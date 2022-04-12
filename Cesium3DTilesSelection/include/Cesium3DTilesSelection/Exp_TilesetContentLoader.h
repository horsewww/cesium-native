#pragma once

#include <Cesium3DTilesSelection/Exp_TileContent.h>
#include <Cesium3DTilesSelection/Exp_TileContentLoadInfo.h>
#include <CesiumAsync/AsyncSystem.h>
#include <CesiumAsync/Future.h>
#include <CesiumAsync/IAssetAccessor.h>

#include <spdlog/logger.h>

#include <memory>

namespace Cesium3DTilesSelection {
class Tile;

class TilesetContentLoader {
public:
  virtual ~TilesetContentLoader() = default;

  void loadTileContent(
      Tile& tile,
      CesiumAsync::AsyncSystem& asyncSystem,
      std::shared_ptr<CesiumAsync::IAssetAccessor>& pAssetAccessor,
      std::shared_ptr<spdlog::logger>& pLogger,
      const TilesetContentOptions &contentOptions);

  void updateTileContent(Tile& tile);

  bool unloadTileContent(Tile& tile);

private:
  static void setTileContentState(TileContent &content, TileContentKind&& contentKind, TileLoadState state);

  void processContentLoadedState(Tile& tile);

  void processDoneState(Tile& tile);

  virtual CesiumAsync::Future<TileContentKind>
  doLoadTileContent(const TileContentLoadInfo& loadInfo) = 0;

  virtual void doProcessLoadedContent(Tile& tile) = 0;

  virtual void doUpdateTileContent(Tile& tile) = 0;

  virtual bool doUnloadTileContent(Tile& tile) = 0;
};
} // namespace Cesium3DTilesSelection
