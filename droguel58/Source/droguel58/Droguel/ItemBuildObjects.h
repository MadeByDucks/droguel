#pragma once
#include "TileMap.h"
#include <vector>

class ItemBuildObjects
{
public:

    ItemBuildObjects();
    ~ItemBuildObjects();

    void AddObject(TileMap& tilemap, int level, TileMap::ObjectType ot, int& line, int& id, int tx, int ty, int tz, int rx, int ry, int rz, int sx, int sy, int sz);
    void BuildLevelObjects(TileMap& tilemap, int levelnum);
    void writeExportData(TileMap& tilemap, std::string fname);
    void ExportObjectsUE(TileMap& tilemap);
    void DrawObjectsToMap(TileMap& tilemap, int levelnum);
};
