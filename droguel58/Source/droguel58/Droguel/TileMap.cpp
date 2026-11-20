#include "TileMap.h"
#include <vector>
#include <string>
#include <iostream>
#include "dpUtilFile.h"
#include "LevelData.h"
#include "PathData.h"
#include "ResourceMgr.h"

TileMap::TileMap(int numTilesX, int numTilesY, int numlevelsZ, int mapId, std::string mapname)
{
    m_mapId = mapId;
    m_mapName = mapname;
    m_mapdef.m_num_x_tiles = numTilesX;
    m_mapdef.m_num_y_tiles = numTilesY;
    m_mapdef.m_num_z_max_levels = numlevelsZ;

    //setup level manager
    levMgr.InitMapDefs(m_mapdef);

    //load in the resources for the map
    mResourceMgr.LoadResources();

    //setup levels
    for (int i = 0; i < m_mapdef.m_num_z_max_levels; i++)
    {
        LevelData level_info;// ();// m_mapdef);
        level_info.m_level_num = i;
        level_info.m_offset_x = 0;
        level_info.m_offset_y = 0;
        level.push_back(level_info);
    }

    //setup character tile map
    m_tilemap = create_3d_array(m_mapdef.m_num_x_tiles, m_mapdef.m_num_y_tiles, m_mapdef.m_num_z_max_levels);
}

TileMap::~TileMap()
{
    destroy_3d_array(m_tilemap, m_mapdef.m_num_x_tiles, m_mapdef.m_num_y_tiles);
}




///////////////////////////////////////////////////////////////////////////////
// Map Arrays
///////////////////////////////////////////////////////////////////////////////

TileData*** TileMap::create_3d_array(int dim1, int dim2, int dim3)
{
    TileData*** array = new TileData * *[dim1];
    for (int i = 0; i < dim1; i++) 
    {
        array[i] = new TileData * [dim2];
        for (int j = 0; j < dim2; j++) 
        {
            array[i][j] = new TileData[dim3];
        }
    }
    return array;
}

void TileMap::destroy_3d_array(TileData*** array, int dim1, int dim2)
{
    for (int i = 0; i < dim1; i++) 
    {
        for (int j = 0; j < dim2; j++) 
        {
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;
}



///////////////////////////////////////////////////////////////////////////////
// Map 
///////////////////////////////////////////////////////////////////////////////

void TileMap::SetMapName(std::string name)
{
    m_mapName = name;
}

std::string TileMap::GetMapName()
{
    return m_mapName;
}

int TileMap::getNumLevels()
{
    return level.size();
}

void TileMap::clearAllTiles()
{
    //std::string tilechar = "'";

    for (int z = 0; z < m_mapdef.m_num_z_max_levels; z++)
    {
        for (int y = 0; y < m_mapdef.m_num_y_tiles; y++)
        {
            for (int x = 0; x < m_mapdef.m_num_x_tiles; x++)
            {
                m_tilemap[x][y][z].clearTile();
            }
        }
    }
}



bool TileMap::inTileRange(int x, int y, int z)
{
    return ((x >= 0) && (y >= 0) && (z >= 0) &&
        (x < m_mapdef.m_num_x_tiles) &&
        (y < m_mapdef.m_num_y_tiles) &&
        (z < m_mapdef.m_num_z_max_levels));
}

std::string TileMap::getTileChar(int x, int y, int z)
{
    //ttdtodo check bounds
    if (inTileRange(x, y, z))
    {
        return m_tilemap[x][y][z].getTileStr();
    }
    else
    {
        return "";
    }
}

void TileMap::setTileChar(int x, int y, int z, std::string input)
{
    if (inTileRange(x, y, z))
    {
        m_tilemap[x][y][z].setTileStr(input);
    }
}

void TileMap::setTileType(int x, int y, int z, TileData::TileType tt)
{
    if (inTileRange(x, y, z))
    {
        m_tilemap[x][y][z].setTileType(tt);
    }
}

TileData::TileType TileMap::getTileType(int x, int y, int z)
{
    if (inTileRange(x, y, z))
    {
        return m_tilemap[x][y][z].getTileType();
    }
    else
        return TileData::TT_Error;
}

bool TileMap::isUserNavTile(int x, int y, int z)
{
    if (inTileRange(x, y, z))
    {
        return m_tilemap[x][y][z].isUserNavTile();
    }
    else
        return false;
}





void TileMap::dumpTileMap(std::string fname)
{
    std::vector<std::string> mapfile;
    std::string outstr;

    mapfile.push_back(dumpDataMapData());

    for (int levelnum = 0; levelnum < level.size(); levelnum++)
    {
        for (unsigned int i = 0; i < level[levelnum].room_list.size(); i++)
        {
            outstr = "";
            outstr += " level: " + std::to_string(level[levelnum].room_list[i].level);
            outstr += " it: " + std::to_string(level[levelnum].room_list[i].iteration);
            outstr += " xy1:(" + std::to_string(level[levelnum].room_list[i].block.x1) + "," + std::to_string(level[levelnum].room_list[i].block.y1) + ")";
            outstr += " xy2:(" + std::to_string(level[levelnum].room_list[i].block.x2) + "," + std::to_string(level[levelnum].room_list[i].block.y2) + ")";
            mapfile.push_back(outstr);
        }
    }

    //dump monsters
    outstr = "\n\nMonsterDump: \n";
    for (int levelnum = 0; levelnum < level.size(); levelnum++)
    {
        for (int monster_idx = 0; monster_idx < level[levelnum].monster_list.size(); monster_idx++)
        {
            ActiveCharMonster the_monster = level[levelnum].monster_list[monster_idx];
            outstr += "monster: ";
            outstr += " level: " + std::to_string(levelnum);
            outstr += " " + std::to_string(the_monster.m_pos.x) + "," + std::to_string(the_monster.m_pos.y) + "\n";
        }
    }
    outstr += "\n";
    mapfile.push_back(outstr);

    for (int z = 0; z < m_mapdef.m_num_z_max_levels; z++)
    {
        mapfile.push_back("\n\nLevel: " + std::to_string(z) + "\n\n");

        for (int y = 0; y < m_mapdef.m_num_y_tiles; y++)
        {
            outstr = "";
            for (int x = 0; x < m_mapdef.m_num_x_tiles; x++)
            {
                outstr += m_tilemap[x][y][z].getTileStr();
            }
            mapfile.push_back(outstr);
        }
    }

    for (int i = 0; i < m_mapdef.getMaxNumLevels(); i++)
    {
        mapfile.push_back(dumpDataConnectionList(i));
    }

    CUtilFile::writeStringArrayToFile(mapfile, fname);
}

std::string TileMap::dumpDataMapData()
{
    std::string outstr = "";
    outstr = "MapDefs:\n";
    outstr += "=======\n";
    outstr += "Map Width:       " + std::to_string(m_mapdef.getSizeX()) + "\n";
    outstr += "Map Height:      " + std::to_string(m_mapdef.getSizeY()) + "\n";
    outstr += "Map Levels:      " + std::to_string(m_mapdef.getSizeZmax()) + "\n";
    outstr += "Min Rooms:       " + std::to_string(m_mapdef.getNumRoomsMin()) + "\n";
    outstr += "Max Rooms:       " + std::to_string(m_mapdef.getNumRoomsMax()) + "\n";
    outstr += "Min Room Width:  " + std::to_string(m_mapdef.getRoomMinWidth()) + "\n";
    outstr += "Max Room Width:  " + std::to_string(m_mapdef.getRoomMaxWidth()) + "\n";
    outstr += "Min Room Height: " + std::to_string(m_mapdef.getRoomMinHeight()) + "\n";
    outstr += "MaxRoom Height:  " + std::to_string(m_mapdef.getRoomMaxHeight()) + "\n";
    outstr += "TileX: " + std::to_string(m_mapdef.xm) + "\n";
    outstr += "TileY: " + std::to_string(m_mapdef.ym) + "\n";
    outstr += "TileX: " + std::to_string(m_mapdef.zm) + "\n";
    outstr += "\n\n\n";
    return outstr;
}

std::string TileMap::dumpDataRooms()
{
    return "";
}

std::string TileMap::dumpDataRoomBlocks()
{
    return "";
}

std::string TileMap::dumpDataConnectionList(int levelnum)
{
    std::string outstr = "";
    outstr += "\n\nCONNECTION LIST NODES\n";
    outstr += "LEVEL: " + std::to_string(levelnum) + "\n";

    for (int i = 0; i < level[levelnum].path_list.size(); i++)
    {
        PathData rec = level[levelnum].path_list[i];
        if (rec.connect.active_connector)
        {
            outstr += "  node_a: " + std::to_string(rec.connect.node_a) +
                " node_b: " + std::to_string(rec.connect.node_b) +
                " weight: " + std::to_string(rec.connect.weight) + "\n";
        }
    }
    return outstr;
}

std::string TileMap::dumpDataAllConnectionList()
{
    std::string outstr = "";
    for (int levelnum = 0; levelnum < getNumLevels(); levelnum++)
    {
        outstr += dumpDataConnectionList(levelnum);
    }
    std::cout << outstr << std::endl;
    return outstr;
}
