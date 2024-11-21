// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "Cesium3DTiles/Library.h"

#include <CesiumUtility/ExtensibleObject.h>

#include <cstdint>
#include <optional>
#include <string>

namespace Cesium3DTiles {
/**
 * @brief A contiguous subset of a buffer
 */
struct CESIUM3DTILES_API BufferView final
    : public CesiumUtility::ExtensibleObject {
  static inline constexpr const char* TypeName = "BufferView";

  /**
   * @brief The index of the buffer.
   */
  int64_t buffer = int64_t();

  /**
   * @brief The offset into the buffer in bytes.
   */
  int64_t byteOffset = int64_t();

  /**
   * @brief The total byte length of the buffer view.
   */
  int64_t byteLength = int64_t();

  /**
   * @brief The name of the `bufferView`.
   */
  std::optional<std::string> name;

  /**
   * @brief Calculates the size in bytes of this object, including the contents
   * of all collections, pointers, and strings. This will NOT include the size
   * of any extensions attached to the object. Calling this method may be slow
   * as it requires traversing the object's entire structure.
   */
  int64_t getSizeBytes() const {
    int64_t accum = 0;
    accum += int64_t(sizeof(BufferView));
    accum += CesiumUtility::ExtensibleObject::getSizeBytes() -
             int64_t(sizeof(CesiumUtility::ExtensibleObject));
    if (this->name) {
      accum += int64_t(this->name->capacity() * sizeof(char));
    }
    return accum;
  }
};
} // namespace Cesium3DTiles
