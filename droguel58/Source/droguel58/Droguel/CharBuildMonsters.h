#pragma once
#include "TileMap.h"
#include <vector>

class CharBuildMonsters
{
public:

    CharBuildMonsters();
    ~CharBuildMonsters();

    void AddMonster(TileMap& tilemap, int level, TileMap::MonsterType mt, int& line, int &id, int tx, int ty, int tz, int rx, int ry, int rz, int sx, int sy, int sz);
    void BuildLevelMonsters(TileMap& tilemap, int levelnum); 
    void writeExportData(TileMap& tilemap, std::string fname);
    void ExportMonsterUE(TileMap& tilemap);
    void DrawMonstersToMap(TileMap& tilemap, int levelnum);
};
