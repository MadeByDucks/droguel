#include "LevelData.h"
#include "dnd_chance.h"
#include "alg_bsp.h"
#include "MapDefs.h"

LevelData::LevelData()//MapDefs mapdef)
{
    m_level_num = -1;
    m_map_num = -1;
    m_offset_x = 0;
    m_offset_y = 0;

    //m_tileLevelMap = create_2d_array(mapdef.m_num_x_tiles, mapdef.m_num_y_tiles);
}

LevelData::~LevelData()
{
    //destroy_2d_array(m_tileLevelMap, mapdef.m_num_x_tiles);
}

TileData** LevelData::create_2d_array(int rows, int cols)
{
    TileData** array = new TileData * [rows];
    for (int i = 0; i < rows; ++i)
    {
        array[i] = new TileData[cols];
    }
    return array;
}

void LevelData::destroy_2d_array(TileData** array, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] array[i];
    }
    delete[] array;
}

int LevelData::getNumRooms()
{
    return room_list.size();
}

bool LevelData::checkForCollision(int x, int y)
{
    bool open = true;
    for (int i = 0; i < stair_list.size(); i++)
    {
        if ((stair_list[i].m_pos.x == x) && (stair_list[i].m_pos.y == y))
        {
            open = false;
        }
    }

    if (open)
    {
        for (int i = 0; i < monster_list.size(); i++)
        {
            if ((monster_list[i].m_pos.x == x) && (monster_list[i].m_pos.y == y))
            {
                open = false;
            }
        }
    }
    return open;
}

int LevelData::getRandomRoomIndex()
{
    int num_rooms = room_list.size();
    int room_num = dnd_chance::randomBetween(0, num_rooms - 1);
    return room_num;
}

mapPosition LevelData::getRandomOpenTileOnLevel()
{
    //ttdtodo:now need a way to find open spot if there was a collision
    bool open = false;
    mapPosition pos;

    for (int i = 1; i < 10; i++)
    {
        if (!open)
        {
            int room_idx = getRandomRoomIndex();
            room_list[room_idx].getRandomTileInRoom(pos);
            open = checkForCollision(pos.x, pos.y);
        }
    }

    if (!open)
    {
        int x = 9;
    }
    return pos;
}
