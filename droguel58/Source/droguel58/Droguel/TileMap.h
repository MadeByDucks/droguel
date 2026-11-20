#pragma once

#include <string>
#include <vector>
#include "TileData.h"
#include "LevelData.h"
#include "LevelMgr.h"
#include "MapDefs.h"
#include "ResourceMgr.h"

class TileMap
{
public:
    enum MonsterType {M_General};
    enum ObjectType {O_General};
    enum direction {DirNorth, DirSouth, DirEast, DirWest};

    MapDefs m_mapdef;
    std::string m_mapName;
    int m_mapId;
    LevelMgr levMgr;
    std::vector<LevelData> level;


    ResourceMgr mResourceMgr;



    TileMap(int numTilesX, int numTilesY, int numlevelsZ, int mapId, std::string mapname);
    ~TileMap();

    TileData*** create_3d_array(int dim1, int dim2, int dim3);
    void destroy_3d_array(TileData ***array, int dim1, int dim2);

    //Tile functions
    bool inTileRange(int x, int y, int z);

    void SetMapName(std::string name);
    std::string GetMapName();

    int getNumLevels();
    std::string getTileChar(int x, int y, int z);
    void setTileChar(int x, int y, int z, std::string input);
    void setTileType(int x, int y, int z, TileData::TileType tt);
    TileData::TileType getTileType(int x, int y, int z);
    bool isUserNavTile(int x, int y, int z);

    void clearAllTiles();
    //void poplulateAllTilesWithChar();

    //dump functions
    void dumpTileMap(std::string fname);
    std::string dumpDataMapData();
    std::string dumpDataRooms();
    std::string dumpDataRoomBlocks();
    std::string dumpDataConnectionList(int levelnum);
    std::string dumpDataAllConnectionList();

private:
    TileData*** m_tilemap;
};
