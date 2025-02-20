// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include <CesiumGltf/Padding.h>
#include <CesiumJsonReader/ArrayJsonHandler.h>
#include <CesiumJsonReader/ExtensibleObjectJsonHandler.h>
#include <CesiumJsonReader/IntegerJsonHandler.h>

namespace CesiumJsonReader {
class JsonReaderOptions;
} // namespace CesiumJsonReader

namespace CesiumGltfReader {
class PaddingJsonHandler
    : public CesiumJsonReader::ExtensibleObjectJsonHandler {
public:
  using ValueType = CesiumGltf::Padding;

  explicit PaddingJsonHandler(
      const CesiumJsonReader::JsonReaderOptions& options) noexcept;
  void reset(IJsonHandler* pParentHandler, CesiumGltf::Padding* pObject);

  IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeyPadding(
      const std::string& objectType,
      const std::string_view& str,
      CesiumGltf::Padding& o);

private:
  CesiumGltf::Padding* _pObject = nullptr;
  CesiumJsonReader::
      ArrayJsonHandler<int64_t, CesiumJsonReader::IntegerJsonHandler<int64_t>>
          _before;
  CesiumJsonReader::
      ArrayJsonHandler<int64_t, CesiumJsonReader::IntegerJsonHandler<int64_t>>
          _after;
};
} // namespace CesiumGltfReader
