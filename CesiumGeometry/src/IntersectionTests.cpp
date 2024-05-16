#include "CesiumGeometry/IntersectionTests.h"

#include "CesiumGeometry/AxisAlignedBox.h"
#include "CesiumGeometry/BoundingSphere.h"
#include "CesiumGeometry/OrientedBoundingBox.h"
#include "CesiumGeometry/Plane.h"
#include "CesiumGeometry/Ray.h"

#include <CesiumUtility/Math.h>

#include <glm/ext/matrix_transform.hpp>
#include <glm/geometric.hpp>
#include <glm/gtx/norm.hpp>

#include <limits>

using namespace CesiumUtility;

namespace CesiumGeometry {

/*static*/ std::optional<glm::dvec3>
IntersectionTests::rayPlane(const Ray& ray, const Plane& plane) noexcept {
  const double denominator = glm::dot(plane.getNormal(), ray.getDirection());

  if (glm::abs(denominator) < Math::Epsilon15) {
    // Ray is parallel to plane.  The ray may be in the polygon's plane.
    return std::optional<glm::dvec3>();
  }

  const double t =
      (-plane.getDistance() - glm::dot(plane.getNormal(), ray.getOrigin())) /
      denominator;

  if (t < 0) {
    return std::optional<glm::dvec3>();
  }

  return ray.getOrigin() + ray.getDirection() * t;
}

std::optional<glm::dvec3> IntersectionTests::rayTriangle(
    const Ray& ray,
    const glm::dvec3& v0,
    const glm::dvec3& v1,
    const glm::dvec3& v2,
    bool cullBackFaces) {
  double t;
  return rayTriangleParametric(ray, v0, v1, v2, t, cullBackFaces) && t >= 0
             ? std::make_optional<glm::dvec3>(ray.pointFromDistance(t))
             : std::nullopt;
}

bool IntersectionTests::rayTriangleParametric(
    const Ray& ray,
    const glm::dvec3& p0,
    const glm::dvec3& p1,
    const glm::dvec3& p2,
    double& t,
    bool cullBackFaces) {

  const glm::dvec3& origin = ray.getOrigin();
  const glm::dvec3& direction = ray.getDirection();

  glm::dvec3 edge0 = p1 - p0;
  glm::dvec3 edge1 = p2 - p0;

  glm::dvec3 p = glm::cross(direction, edge1);
  double det = glm::dot(edge0, p);
  if (cullBackFaces) {
    if (det < Math::Epsilon6)
      return false;

    glm::dvec3 tvec = origin - p0;
    double u = glm::dot(tvec, p);
    if (u < 0.0 || u > det)
      return false;

    glm::dvec3 q = glm::cross(tvec, edge0);
    double v = glm::dot(direction, q);
    if (v < 0.0 || u + v > det)
      return false;

    t = glm::dot(edge1, q) / det;
    return true;

  } else {

    if (glm::abs(det) < Math::Epsilon6)
      return false;

    double invDet = 1.0 / det;

    glm::dvec3 tvec = origin - p0;
    double u = glm::dot(tvec, p) * invDet;
    if (u < 0.0 || u > 1.0)
      return false;

    glm::dvec3 q = glm::cross(tvec, edge0);
    double v = glm::dot(direction, q) * invDet;
    if (v < 0.0 || u + v > 1.0)
      return false;

    t = glm::dot(edge1, q) * invDet;
    return true;
  }
}

std::optional<glm::dvec3>
IntersectionTests::rayAABB(const Ray& ray, const AxisAlignedBox& aabb) {
  double t;
  return rayAABBParametric(ray, aabb, t) && t >= 0
             ? std::make_optional<glm::dvec3>(ray.pointFromDistance(t))
             : std::nullopt;
}

bool IntersectionTests::rayAABBParametric(
    const Ray& ray,
    const AxisAlignedBox& aabb,
    double& t) {
  const glm::dvec3& dir = ray.getDirection();
  const glm::dvec3& origin = ray.getOrigin();
  const glm::dvec3* min = reinterpret_cast<const glm::dvec3*>(&aabb.minimumX);
  const glm::dvec3* max = reinterpret_cast<const glm::dvec3*>(&aabb.maximumX);
  double greatestMin = -std::numeric_limits<double>::max();
  double smallestMax = std::numeric_limits<double>::max();
  double tmin = greatestMin;
  double tmax = smallestMax;

  for (uint32_t i = 0; i < 3; ++i) {
    if (glm::abs(dir[i]) < Math::Epsilon6) {
      continue;
    } else {
      tmin = ((*min)[i] - origin[i]) / dir[i];
      tmax = ((*max)[i] - origin[i]) / dir[i];
    }
    if (tmin > tmax) {
      std::swap(tmin, tmax);
    }
    greatestMin = glm::max(tmin, greatestMin);
    smallestMax = glm::min(tmax, smallestMax);
  }
  if (smallestMax < 0.0 || greatestMin > smallestMax) {
    return false;
  }
  t = greatestMin < 0.0 ? smallestMax : greatestMin;
  return true;
}

std::optional<glm::dvec3>
IntersectionTests::rayOBB(const Ray& ray, const OrientedBoundingBox& obb) {
  double t;
  return rayOBBParametric(ray, obb, t) && t >= 0
             ? std::make_optional<glm::dvec3>(ray.pointFromDistance(t))
             : std::nullopt;
}

bool IntersectionTests::rayOBBParametric(
    const Ray& ray,
    const OrientedBoundingBox& obb,
    double& t) {

  const glm::dmat3x3& inverseHalfAxis = obb.getInverseHalfAxes();
  glm::dmat4x4 transformation(
      glm::normalize(glm::dvec4(inverseHalfAxis[0], 0.0)),
      glm::normalize(glm::dvec4(inverseHalfAxis[1], 0.0)),
      glm::normalize(glm::dvec4(inverseHalfAxis[2], 0.0)),
      glm::dvec4(0.0, 0.0, 0.0, 1.0));

  glm::dvec3 center =
      glm::dvec3(transformation * glm::dvec4(obb.getCenter(), 1.0));
  glm::dvec3 halfLengths = obb.getLengths() / 2.0;
  glm::dvec3 ll = center - halfLengths;
  glm::dvec3 ur = center + halfLengths;

  return rayAABBParametric(
      ray.transform(transformation),
      AxisAlignedBox(ll.x, ll.y, ll.z, ur.x, ur.y, ur.z),
      t);
}

std::optional<glm::dvec3>
IntersectionTests::raySphere(const Ray& ray, const BoundingSphere& sphere) {
  double t;
  return raySphereParametric(ray, sphere, t) && t >= 0
             ? std::make_optional<glm::dvec3>(ray.pointFromDistance(t))
             : std::nullopt;
}

namespace {
bool solveQuadratic(
    double a,
    double b,
    double c,
    double& root0,
    double& root1) {
  double det = b * b - 4.0 * a * c;
  if (det < 0.0) {
    return false;
  } else if (det > 0.0) {
    double denom = 1.0 / (2.0 * a);
    double disc = glm::sqrt(det);
    root0 = (-b + disc) * denom;
    root1 = (-b - disc) * denom;

    if (root1 < root0) {
      std::swap(root1, root0);
    }
    return true;
  }

  double root = -b / (2.0 * a);
  if (root == 0.0) {
    return false;
  }

  root0 = root1 = root;
  return true;
}
} // namespace

bool IntersectionTests::raySphereParametric(
    const Ray& ray,
    const BoundingSphere& sphere,
    double& t) {
  const glm::dvec3& origin = ray.getOrigin();
  const glm::dvec3& direction = ray.getDirection();

  const glm::dvec3& center = sphere.getCenter();
  const double radiusSquared = sphere.getRadius() * sphere.getRadius();

  const glm::dvec3 diff = origin - center;

  const double b = 2.0 * glm::dot(direction, diff);
  const double c = glm::dot(diff, diff) - radiusSquared;

  double t0, t1;
  if (solveQuadratic(1.0, b, c, t0, t1)) {
    t = t0 < 0 ? t1 : t0;
    return true;
  }
  return false;
}

bool IntersectionTests::pointInTriangle(
    const glm::dvec2& point,
    const glm::dvec2& triangleVertA,
    const glm::dvec2& triangleVertB,
    const glm::dvec2& triangleVertC) noexcept {
  // Define the triangle edges.
  const glm::dvec2 ab = triangleVertB - triangleVertA;
  const glm::dvec2 bc = triangleVertC - triangleVertB;
  const glm::dvec2 ca = triangleVertA - triangleVertC;

  // Return false for degenerate triangles.
  if (glm::length2(ab) < CesiumUtility::Math::Epsilon8 ||
      glm::length2(bc) < CesiumUtility::Math::Epsilon8 ||
      glm::length2(ca) < CesiumUtility::Math::Epsilon8) {
    return false;
  }

  // Get the vector perpendicular to each triangle edge in the same 2D plane).
  const glm::dvec2 ab_perp(-ab.y, ab.x);
  const glm::dvec2 bc_perp(-bc.y, bc.x);
  const glm::dvec2 ca_perp(-ca.y, ca.x);

  // Get vectors from triangle corners to point.
  const glm::dvec2 av = point - triangleVertA;
  const glm::dvec2 cv = point - triangleVertC;

  // Project the point vectors onto the perpendicular vectors.
  const double v_proj_ab_perp = glm::dot(av, ab_perp);
  const double v_proj_bc_perp = glm::dot(cv, bc_perp);
  const double v_proj_ca_perp = glm::dot(cv, ca_perp);

  // The projections determine in what direction the point is from the triangle
  // edge. This will determine in or out, irrespective of winding.
  return (v_proj_ab_perp >= 0.0 && v_proj_ca_perp >= 0.0 &&
          v_proj_bc_perp >= 0.0) ||
         (v_proj_ab_perp <= 0.0 && v_proj_ca_perp <= 0.0 &&
          v_proj_bc_perp <= 0.0);
}

bool IntersectionTests::pointInTriangle(
    const glm::dvec3& point,
    const glm::dvec3& triangleVertA,
    const glm::dvec3& triangleVertB,
    const glm::dvec3& triangleVertC) noexcept {
  // PERFORMANCE_IDEA: Investigate if there is a faster algorithm that can do
  // this test, but without needing to compute barycentric coordinates
  glm::dvec3 unused;
  return IntersectionTests::pointInTriangle(
      point,
      triangleVertA,
      triangleVertB,
      triangleVertC,
      unused);
}

bool IntersectionTests::pointInTriangle(
    const glm::dvec3& point,
    const glm::dvec3& triangleVertA,
    const glm::dvec3& triangleVertB,
    const glm::dvec3& triangleVertC,
    glm::dvec3& barycentricCoordinates) noexcept {
  // PERFORMANCE_IDEA: If optimization is necessary in the future, there are
  // algorithms that avoid length computations (which involve square root
  // operations).

  // Define the triangle edges.
  const glm::dvec3 ab = triangleVertB - triangleVertA;
  const glm::dvec3 bc = triangleVertC - triangleVertB;

  const glm::dvec3 triangleNormal = glm::cross(ab, bc);
  const double lengthSquared = glm::length2(triangleNormal);
  if (lengthSquared < CesiumUtility::Math::Epsilon8) {
    // Don't handle invalid triangles.
    return false;
  }

  // Technically this is the area of the parallelogram between the vectors,
  // but triangles are 1/2 of the area, and the division will cancel out later.
  const double triangleAreaInv = 1.0 / glm::sqrt(lengthSquared);

  const glm::dvec3 ap = point - triangleVertA;
  const double triangleABPRatio =
      glm::length(glm::cross(ab, ap)) * triangleAreaInv;
  if (triangleABPRatio > 1) {
    return false;
  }

  const glm::dvec3 bp = point - triangleVertB;
  const double triangleBCPRatio =
      glm::length(glm::cross(bc, bp)) * triangleAreaInv;
  if (triangleBCPRatio > 1) {
    return false;
  }

  const double triangleCAPRatio = 1.0 - triangleABPRatio - triangleBCPRatio;
  if (triangleCAPRatio < 0) {
    return false;
  }

  barycentricCoordinates.x = triangleBCPRatio;
  barycentricCoordinates.y = triangleCAPRatio;
  barycentricCoordinates.z = triangleABPRatio;

  return true;
}

} // namespace CesiumGeometry
