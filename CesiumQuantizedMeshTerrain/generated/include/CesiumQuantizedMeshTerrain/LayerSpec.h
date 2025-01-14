// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include <CesiumQuantizedMeshTerrain/AvailabilityRectangle.h>
#include <CesiumQuantizedMeshTerrain/Library.h>
#include <CesiumUtility/ExtensibleObject.h>

#include <cstdint>
#include <optional>
#include <string>
#include <vector>

namespace CesiumQuantizedMeshTerrain {
/**
 * @brief A quantized-mesh terrain layer.json.
 */
struct CESIUMQUANTIZEDMESHTERRAIN_API LayerSpec
    : public CesiumUtility::ExtensibleObject {
  /**
   * @brief The original name of this type.
   */
  static constexpr const char* TypeName = "Layer";

  /**
   * @brief The attribution (credit) string for the terrain.
   */
  std::string attribution;

  /**
   * @brief The tile availability information. The outer array is indexed by
   * tile level. The inner array is a list of rectangles of availability at that
   * level. Tiles themselves may also contain further availability information
   * for their subtree.
   */
  std::vector<std::vector<CesiumQuantizedMeshTerrain::AvailabilityRectangle>>
      available;

  /**
   * @brief The bounding box of the terrain, expressed as west, south, east,
   * north in degrees.
   */
  std::vector<double> bounds = {-180, -90, 180, 90};

  /**
   * @brief The description of this terrain tileset.
   */
  std::string description;

  /**
   * @brief The extensions available for this tileset.
   */
  std::vector<std::string> extensionsProperty;

  /**
   * @brief The format of the terrain tiles. Should be `"quantized-mesh-1.0"`.
   */
  std::string format = "quantized-mesh-1.0";

  /**
   * @brief The maximum level for which there are any available tiles.
   */
  int64_t maxzoom = int64_t();

  /**
   * @brief The minimum level for which there are any available tiles.
   */
  int64_t minzoom = 0;

  /**
   * @brief The levels at metadata is found in tiles. For example, if this value
   * is 10, then metadata is found at levels 0, 10, 20, etc.
   */
  std::optional<int64_t> metadataAvailability;

  /**
   * @brief The name of this terrain tileset.
   */
  std::string name = "Terrain";

  /**
   * @brief The URL of the parent layer.json that this one is layered on top of.
   */
  std::optional<std::string> parentUrl;

  /**
   * @brief The map projection of this tileset. Valid values are `"EPSG:4326"`
   * and `"EPSG:3857"`.
   */
  std::string projection = "EPSG:4326";

  /**
   * @brief The tiling scheme. The only valid value is `"tms"`.
   */
  std::string scheme = "tms";

  /**
   * @brief The URL templates from which to obtain tiles.
   */
  std::vector<std::string> tiles;

  /**
   * @brief The version of this tileset.
   */
  std::string version = "1.0.0";

  /**
   * @brief Calculates the size in bytes of this object, including the contents
   * of all collections, pointers, and strings. This will NOT include the size
   * of any extensions attached to the object. Calling this method may be slow
   * as it requires traversing the object's entire structure.
   */
  int64_t getSizeBytes() const {
    int64_t accum = 0;
    accum += int64_t(sizeof(LayerSpec));
    accum += CesiumUtility::ExtensibleObject::getSizeBytes() -
             int64_t(sizeof(CesiumUtility::ExtensibleObject));
    accum += int64_t(this->attribution.capacity() * sizeof(char));
    accum += int64_t(
        sizeof(std::vector<CesiumQuantizedMeshTerrain::AvailabilityRectangle>) *
        this->available.capacity());
    for (const std::vector<CesiumQuantizedMeshTerrain::AvailabilityRectangle>&
             valueOuter : this->available) {
      accum += int64_t(
          sizeof(CesiumQuantizedMeshTerrain::AvailabilityRectangle) *
          valueOuter.capacity());
      for (const CesiumQuantizedMeshTerrain::AvailabilityRectangle& value :
           valueOuter) {
        accum +=
            value.getSizeBytes() -
            int64_t(sizeof(CesiumQuantizedMeshTerrain::AvailabilityRectangle));
      }
    }
    accum += int64_t(sizeof(double) * this->bounds.capacity());
    accum += int64_t(this->description.capacity() * sizeof(char));
    accum += int64_t(sizeof(std::string) * this->extensionsProperty.capacity());
    accum += int64_t(this->format.capacity() * sizeof(char));
    accum += int64_t(this->name.capacity() * sizeof(char));
    if (this->parentUrl) {
      accum += int64_t(this->parentUrl->capacity() * sizeof(char));
    }
    accum += int64_t(this->projection.capacity() * sizeof(char));
    accum += int64_t(this->scheme.capacity() * sizeof(char));
    accum += int64_t(sizeof(std::string) * this->tiles.capacity());
    accum += int64_t(this->version.capacity() * sizeof(char));
    return accum;
  }

protected:
  /**
   * @brief This class is not meant to be instantiated directly. Use {@link Layer} instead.
   */
  LayerSpec() = default;
  friend struct Layer;
};
} // namespace CesiumQuantizedMeshTerrain
