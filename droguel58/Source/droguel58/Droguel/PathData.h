#pragma once
#include "TileData.h"
#include "RoomData.h"
#include <vector>

class PathData
{
public:

    PathData();
    ~PathData();
    
    struct StartEndCoord
    {
        int x1;
        int y1;
        int x2;
        int y2;
    };

    //rats nest connection list
    struct connector
    {
        int node_a;
        int node_b;
        double weight;
        bool active_connector;    
    };
    connector connect;


    //doors for active connection paths
    TileData door_a;
    TileData door_b;




    //int start_x;
    //int start_y;
    //int end_x;
    //int end_y;
    StartEndCoord start_end;





    //full tile path
    std::vector<TileData> path;
};
