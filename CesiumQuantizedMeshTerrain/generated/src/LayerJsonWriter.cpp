// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!

#include "LayerJsonWriter.h"

#include <CesiumJsonWriter/ExtensionWriterContext.h>
#include <CesiumJsonWriter/JsonObjectWriter.h>
#include <CesiumJsonWriter/JsonWriter.h>
#include <CesiumJsonWriter/writeJsonExtensions.h>
#include <CesiumQuantizedMeshTerrain/AvailabilityRectangle.h>
#include <CesiumQuantizedMeshTerrain/Layer.h>
#include <CesiumUtility/IntrusivePointer.h>
#include <CesiumUtility/JsonValue.h>

namespace CesiumQuantizedMeshTerrain {

namespace {

void writeJson(
    const CesiumQuantizedMeshTerrain::Layer& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context);

void writeJson(
    const CesiumQuantizedMeshTerrain::AvailabilityRectangle& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context);

// Forward declaration to avoid circular dependency since some properties
// are vector of unordered_map and others are unordered_map of vector
template <typename T>
[[maybe_unused]] void writeJson(
    const std::vector<T>& list,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context);

template <typename T>
[[maybe_unused]] void writeJson(
    const CesiumUtility::IntrusivePointer<T>& ptr,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  writeJson(*ptr, jsonWriter, context);
}

[[maybe_unused]] void writeJson(
    const std::string& str,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& /* context */) {
  jsonWriter.String(str);
}

[[maybe_unused]] void writeJson(
    double val,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& /* context */) {
  jsonWriter.Double(val);
}

[[maybe_unused]] void writeJson(
    bool val,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& /* context */) {
  jsonWriter.Bool(val);
}

[[maybe_unused]] void writeJson(
    int64_t val,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& /* context */) {
  jsonWriter.Int64(val);
}

[[maybe_unused]] void writeJson(
    int32_t val,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& /* context */) {
  jsonWriter.Int64(val);
}

[[maybe_unused]] void writeJson(
    const CesiumUtility::JsonValue::Object& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& /* context */) {
  jsonWriter.StartObject();
  for (const auto& item : obj) {
    jsonWriter.Key(item.first);
    CesiumJsonWriter::writeJsonValue(item.second, jsonWriter);
  }
  jsonWriter.EndObject();
}

[[maybe_unused]] void writeJson(
    const CesiumUtility::JsonValue& value,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& /* context */) {
  CesiumJsonWriter::writeJsonValue(value, jsonWriter);
}

template <typename T>
[[maybe_unused]] void writeJson(
    const std::unordered_map<std::string, T>& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  jsonWriter.StartObject();
  for (const auto& item : obj) {
    jsonWriter.Key(item.first);
    writeJson(item.second, jsonWriter, context);
  }
  jsonWriter.EndObject();
}

template <typename T>
[[maybe_unused]] void writeJson(
    const std::vector<T>& list,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  jsonWriter.StartArray();
  for (const T& item : list) {
    writeJson(item, jsonWriter, context);
  }
  jsonWriter.EndArray();
}

template <typename T>
[[maybe_unused]] void writeJson(
    const std::optional<T>& val,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  if (val.has_value()) {
    writeJson(*val, jsonWriter, context);
  } else {
    jsonWriter.Null();
  }
}

template <typename T>
void writeExtensibleObject(
    const T& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {

  if (hasRegisteredExtensions(obj, jsonWriter, context)) {
    jsonWriter.Key("extensions");
    writeJsonExtensions(obj, jsonWriter, context);
  }

  if (!obj.extras.empty()) {
    jsonWriter.Key("extras");
    writeJson(obj.extras, jsonWriter, context);
  }
}

template <typename T>
void writeSharedAsset(
    const T& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  writeExtensibleObject(obj, jsonWriter, context);
}

template <typename T>
void writeNamedObject(
    const T& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {

  if (!obj.name.empty()) {
    jsonWriter.Key("name");
    writeJson(obj.name, jsonWriter, context);
  }

  writeExtensibleObject(obj, jsonWriter, context);
}

void writeJson(
    const CesiumQuantizedMeshTerrain::Layer& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  jsonWriter.StartObject();

  if (obj.attribution != "") {
    jsonWriter.Key("attribution");
    writeJson(obj.attribution, jsonWriter, context);
  }

  if (!obj.available.empty()) {
    jsonWriter.Key("available");
    writeJson(obj.available, jsonWriter, context);
  }

  static const std::vector<double> boundsDefault = {-180, -90, 180, 90};
  if (obj.bounds != boundsDefault) {
    jsonWriter.Key("bounds");
    writeJson(obj.bounds, jsonWriter, context);
  }

  if (obj.description != "") {
    jsonWriter.Key("description");
    writeJson(obj.description, jsonWriter, context);
  }

  if (!obj.extensionsProperty.empty()) {
    jsonWriter.Key("extensions");
    writeJson(obj.extensionsProperty, jsonWriter, context);
  }

  if (obj.format != "quantized-mesh-1.0") {
    jsonWriter.Key("format");
    writeJson(obj.format, jsonWriter, context);
  }

  jsonWriter.Key("maxzoom");
  writeJson(obj.maxzoom, jsonWriter, context);

  if (obj.minzoom != 0) {
    jsonWriter.Key("minzoom");
    writeJson(obj.minzoom, jsonWriter, context);
  }

  if (obj.metadataAvailability.has_value()) {
    jsonWriter.Key("metadataAvailability");
    writeJson(obj.metadataAvailability, jsonWriter, context);
  }

  if (obj.name != "Terrain") {
    jsonWriter.Key("name");
    writeJson(obj.name, jsonWriter, context);
  }

  if (obj.parentUrl.has_value()) {
    jsonWriter.Key("parentUrl");
    writeJson(obj.parentUrl, jsonWriter, context);
  }

  if (obj.projection != "EPSG:4326") {
    jsonWriter.Key("projection");
    writeJson(obj.projection, jsonWriter, context);
  }

  if (obj.scheme != "tms") {
    jsonWriter.Key("scheme");
    writeJson(obj.scheme, jsonWriter, context);
  }

  if (!obj.tiles.empty()) {
    jsonWriter.Key("tiles");
    writeJson(obj.tiles, jsonWriter, context);
  }

  if (obj.version != "1.0.0") {
    jsonWriter.Key("version");
    writeJson(obj.version, jsonWriter, context);
  }

  writeExtensibleObject(obj, jsonWriter, context);

  jsonWriter.EndObject();
}

void writeJson(
    const CesiumQuantizedMeshTerrain::AvailabilityRectangle& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  jsonWriter.StartObject();

  jsonWriter.Key("startX");
  writeJson(obj.startX, jsonWriter, context);

  jsonWriter.Key("startY");
  writeJson(obj.startY, jsonWriter, context);

  jsonWriter.Key("endX");
  writeJson(obj.endX, jsonWriter, context);

  jsonWriter.Key("endY");
  writeJson(obj.endY, jsonWriter, context);

  writeExtensibleObject(obj, jsonWriter, context);

  jsonWriter.EndObject();
}

} // namespace

void LayerJsonWriter::write(
    const CesiumQuantizedMeshTerrain::Layer& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  writeJson(obj, jsonWriter, context);
}

void AvailabilityRectangleJsonWriter::write(
    const CesiumQuantizedMeshTerrain::AvailabilityRectangle& obj,
    CesiumJsonWriter::JsonWriter& jsonWriter,
    const CesiumJsonWriter::ExtensionWriterContext& context) {
  writeJson(obj, jsonWriter, context);
}

} // namespace CesiumQuantizedMeshTerrain
