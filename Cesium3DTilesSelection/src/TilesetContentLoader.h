#pragma once

#include <Cesium3DTilesSelection/TileContent.h>
#include <Cesium3DTilesSelection/TilesetOptions.h>
#include <CesiumAsync/AsyncSystem.h>
#include <CesiumAsync/Future.h>
#include <CesiumAsync/IAssetAccessor.h>

#include <spdlog/logger.h>

#include <functional>
#include <memory>
#include <vector>

namespace Cesium3DTilesSelection {
class Tile;

enum class TileLoadResultState { Success, Failed, RetryLater };

struct TileLoadResult {
  TileContentKind contentKind;
  TileLoadResultState state;
  std::shared_ptr<CesiumAsync::IAssetRequest> pCompletedRequest;
};

class TilesetContentLoader {
public:
  virtual ~TilesetContentLoader() = default;

  virtual CesiumAsync::Future<TileLoadResult> loadTileContent(
      Tile& tile,
      const TilesetContentOptions& contentOptions,
      const CesiumAsync::AsyncSystem& asyncSystem,
      const std::shared_ptr<CesiumAsync::IAssetAccessor>& pAssetAccessor,
      const std::shared_ptr<spdlog::logger>& pLogger,
      const std::vector<CesiumAsync::IAssetAccessor::THeader>&
          requestHeaders) = 0;

  virtual bool updateTileContent(Tile& tile) = 0;
};
} // namespace Cesium3DTilesSelection
