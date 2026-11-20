#include "LevelBuilder.h"
#include "alg_bsp.h"
#include "MapDefs.h"
#include "dnd_chance.h"
#include "pathfinder.h"
#include "CharBuildMonsters.h"
#include "ItemBuildObjects.h"
#include <cmath>

LevelBuilder::LevelBuilder()
{
}

LevelBuilder::~LevelBuilder()
{
}

void LevelBuilder::BuildConnectionList(MapDefs& mapdef, std::vector<RoomData>& room_list, std::vector<PathData>& path_list, int levelnum)
{
    struct path_weight
    {
        int node_a;
        int node_b;
        bool node_a_active;
        bool node_b_active;
        double weight;
        bool selected;
    };
    std::vector<path_weight> pathlist;

    pathlist.clear();
    int num_nodes = room_list.size();

    for (int i = 0; i < num_nodes - 1; i++)
    {
        for (int j = i + 1; j < num_nodes; j++)
        {
            //TileMap::pathrec rec;
            //rec.node_a = tilemap.level[levelnum].room_list[i];
            //rec.node_b = tilemap.level[levelnum].room_list[j];

            //int x1 = rec.node_a.room.x1 + (GetRoomWidth(rec.node_a) / 2);
            //int y1 = rec.node_a.room.y1 + (GetRoomHeight(rec.node_a) / 2);

            //int x2 = rec.node_b.room.x2 + (GetRoomWidth(rec.node_b) / 2);
            //int y2 = rec.node_b.room.y2 + (GetRoomHeight(rec.node_b) / 2);

            //rec.weight = sqrt((std::pow((x2 - x1), 2) + std::pow((y2 - y1), 2)));
            //rec.selected = false;

            //tilemap.level[levelnum].paths.push_back(rec);

            RoomData::MapRect rect1 = room_list[i].room;
            RoomData::MapRect rect2 = room_list[j].room;

            //room centers

            int x1;//= rect1.x1 + (GetRectWidth(rect1) / 2);
            int y1;//= rect1.y1 + (GetRectHeight(rect1) / 2);
            int x2;//= rect2.x2 + (GetRectWidth(rect2) / 2);
            int y2;//= rect2.y2 + (GetRectHeight(rect2) / 2);
            room_list[i].getRoomCenter(x1, y1);
            room_list[j].getRoomCenter(x2, y2);


            //path weight (use different calculations) Heuristic::getDelta / Heuristic::manhattan / Heuristic::euclidean / Heuristic::octagonal
            path_weight path_rec;
            path_rec.node_a = i;
            path_rec.node_b = j;
            path_rec.weight = sqrt((std::pow((x2 - x1), 2) + std::pow((y2 - y1), 2)));
            path_rec.selected = false;
            path_rec.node_a_active = false;
            path_rec.node_b_active = false;
            pathlist.push_back(path_rec);
        }
    }

    ////create list of nodes
    //std::vector<int> selected;
    //for (int i = 0; i < tilemap.level[levelnum].room_list.size() - 1; i++)
    //{
    //    int is_active = false;
    //    selected.push_back(is_active);
    //}
    //selected[index] = true;

    //pick random node
    int index = dnd_chance::getRandomInt(1, num_nodes) - 1; //zero base

    //select starting point
    int num_selected = 1;
    for (int i = 0; i < pathlist.size(); i++)
    {
        if (pathlist[i].node_a == index)
        {
            pathlist[i].node_a_active = true;
        }
        if (pathlist[i].node_b == index)
        {
            pathlist[i].node_b_active = true;
        }
    }


    //traverse
    bool disconnected = false;

    while ((num_selected < num_nodes) && (!disconnected))
    {
        disconnected = true;
        float min_weight = 0.0;
        int min_node = -1;
        int min_path = -1;

        //create list of weights and find min
        for (int i = 0; i < pathlist.size(); i++)
        {
            if (pathlist[i].selected == false)
            {
                if ((pathlist[i].node_a_active) && (!pathlist[i].node_b_active) ||
                    (!pathlist[i].node_a_active) && (pathlist[i].node_b_active))
                {
                    if ((min_node < 0) || (min_weight > pathlist[i].weight))
                    {
                        min_weight = pathlist[i].weight;
                        if (pathlist[i].node_a_active)
                            min_node = pathlist[i].node_b;
                        else
                            min_node = pathlist[i].node_a;
                        min_path = i;

                        disconnected = false;
                    }
                }
            }
        }

        //set vector
        if (min_path >= 0)
        {
            pathlist[min_path].selected = true;
            num_selected++;
        }

        //set nodes
        for (int i = 0; i < pathlist.size(); i++)
        {
            if (min_node == pathlist[i].node_a)
            {
                pathlist[i].node_a_active = true;
            }
            if (min_node == pathlist[i].node_b)
            {
                pathlist[i].node_b_active = true;
            }
        }

        if (disconnected == true)
            int x = 5;
    }

    //only copy selected so active will always be true for now???
    for (int i = 0; i < pathlist.size(); i++)
    {
        PathData rec;
        rec.connect.node_a = pathlist[i].node_a;
        rec.connect.node_b = pathlist[i].node_b;
        rec.connect.weight = pathlist[i].weight;
        rec.connect.active_connector = pathlist[i].selected;
        //rec.active_path = true;
        path_list.push_back(rec);
    }

    ////save list
    //std::cout << "\n\nCONNECTION LIST NODES" << std::endl;
    //std::cout << "LEVEL: " << levelnum  < < std::endl;
    //for (int i = 0; i < pathlist.size(); i++)
    //{
    //    if (pathlist[i].selected == true)
    //        std::cout << i << " " << pathlist[i].node_a << " " << pathlist[i].node_b << std::endl;
    //}
    //std::cout << "= = = = =" << std::endl;
}



void LevelBuilder::BuildDoors(std::vector<RoomData>& room_list, std::vector<PathData>& path_list)
{
    PathData::StartEndCoord start_end;
    int level = -1;

    //for (int levelnum = 0; levelnum < tilemap.m_mapdef.getNumLevels(); levelnum++)
    //{
    for (int path_idx = 0; path_idx < path_list.size(); path_idx++)
    {
        PathData path = path_list[path_idx];
        if (path.connect.active_connector)//(path.active_path)
        {
            RoomData room_a = room_list[path.connect.node_a];
            RoomData room_b = room_list[path.connect.node_b];

            int xpos_a = dnd_chance::randomBetween(room_a.room.x1 + 1, room_a.room.x2 - 1);
            int ypos_a = dnd_chance::randomBetween(room_a.room.y1 + 1, room_a.room.y2 - 1);
            int xpos_b = dnd_chance::randomBetween(room_b.room.x1 + 1, room_b.room.x2 - 1);
            int ypos_b = dnd_chance::randomBetween(room_b.room.y1 + 1, room_b.room.y2 - 1);

            //direction from room a to b
            TileData door_a;
            TileData door_b;
            if ((room_a.room.x1 <= room_b.room.x1) && (room_a.room.y1 <= room_b.room.y1))
            {
                door_a.roomidx = path.connect.node_a;
                door_b.roomidx = path.connect.node_b;

                //a-SE b-NW
                if (dnd_chance::pickRandom())
                {
                    //South Door
                    door_a.setTilePos(xpos_a, room_a.room.y2, level);
                    //door_a.m_pos.x = xpos_a;
                    //door_a.m_pos.y = room_a.room.y2;
                    door_a.setTileType(TileData::TT_SouthDoor);
                    start_end.x1 = xpos_a;
                    start_end.y1 = room_a.room.y2 + 1;
                }
                else
                {
                    //East Door
                    door_a.setTilePos(room_a.room.x2, ypos_a, level);
                    //door_a.m_pos.x = room_a.room.x2;
                    //door_a.m_pos.y = ypos_a;
                    door_a.setTileType(TileData::TT_EastDoor);
                    start_end.x1 = room_a.room.x2 + 1;
                    start_end.y1 = ypos_a;
                }

                if (dnd_chance::pickRandom())
                {
                    //North Door
                    door_b.setTilePos(xpos_b, room_b.room.y1, level);
                    //door_b.m_pos.x = xpos_b;
                    //door_b.m_pos.y = room_b.room.y1;
                    door_b.setTileType(TileData::TT_NorthDoor);
                    start_end.x2 = xpos_b;
                    start_end.y2 = room_b.room.y1 - 1;
                }
                else
                {
                    //West Door
                    door_b.setTilePos(room_b.room.x1, ypos_b, level);
                    //door_b.m_pos.x = room_b.room.x1;
                    //door_b.m_pos.y = ypos_b;
                    door_b.setTileType(TileData::TT_WestDoor);
                    start_end.x2 = room_b.room.x1 - 1;
                    start_end.y2 = ypos_b;
                }
            }
            else if ((room_a.room.x1 <= room_b.room.x1) && (room_a.room.y1 >= room_b.room.y1))
            {
                //a-NE b-SW
                if (dnd_chance::pickRandom())
                {
                    //North Door
                    door_a.setTilePos(xpos_a, room_a.room.y1, level);
                    //door_a.m_pos.x = xpos_a;
                    //door_a.m_pos.y = room_a.room.y1;
                    door_a.setTileType(TileData::TT_NorthDoor);
                    start_end.x1 = xpos_a;
                    start_end.y1 = room_a.room.y1 - 1;
                }
                else
                {
                    //East Door
                    door_a.setTilePos(room_a.room.x2, ypos_a, level);
                    //door_a.m_pos.x = room_a.room.x2;
                    //door_a.m_pos.y = ypos_a;
                    door_a.setTileType(TileData::TT_EastDoor);
                    start_end.x1 = room_a.room.x2 + 1;
                    start_end.y1 = ypos_a;
                }

                if (dnd_chance::pickRandom())
                {
                    //South Door
                    door_b.setTilePos(xpos_b, room_b.room.y2, level);
                    //door_b.m_pos.x = xpos_b;
                    //door_b.m_pos.y = room_b.room.y2;
                    door_b.setTileType(TileData::TT_SouthDoor);
                    start_end.x2 = xpos_b;
                    start_end.y2 = room_b.room.y2 + 1;
                }
                else
                {
                    //West Door
                    door_b.setTilePos(room_b.room.x1, ypos_b, level);
                    //door_b.m_pos.x = room_b.room.x1;
                    //door_b.m_pos.y = ypos_b;
                    door_b.setTileType(TileData::TT_WestDoor);
                    start_end.x2 = room_b.room.x1 - 1;
                    start_end.y2 = ypos_b;
                }
            }
            else if ((room_a.room.x1 >= room_b.room.x1) && (room_a.room.y1 <= room_b.room.y1))
            {
                //a-SW b-NE
                if (dnd_chance::pickRandom())
                {
                    //South Door
                    door_a.setTilePos(xpos_a, room_a.room.y2, level);
                    //door_a.m_pos.x = xpos_a;
                    //door_a.m_pos.y = room_a.room.y2;
                    door_a.setTileType(TileData::TT_SouthDoor);
                    start_end.x1 = xpos_a;
                    start_end.y1 = room_a.room.y2 + 1;
                }
                else
                {
                    //West Door
                    door_a.setTilePos(room_a.room.x1, ypos_a, level);
                    //door_a.m_pos.x = room_a.room.x1;
                    //door_a.m_pos.y = ypos_a;
                    door_a.setTileType(TileData::TT_WestDoor);
                    start_end.x1 = room_a.room.x1 - 1;
                    start_end.y1 = ypos_a;
                }

                if (dnd_chance::pickRandom())
                {
                    //North Door
                    door_b.setTilePos(xpos_b, room_b.room.y1, level);
                    //door_b.m_pos.x = xpos_b;
                    //door_b.m_pos.y = room_b.room.y1;
                    door_b.setTileType(TileData::TT_NorthDoor);
                    start_end.x2 = xpos_b;
                    start_end.y2 = room_b.room.y1 - 1;
                }
                else
                {
                    //East Door
                    door_b.setTilePos(room_b.room.x2, ypos_b, level);
                    //door_b.m_pos.x = room_b.room.x2;
                    //door_b.m_pos.y = ypos_b;
                    door_b.setTileType(TileData::TT_EastDoor);
                    start_end.x2 = room_b.room.x2 + 1;
                    start_end.y2 = ypos_b;
                }
            }
            else if ((room_a.room.x1 >= room_b.room.x1) && (room_a.room.y1 >= room_b.room.y1))
            {
                //a-NW b-SE
                if (dnd_chance::pickRandom())
                {
                    //North Door
                    door_a.setTilePos(xpos_a, room_a.room.y1, level);
                    //door_a.m_pos.x = xpos_a;
                    //door_a.m_pos.y = room_a.room.y1;
                    door_a.setTileType(TileData::TT_NorthDoor);
                    start_end.x1 = xpos_a;
                    start_end.y1 = room_a.room.y1 - 1;
                }
                else
                {
                    //West Door
                    door_a.setTilePos(room_a.room.x1, ypos_a, level);
                    //door_a.m_pos.x = room_a.room.x1;
                    //door_a.m_pos.y = ypos_a;
                    door_a.setTileType(TileData::TT_WestDoor);
                    start_end.x1 = room_a.room.x1 - 1;
                    start_end.y1 = ypos_a;
                }

                if (dnd_chance::pickRandom())
                {
                    //South Door
                    door_b.setTilePos(xpos_b, room_b.room.y2, level);
                    //door_b.m_pos.x = xpos_b;
                    //door_b.m_pos.y = room_b.room.y2;
                    door_b.setTileType(TileData::TT_SouthDoor);
                    start_end.x2 = xpos_b;
                    start_end.y2 = room_b.room.y2 + 1;
                }
                else
                {
                    //East Door
                    door_b.setTilePos(room_b.room.x2, ypos_b, level);
                    //door_b.m_pos.x = room_b.room.x2;
                    //door_b.m_pos.y = ypos_b;
                    door_b.setTileType(TileData::TT_EastDoor);
                    start_end.x2 = room_b.room.x2 + 1;
                    start_end.y2 = ypos_b;
                }
            }

            path_list[path_idx].door_a = door_a;
            path_list[path_idx].door_b = door_b;
            path_list[path_idx].start_end = start_end;
        }
    }
    //}
}


void LevelBuilder::BuildPathList(MapDefs& mapdef, std::vector<RoomData>& room_list, std::vector<PathData>& path_list)
{
    pathfinder x;
    x.process(mapdef, room_list, path_list);
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void LevelBuilder::BuildStairs(LevelData& level_info, std::vector<RoomData>& room_list, std::vector<TileData>& stairList)
{
    TileData stairs;
    int level = -1;

    int roomStairsUpIdx = dnd_chance::getRandomInt(0, room_list.size() - 1);
    int roomStairsDownIdx = dnd_chance::getRandomInt(0, room_list.size() - 1);

    //try to avoid rooms with upstairs and downstairs
    int counter = 0;
    while ((counter <= 10) && (roomStairsUpIdx == roomStairsDownIdx))
    {
        roomStairsDownIdx = dnd_chance::getRandomInt(0, room_list.size() - 1);
        counter++;
    }

    //find random open sponts in room
    RoomData roomStairsUp = room_list[roomStairsUpIdx];
    RoomData roomStairsDown = room_list[roomStairsDownIdx];

    int up_x = dnd_chance::getRandomInt(roomStairsUp.room.x1 + 1, roomStairsUp.room.x2 - 1);
    int up_y = dnd_chance::getRandomInt(roomStairsUp.room.y1 + 1, roomStairsUp.room.y2 - 1);
    int dn_x = dnd_chance::getRandomInt(roomStairsDown.room.x1 + 1, roomStairsDown.room.x2 - 1);
    int dn_y = dnd_chance::getRandomInt(roomStairsDown.room.y1 + 1, roomStairsDown.room.y2 - 1);

    //stairs.m_pos.x = up_x;
    //stairs.m_pos.y = up_y;
    stairs.setTilePos(up_x, up_y, level);
    stairs.roomidx = roomStairsUpIdx;
    stairs.setTileType(TileData::TT_StairUp);
    stairList.push_back(stairs);

    stairs.setTilePos(dn_x, dn_y, level);
    //stairs.m_pos.x = dn_x;
    //stairs.m_pos.y = dn_y;
    stairs.roomidx = roomStairsDownIdx;
    stairs.setTileType(TileData::TT_StairDown);
    stairList.push_back(stairs);
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


void LevelBuilder::buildLevel(TileMap& tilemap, int levelnum)
{
    alg_bsp bsp;
    bsp.buildRoomBlocks(tilemap.m_mapdef, tilemap.level[levelnum].room_list, levelnum);
    bsp.BuildRoomsFromBlocks(tilemap.m_mapdef, tilemap.level[levelnum].room_list);

    BuildConnectionList(tilemap.m_mapdef, tilemap.level[levelnum].room_list, tilemap.level[levelnum].path_list, levelnum);
    BuildDoors(tilemap.level[levelnum].room_list, tilemap.level[levelnum].path_list);
    BuildPathList(tilemap.m_mapdef, tilemap.level[levelnum].room_list, tilemap.level[levelnum].path_list);
    BuildStairs(tilemap.level[levelnum], tilemap.level[levelnum].room_list, tilemap.level[levelnum].stair_list);

    //CharBuildMonsters monster_util;
    //monster_util.BuildLevelMonsters(tilemap, levelnum);

    //ItemBuildObjects objectUtil;
    //objectUtil.BuildLevelObjects(tilemap, levelnum);
}
