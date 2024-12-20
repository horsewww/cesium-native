#include "CesiumUtility/Gzip.h"

#include <CesiumNativeTests/readFile.h>

#include <catch2/catch_test_macros.hpp>

#include <cstddef>
#include <filesystem>
#include <vector>

using namespace CesiumUtility;

namespace {
std::filesystem::path testDataDir = CesiumUtility_TEST_DATA_DIR;
std::filesystem::path compressedDataPath =
    testDataDir / "Gzip" / "CesiumMilkTruck.png.gz";
std::filesystem::path uncompressedDataPath =
    testDataDir / "Gzip" / "CesiumMilkTruck.png";
std::filesystem::path invalidCompressedDataPath =
    testDataDir / "Gzip" / "CesiumMilkTruck.png.gz.invalid";

} // namespace

TEST_CASE("isGzip") {
  SECTION("returns true if data is gzipped") {
    std::vector<std::byte> compressedData = readFile(compressedDataPath);
    CHECK(isGzip(compressedData));
  }

  SECTION("returns false if data is not gzipped") {
    std::vector<std::byte> uncompressedData = readFile(uncompressedDataPath);
    CHECK(!isGzip(uncompressedData));
  }
}

TEST_CASE("gzip") {
  SECTION("gzips data") {
    std::vector<std::byte> uncompressedData = readFile(uncompressedDataPath);
    std::vector<std::byte> compressedData;
    bool result = gzip(uncompressedData, compressedData);
    REQUIRE(result);
    CHECK(compressedData.size() < uncompressedData.size());
    CHECK(isGzip(compressedData));

    std::vector<std::byte> decompressedData;
    result = gunzip(compressedData, decompressedData);
    REQUIRE(result);
    CHECK(decompressedData == uncompressedData);
  }
}

TEST_CASE("gunzip") {
  SECTION("gunzips data") {
    std::vector<std::byte> compressedData = readFile(compressedDataPath);
    std::vector<std::byte> uncompressedData = readFile(uncompressedDataPath);

    std::vector<std::byte> decompressedData;
    bool result = gunzip(compressedData, decompressedData);
    REQUIRE(result);
    CHECK(decompressedData == uncompressedData);
  }

  SECTION("returns false for invalid header") {
    std::vector<std::byte> invalidCompressedData =
        readFile(uncompressedDataPath);

    std::vector<std::byte> decompressedData;
    bool result = gunzip(invalidCompressedData, decompressedData);

    CHECK(!result);
  }

  SECTION("returns false for truncated data") {
    std::vector<std::byte> invalidCompressedData =
        readFile(invalidCompressedDataPath);

    std::vector<std::byte> decompressedData;
    bool result = gunzip(invalidCompressedData, decompressedData);

    CHECK(!result);
  }
}
