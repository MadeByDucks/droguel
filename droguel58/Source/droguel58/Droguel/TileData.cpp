#include "TileData.h"

TileData::TileData()
{
    m_tileStr = "";
    m_tileType = TT_Empty;
    m_isUserNav = false;
}

TileData::~TileData()
{
}

bool TileData::isStairUp(TileData::TileType tile)
{
    return (
        (tile == TileData::TT_StairUp) ||
        (tile == TileData::TT_StairUpNorth) ||
        (tile == TileData::TT_StairUpSouth) ||
        (tile == TileData::TT_StairUpEast) ||
        (tile == TileData::TT_StairUpWest)
        );
}

bool TileData::isStairDown(TileData::TileType tile)
{
    return (
        (tile == TileData::TT_StairDown) ||
        (tile == TileData::TT_StairDownNorth) ||
        (tile == TileData::TT_StairDownSouth) ||
        (tile == TileData::TT_StairDownEast) ||
        (tile == TileData::TT_StairDownWest)
        );
}

bool TileData::isDoorTile(TileData::TileType tile)
{
    return (
        (tile == TileData::TT_NorthDoor) ||
        (tile == TileData::TT_SouthDoor) ||
        (tile == TileData::TT_EastDoor) ||
        (tile == TileData::TT_WestDoor)
        );
}

bool TileData::isPathTile(TileData::TileType tile)
{
    return (
        (tile == TileData::TT_NS_Path) ||
        (tile == TileData::TT_EW_Path) ||

        (tile == TileData::TT_NW_Path) ||
        (tile == TileData::TT_NE_Path) ||
        (tile == TileData::TT_SE_Path) ||
        (tile == TileData::TT_SW_Path) ||

        (tile == TileData::TT_PathEndNorth) ||
        (tile == TileData::TT_PathEndSouth) ||
        (tile == TileData::TT_PathEndEast) ||
        (tile == TileData::TT_PathEndWest) ||

        (tile == TileData::TT_TNorthPath) ||
        (tile == TileData::TT_TSouthPath) ||
        (tile == TileData::TT_TEastPath) ||
        (tile == TileData::TT_TWestPath) ||  

        //(tile == TileData::TT_PathDiagNW) ||
        //(tile == TileData::TT_PathDiagNE) ||
        //(tile == TileData::TT_PathDiagSE) ||
        //(tile == TileData::TT_PathDiagSW) ||

        (tile == TileData::TT_PathSimple) ||
        (tile == TileData::TT_CrossPath) 
        );
}

bool TileData::isNavTile(TileData::TileType tile)
{
    return(TileData::isDoorTile(tile) || TileData::isPathTile(tile));
}


void TileData::clearTile()
{
    m_tileStr = " "; //space
    m_tileType = TileData::TT_Empty;

    m_pos.x = 0;
    m_pos.y = 0;
    m_pos.z = 0;

    m_pos.x_world = 0;
    m_pos.y_world = 0;
    m_pos.z_world = 0;
}

void TileData::setTileInfo(std::string tileStr, TileType tileType)
{
   m_tileStr = tileStr;
   m_tileType = tileType;
}

void TileData::setTilePos(int x, int y, int z)
{
   m_pos.x = x;
   m_pos.y = y;
   m_pos.z = z;
}

void TileData::setTileWorldPos(float x, float y, float z)
{
   m_pos.x_world = x;
   m_pos.y_world = y;
   m_pos.z_world = z;
}

void TileData::setTileStr(std::string tileStr)
{
    m_tileStr = tileStr;
}

std::string TileData::getTileStr()
{
    return m_tileStr;
}

TileData::TileType TileData::getTileType()
{
    return m_tileType;
}

void TileData::setTileType(TileType tileType)
{
    m_isUserNav = true;
    m_tileType = tileType;
}

bool TileData::isUserNavTile()
{
    return (isNavTile(m_tileType) || isPathTile(m_tileType) || isStairUp(m_tileType) || isStairDown(m_tileType) ||
        (m_tileType == TT_Floor) ||
        (m_tileType == TT_MidFloor) ||
        (m_tileType == TT_Gateway)
        );
}