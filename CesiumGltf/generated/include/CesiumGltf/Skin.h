// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "CesiumGltf/Library.h"
#include "CesiumGltf/NamedObject.h"

#include <cstdint>
#include <vector>

namespace CesiumGltf {
/**
 * @brief Joints and matrices defining a skin.
 */
struct CESIUMGLTF_API Skin final : public CesiumGltf::NamedObject {
  static inline constexpr const char* TypeName = "Skin";

  /**
   * @brief The index of the accessor containing the floating-point 4x4
   * inverse-bind matrices.
   *
   * Its `accessor.count` property **MUST** be greater than or equal to the
   * number of elements of the `joints` array. When undefined, each matrix is a
   * 4x4 identity matrix.
   */
  int32_t inverseBindMatrices = -1;

  /**
   * @brief The index of the node used as a skeleton root.
   *
   * The node **MUST** be the closest common root of the joints hierarchy or a
   * direct or indirect parent node of the closest common root.
   */
  int32_t skeleton = -1;

  /**
   * @brief Indices of skeleton nodes, used as joints in this skin.
   */
  std::vector<int32_t> joints;

  /**
   * @brief Calculates the size in bytes of this object, including the contents
   * of all collections, pointers, and strings. This will NOT include the size
   * of any extensions attached to the object. Calling this method may be slow
   * as it requires traversing the object's entire structure.
   */
  int64_t getSizeBytes() const {
    int64_t accum = 0;
    accum += int64_t(sizeof(Skin));
    accum += CesiumGltf::NamedObject::getSizeBytes() -
             int64_t(sizeof(CesiumGltf::NamedObject));
    accum += int64_t(sizeof(int32_t) * this->joints.capacity());
    return accum;
  }
};
} // namespace CesiumGltf
