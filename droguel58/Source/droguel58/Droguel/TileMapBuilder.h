#pragma once
#include "TileMap.h"
#include "TileData.h"

class TileMapBuilder
{
public:

    TileMapBuilder();
    ~TileMapBuilder();

public:
    void AddTile(TileMap& tilemap, int levnum,
        TileData::TileType tile, int& line, int& id,
        int tx, int ty, int tz,
        int rx, int ry, int rz,
        int sx, int sy, int sz);


    void ClearTileMap(TileMap& tilemap);
    void DrawBlocksToMap(TileMap& tilemap, int levelnum);
    void DrawRoomsToMap(TileMap& tilemap, int levelnum);
    void DrawWallsOnPaths(TileMap& tilemap, int levelnum);
    void DrawPathsToMap(TileMap& tilemap, int levelnum);
    void DrawDoorsToMap(TileMap& tilemap, int levelnum);
    void DrawStairsToMap(TileMap& tilemap, int levelnum);

    void ExportTileMapUE(TileMap& tilemap);

    void CreateTileMap(TileMap& tilemap);
};
