// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include <CesiumGltf/ExtensionKhrTextureTransform.h>
#include <CesiumJsonReader/ArrayJsonHandler.h>
#include <CesiumJsonReader/DoubleJsonHandler.h>
#include <CesiumJsonReader/ExtensibleObjectJsonHandler.h>
#include <CesiumJsonReader/IntegerJsonHandler.h>

namespace CesiumJsonReader {
class JsonReaderOptions;
}

namespace CesiumGltfReader {
class ExtensionKhrTextureTransformJsonHandler
    : public CesiumJsonReader::ExtensibleObjectJsonHandler,
      public CesiumJsonReader::IExtensionJsonHandler {
public:
  using ValueType = CesiumGltf::ExtensionKhrTextureTransform;

  static inline constexpr const char* ExtensionName = "KHR_texture_transform";

  ExtensionKhrTextureTransformJsonHandler(
      const CesiumJsonReader::JsonReaderOptions& options) noexcept;
  void reset(
      IJsonHandler* pParentHandler,
      CesiumGltf::ExtensionKhrTextureTransform* pObject);

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

  virtual void reset(
      IJsonHandler* pParentHandler,
      CesiumUtility::ExtensibleObject& o,
      const std::string_view& extensionName) override;

  virtual IJsonHandler& getHandler() override { return *this; }

protected:
  IJsonHandler* readObjectKeyExtensionKhrTextureTransform(
      const std::string& objectType,
      const std::string_view& str,
      CesiumGltf::ExtensionKhrTextureTransform& o);

private:
  CesiumGltf::ExtensionKhrTextureTransform* _pObject = nullptr;
  CesiumJsonReader::
      ArrayJsonHandler<double, CesiumJsonReader::DoubleJsonHandler>
          _offset;
  CesiumJsonReader::DoubleJsonHandler _rotation;
  CesiumJsonReader::
      ArrayJsonHandler<double, CesiumJsonReader::DoubleJsonHandler>
          _scale;
  CesiumJsonReader::IntegerJsonHandler<int64_t> _texCoord;
};
} // namespace CesiumGltfReader
