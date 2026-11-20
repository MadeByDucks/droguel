#include "pathfinder.h"
#include "alg_astar.h"
#include "TileMap.h"
#include <iostream>
#include "dnd_chance.h"
#include "LevelData.h"
#include "TileData.h"


//https://github.com/daancode/a-star
//https://rosettacode.org/wiki/A*_search_algorithm
//https://www.geeksforgeeks.org/a-search-algorithm/


pathfinder::pathfinder()
{
}


pathfinder::~pathfinder()
{
}


void pathfinder::test()
{
    AStar::Generator generator;
    // Set 2d map size.
    generator.setWorldSize({ 25, 25 });
    // You can use a few heuristics : manhattan, euclidean or octagonal.
    generator.setHeuristic(AStar::Heuristic::euclidean);
    generator.setDiagonalMovement(true);

    std::cout << "\n\n\n";
    std::cout << "Generate path ... \n";
    // This method returns vector of coordinates from target to source.
/////////////////////    auto path = generator.findPath({ 0, 0 }, { 20, 20 });

////////////////////    for (auto& coordinate : path) 
    {
////////////////////        std::cout << coordinate.x << " " << coordinate.y << "\n";
    }
}

void pathfinder::process(MapDefs& mapdef, std::vector<RoomData>& room_list, std::vector<PathData>& path_list)
{
    AStar::Generator generator;
    // Set 2d map size.
    generator.setWorldSize({ mapdef.getSizeX(), mapdef.getSizeY()});
    // You can use a few heuristics : manhattan, euclidean or octagonal.
    generator.setHeuristic(AStar::Heuristic::euclidean);
    generator.setDiagonalMovement(false);

    std::cout << "\n\n\n";
    std::cout << "Generate path ... \n";

    //for (int levnum = 0; levnum < tilemap.mapdef.getNumLevels(); levnum++)
    //{
        for (int i = 0; i < path_list.size(); i++)
        {
            PathData path = path_list[i];
            if (path.connect.active_connector)
            {
                //x1 y1 and x2 y2 are the door pos and not the start pos which would be a conflict

                PathData::StartEndCoord start_end = path_list[i].start_end;
                int x1 = start_end.x1; //tilemap.level[level].path_list[i].door_a.x;
                int y1 = start_end.y1; //tilemap.level[level].path_list[i].door_a.y;
                int x2 = start_end.x2; //tilemap.level[level].path_list[i].door_b.x;
                int y2 = start_end.y2; //tilemap.level[level].path_list[i].door_b.y;

                auto pathfinder = generator.findPath(mapdef, room_list,/*tilemap, levnum,*/ {x1, y1}, {x2, y2});

                std::cout << /*"level: " << levnum <<*/ " node a: " << path.connect.node_a << " node b: " << path.connect.node_b << std::endl;
                for (auto& coordinate : pathfinder) 
                {
                    std::cout << coordinate.x << " " << coordinate.y << "\n";

                    TileData element;
                    element.m_pos.x = coordinate.x;
                    element.m_pos.y = coordinate.y;
                    path_list[i].path.push_back(element);
                }

                //save rec
            }
        }
    //}
    test();
}

