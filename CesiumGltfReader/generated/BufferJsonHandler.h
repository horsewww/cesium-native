// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "IntegerJsonHandler.h"
#include "NamedObjectJsonHandler.h"
#include "StringJsonHandler.h"

namespace CesiumGltf {
struct Buffer;

class BufferJsonHandler : public NamedObjectJsonHandler {
public:
  void reset(IJsonHandler* pHandler, Buffer* pObject);
  Buffer* getObject();
  virtual void reportWarning(
      const std::string& warning,
      std::vector<std::string>&& context = std::vector<std::string>()) override;

  virtual IJsonHandler* Key(const char* str, size_t length, bool copy) override;

protected:
  IJsonHandler* BufferKey(const char* str, Buffer& o);

private:
  Buffer* _pObject = nullptr;
  StringJsonHandler _uri;
  IntegerJsonHandler<int64_t> _byteLength;
};
} // namespace CesiumGltf
