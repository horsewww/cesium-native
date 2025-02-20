// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

// forward declarations
namespace CesiumJsonWriter {
class JsonWriter;
class ExtensionWriterContext;
} // namespace CesiumJsonWriter

// forward declarations
namespace Cesium3DTiles {
struct Extension3dTilesBoundingVolumeS2;
struct Extension3dTilesEllipsoid;
struct ExtensionContent3dTilesContentVoxels;
struct Padding;
struct Statistics;
struct ClassStatistics;
struct PropertyStatistics;
struct Schema;
struct Enum;
struct EnumValue;
struct Class;
struct ClassProperty;
struct Subtree;
struct MetadataEntity;
struct Availability;
struct PropertyTable;
struct PropertyTableProperty;
struct BufferView;
struct Buffer;
struct Tileset;
struct Tile;
struct ImplicitTiling;
struct Subtrees;
struct Content;
struct BoundingVolume;
struct GroupMetadata;
struct Properties;
struct Asset;
} // namespace Cesium3DTiles

namespace Cesium3DTilesWriter {

struct Extension3dTilesBoundingVolumeS2JsonWriter {
  using ValueType = Cesium3DTiles::Extension3dTilesBoundingVolumeS2;

  /** @brief The official name of the extension. This should be the same as its
   * key in the `extensions` object. */
  static constexpr const char* ExtensionName = "3DTILES_bounding_volume_S2";

  static void write(
      const Cesium3DTiles::Extension3dTilesBoundingVolumeS2& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct Extension3dTilesEllipsoidJsonWriter {
  using ValueType = Cesium3DTiles::Extension3dTilesEllipsoid;

  /** @brief The official name of the extension. This should be the same as its
   * key in the `extensions` object. */
  static constexpr const char* ExtensionName = "3DTILES_ellipsoid";

  static void write(
      const Cesium3DTiles::Extension3dTilesEllipsoid& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ExtensionContent3dTilesContentVoxelsJsonWriter {
  using ValueType = Cesium3DTiles::ExtensionContent3dTilesContentVoxels;

  /** @brief The official name of the extension. This should be the same as its
   * key in the `extensions` object. */
  static constexpr const char* ExtensionName = "3DTILES_content_voxels";

  static void write(
      const Cesium3DTiles::ExtensionContent3dTilesContentVoxels& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct PaddingJsonWriter {
  using ValueType = Cesium3DTiles::Padding;

  static void write(
      const Cesium3DTiles::Padding& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct StatisticsJsonWriter {
  using ValueType = Cesium3DTiles::Statistics;

  static void write(
      const Cesium3DTiles::Statistics& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ClassStatisticsJsonWriter {
  using ValueType = Cesium3DTiles::ClassStatistics;

  static void write(
      const Cesium3DTiles::ClassStatistics& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct PropertyStatisticsJsonWriter {
  using ValueType = Cesium3DTiles::PropertyStatistics;

  static void write(
      const Cesium3DTiles::PropertyStatistics& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct SchemaJsonWriter {
  using ValueType = Cesium3DTiles::Schema;

  static void write(
      const Cesium3DTiles::Schema& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct EnumJsonWriter {
  using ValueType = Cesium3DTiles::Enum;

  static void write(
      const Cesium3DTiles::Enum& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct EnumValueJsonWriter {
  using ValueType = Cesium3DTiles::EnumValue;

  static void write(
      const Cesium3DTiles::EnumValue& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ClassJsonWriter {
  using ValueType = Cesium3DTiles::Class;

  static void write(
      const Cesium3DTiles::Class& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ClassPropertyJsonWriter {
  using ValueType = Cesium3DTiles::ClassProperty;

  static void write(
      const Cesium3DTiles::ClassProperty& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct SubtreeJsonWriter {
  using ValueType = Cesium3DTiles::Subtree;

  static void write(
      const Cesium3DTiles::Subtree& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct MetadataEntityJsonWriter {
  using ValueType = Cesium3DTiles::MetadataEntity;

  static void write(
      const Cesium3DTiles::MetadataEntity& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct AvailabilityJsonWriter {
  using ValueType = Cesium3DTiles::Availability;

  static void write(
      const Cesium3DTiles::Availability& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct PropertyTableJsonWriter {
  using ValueType = Cesium3DTiles::PropertyTable;

  static void write(
      const Cesium3DTiles::PropertyTable& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct PropertyTablePropertyJsonWriter {
  using ValueType = Cesium3DTiles::PropertyTableProperty;

  static void write(
      const Cesium3DTiles::PropertyTableProperty& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct BufferViewJsonWriter {
  using ValueType = Cesium3DTiles::BufferView;

  static void write(
      const Cesium3DTiles::BufferView& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct BufferJsonWriter {
  using ValueType = Cesium3DTiles::Buffer;

  static void write(
      const Cesium3DTiles::Buffer& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct TilesetJsonWriter {
  using ValueType = Cesium3DTiles::Tileset;

  static void write(
      const Cesium3DTiles::Tileset& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct TileJsonWriter {
  using ValueType = Cesium3DTiles::Tile;

  static void write(
      const Cesium3DTiles::Tile& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ImplicitTilingJsonWriter {
  using ValueType = Cesium3DTiles::ImplicitTiling;

  static void write(
      const Cesium3DTiles::ImplicitTiling& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct SubtreesJsonWriter {
  using ValueType = Cesium3DTiles::Subtrees;

  static void write(
      const Cesium3DTiles::Subtrees& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct ContentJsonWriter {
  using ValueType = Cesium3DTiles::Content;

  static void write(
      const Cesium3DTiles::Content& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct BoundingVolumeJsonWriter {
  using ValueType = Cesium3DTiles::BoundingVolume;

  static void write(
      const Cesium3DTiles::BoundingVolume& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct GroupMetadataJsonWriter {
  using ValueType = Cesium3DTiles::GroupMetadata;

  static void write(
      const Cesium3DTiles::GroupMetadata& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct PropertiesJsonWriter {
  using ValueType = Cesium3DTiles::Properties;

  static void write(
      const Cesium3DTiles::Properties& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

struct AssetJsonWriter {
  using ValueType = Cesium3DTiles::Asset;

  static void write(
      const Cesium3DTiles::Asset& obj,
      CesiumJsonWriter::JsonWriter& jsonWriter,
      const CesiumJsonWriter::ExtensionWriterContext& context);
};

} // namespace Cesium3DTilesWriter
