#pragma once
#include "MapDefs.h"
#include <string>

class TileData
{
public:

    TileData();
    ~TileData();

public:
    enum TileType {
        TT_Floor, TT_Ceiling, TT_PathWall, TT_Wall,
        TT_StairUp, TT_StairDown,
        TT_NorthWall, TT_SouthWall, TT_EastWall, TT_WestWall,
        TT_NW_Corner, TT_NE_Corner, TT_SW_Corner, TT_SE_Corner,
        TT_NorthDoor, TT_SouthDoor, TT_EastDoor, TT_WestDoor,
        TT_NS_Path, TT_EW_Path, TT_CrossPath, TT_PathSimple,
        TT_NW_Path, TT_SW_Path, TT_NE_Path, TT_SE_Path,
        TT_TNorthPath, TT_TSouthPath, TT_TEastPath, TT_TWestPath,
        TT_PathEndNorth, TT_PathEndSouth, TT_PathEndEast, TT_PathEndWest,
        TT_PathDiagNW, TT_PathDiagNE, TT_PathDiagSE, TT_PathDiagSW,
        TT_Door, TT_Gateway,
        TT_StairUpNorth, TT_StairUpSouth, TT_StairUpEast, TT_StairUpWest,
        TT_StairDownNorth, TT_StairDownSouth, TT_StairDownEast, TT_StairDownWest,
        TT_MidFloor,
        TT_Error, TT_Empty
    };


    int roomidx;
    mapPosition m_pos;

    //map
    //tile coordinates
    //world coordinates


    static bool isStairUp(TileData::TileType tile);
    static bool isStairDown(TileData::TileType tile);
    static bool isDoorTile(TileData::TileType tile);
    static bool isPathTile(TileData::TileType tile);
    static bool isNavTile(TileData::TileType tile);
    
    
    bool isUserNavTile();

    void clearTile();

    void setTileInfo(std::string tileStr, TileType tileType);
    void setTilePos(int x, int y, int z);
    void setTileWorldPos(float x, float y, float z);

    std::string        getTileStr();
    void               setTileStr(std::string tileStr);
    TileData::TileType getTileType();
    void               setTileType(TileType tileType);

private:
    std::string m_tileStr;
    TileType    m_tileType;

    bool        m_isUserNav;


};
