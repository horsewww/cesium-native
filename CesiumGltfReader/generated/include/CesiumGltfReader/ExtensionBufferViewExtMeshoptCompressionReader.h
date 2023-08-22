// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include <CesiumGltf/ExtensionBufferViewExtMeshoptCompression.h>
#include <CesiumGltfReader/Library.h>
#include <CesiumJsonReader/JsonReader.h>
#include <CesiumJsonReader/JsonReaderOptions.h>

#include <gsl/span>
#include <rapidjson/fwd.h>

#include <vector>

namespace CesiumGltf {
struct ExtensionBufferViewExtMeshoptCompression;
}

namespace CesiumGltfReader {

class CESIUMGLTFREADER_API ExtensionBufferViewExtMeshoptCompressionReader {
public:
  /**
   * @brief Constructs a new instance.
   */
  ExtensionBufferViewExtMeshoptCompressionReader();

  /**
   * @brief Gets the options controlling how the JSON is read.
   */
  CesiumJsonReader::JsonReaderOptions& getOptions();

  /**
   * @brief Gets the options controlling how the JSON is read.
   */
  const CesiumJsonReader::JsonReaderOptions& getOptions() const;

  /**
   * @brief Reads an instance of ExtensionBufferViewExtMeshoptCompression from a
   * byte buffer.
   *
   * @param data The buffer from which to read the instance.
   * @return The result of reading the instance.
   */
  CesiumJsonReader::ReadJsonResult<
      CesiumGltf::ExtensionBufferViewExtMeshoptCompression>
  readFromJson(const gsl::span<const std::byte>& data) const;

  /**
   * @brief Reads an instance of ExtensionBufferViewExtMeshoptCompression from a
   * rapidJson::Value.
   *
   * @param data The buffer from which to read the instance.
   * @return The result of reading the instance.
   */
  CesiumJsonReader::ReadJsonResult<
      CesiumGltf::ExtensionBufferViewExtMeshoptCompression>
  readFromJson(const rapidjson::Value& value) const;

  /**
   * @brief Reads an array of instances of
   * ExtensionBufferViewExtMeshoptCompression from a rapidJson::Value.
   *
   * @param data The buffer from which to read the array of instances.
   * @return The result of reading the array of instances.
   */
  CesiumJsonReader::ReadJsonResult<
      std::vector<CesiumGltf::ExtensionBufferViewExtMeshoptCompression>>
  readArrayFromJson(const rapidjson::Value& value) const;

private:
  CesiumJsonReader::JsonReaderOptions _options;
};

} // namespace CesiumGltfReader