// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "ClassJsonHandler.h"
#include "EnumJsonHandler.h"
#include "SharedAssetJsonHandler.h"

#include <CesiumGltf/Schema.h>
#include <CesiumJsonReader/DictionaryJsonHandler.h>
#include <CesiumJsonReader/StringJsonHandler.h>

namespace CesiumJsonReader {
class JsonReaderOptions;
}

namespace CesiumGltfReader {
class SchemaJsonHandler : public CesiumGltfReader::SharedAssetJsonHandler {
public:
  using ValueType = CesiumGltf::Schema;

  SchemaJsonHandler(
      const CesiumJsonReader::JsonReaderOptions& options) noexcept;
  void reset(IJsonHandler* pParentHandler, CesiumGltf::Schema* pObject);

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeySchema(
      const std::string& objectType,
      const std::string_view& str,
      CesiumGltf::Schema& o);

private:
  CesiumGltf::Schema* _pObject = nullptr;
  CesiumJsonReader::StringJsonHandler _id;
  CesiumJsonReader::StringJsonHandler _name;
  CesiumJsonReader::StringJsonHandler _description;
  CesiumJsonReader::StringJsonHandler _version;
  CesiumJsonReader::DictionaryJsonHandler<CesiumGltf::Class, ClassJsonHandler>
      _classes;
  CesiumJsonReader::DictionaryJsonHandler<CesiumGltf::Enum, EnumJsonHandler>
      _enums;
};
} // namespace CesiumGltfReader
