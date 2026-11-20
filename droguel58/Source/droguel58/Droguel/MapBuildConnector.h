#pragma once
#include "TileMap.h"

class MapBuildConnector
{
public:

    MapBuildConnector();
    ~MapBuildConnector();

    void OffsetMapLevelBuilder(TileMap& tilemap);

    void GetStairsData(TileMap& tilemap, int levelnum, TileData& up, TileData& down, int& index_up, int& index_dn);
    void MoveMap(TileMap& tilemap, int x, int y);
    void SetOffsetsOnly(TileMap& tilemap);
    void AddConnectors(TileMap& tilemap);
    void RotateStairs(TileMap& tilemap, bool trimPath);
    void BuildConnectors(TileMap& tilemap, bool isUE); //isUE = sprawl (false) vs stacked (true
    //void BuildConnectorsUE(TileMap& tilemap); //stacked
};


