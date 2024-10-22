// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "CesiumGltf/Library.h"
#include "CesiumGltf/MaterialNormalTextureInfo.h"
#include "CesiumGltf/MaterialOcclusionTextureInfo.h"
#include "CesiumGltf/MaterialPBRMetallicRoughness.h"
#include "CesiumGltf/NamedObject.h"
#include "CesiumGltf/TextureInfo.h"

#include <optional>
#include <string>
#include <vector>

namespace CesiumGltf {
/**
 * @brief The material appearance of a primitive.
 */
struct CESIUMGLTF_API Material final : public CesiumGltf::NamedObject {
  static inline constexpr const char* TypeName = "Material";

  /**
   * @brief Known values for The alpha rendering mode of the material.
   */
  struct AlphaMode {
    inline static const std::string OPAQUE = "OPAQUE";

    inline static const std::string MASK = "MASK";

    inline static const std::string BLEND = "BLEND";
  };

  /**
   * @brief A set of parameter values that are used to define the
   * metallic-roughness material model from Physically Based Rendering (PBR)
   * methodology. When undefined, all the default values of
   * `pbrMetallicRoughness` **MUST** apply.
   */
  std::optional<CesiumGltf::MaterialPBRMetallicRoughness> pbrMetallicRoughness;

  /**
   * @brief The tangent space normal texture.
   *
   * The texture encodes RGB components with linear transfer function. Each
   * texel represents the XYZ components of a normal vector in tangent space.
   * The normal vectors use the convention +X is right and +Y is up. +Z points
   * toward the viewer. If a fourth component (A) is present, it **MUST** be
   * ignored. When undefined, the material does not have a tangent space normal
   * texture.
   */
  std::optional<CesiumGltf::MaterialNormalTextureInfo> normalTexture;

  /**
   * @brief The occlusion texture.
   *
   * The occlusion values are linearly sampled from the R channel. Higher values
   * indicate areas that receive full indirect lighting and lower values
   * indicate no indirect lighting. If other channels are present (GBA), they
   * **MUST** be ignored for occlusion calculations. When undefined, the
   * material does not have an occlusion texture.
   */
  std::optional<CesiumGltf::MaterialOcclusionTextureInfo> occlusionTexture;

  /**
   * @brief The emissive texture.
   *
   * It controls the color and intensity of the light being emitted by the
   * material. This texture contains RGB components encoded with the sRGB
   * transfer function. If a fourth component (A) is present, it **MUST** be
   * ignored. When undefined, the texture **MUST** be sampled as having `1.0` in
   * RGB components.
   */
  std::optional<CesiumGltf::TextureInfo> emissiveTexture;

  /**
   * @brief The factors for the emissive color of the material.
   *
   * This value defines linear multipliers for the sampled texels of the
   * emissive texture.
   */
  std::vector<double> emissiveFactor = {0, 0, 0};

  /**
   * @brief The alpha rendering mode of the material.
   *
   * Known values are defined in {@link AlphaMode}.
   *
   *
   * The material's alpha rendering mode enumeration specifying the
   * interpretation of the alpha value of the base color.
   */
  std::string alphaMode = AlphaMode::OPAQUE;

  /**
   * @brief The alpha cutoff value of the material.
   *
   * Specifies the cutoff threshold when in `MASK` alpha mode. If the alpha
   * value is greater than or equal to this value then it is rendered as fully
   * opaque, otherwise, it is rendered as fully transparent. A value greater
   * than `1.0` will render the entire material as fully transparent. This value
   * **MUST** be ignored for other alpha modes. When `alphaMode` is not defined,
   * this value **MUST NOT** be defined.
   */
  double alphaCutoff = 0.5;

  /**
   * @brief Specifies whether the material is double sided.
   *
   * When this value is false, back-face culling is enabled. When this value is
   * true, back-face culling is disabled and double-sided lighting is enabled.
   * The back-face **MUST** have its normals reversed before the lighting
   * equation is evaluated.
   */
  bool doubleSided = false;

  int64_t getSizeBytes() const {
    int64_t accum = 0;
    accum += sizeof(this->pbrMetallicRoughness) +
             (this->pbrMetallicRoughness.has_value()
                  ? this->pbrMetallicRoughness->getSizeBytes()
                  : 0);
    accum +=
        sizeof(this->normalTexture) + (this->normalTexture.has_value()
                                           ? this->normalTexture->getSizeBytes()
                                           : 0);
    accum += sizeof(this->occlusionTexture) +
             (this->occlusionTexture.has_value()
                  ? this->occlusionTexture->getSizeBytes()
                  : 0);
    accum += sizeof(this->emissiveTexture) +
             (this->emissiveTexture.has_value()
                  ? this->emissiveTexture->getSizeBytes()
                  : 0);
    for (const double& value : this->emissiveFactor) {
      accum += sizeof(value);
    }
    accum += sizeof(this->alphaMode);
    accum += sizeof(this->alphaCutoff);
    accum += sizeof(this->doubleSided);
    return accum;
  }
};
} // namespace CesiumGltf
