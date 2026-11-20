#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <cmath> //a* 
#include <unordered_map> //a*



enum class TileType { Empty, Player, Monster, Wall };

struct Tile 
{
    int x, y;
    TileType type;

    Tile(int x, int y, TileType type) : x(x), y(y), type(type) {}
};




class GameGrid
{
private:
    int width, height;
    std::vector<std::vector<Tile>> grid;

public:
    GameGrid(int w, int h);
    void setTile(int x, int y, TileType type);
    std::vector<Tile> findPath();
};




class GameGridORIGINAL
{
private:
    int width, height;
    std::vector<std::vector<Tile>> grid;

public:
    GameGridORIGINAL(int w, int h) : width(w), height(h), grid(h, std::vector<Tile>(w, Tile(0, 0, TileType::Empty)))
    {
        for (int y = 0; y < h; ++y)
            for (int x = 0; x < w; ++x)
                grid[y][x] = Tile(x, y, TileType::Empty);
    }

    void setTile(int x, int y, TileType type)
    {
        if (x >= 0 && x < width && y >= 0 && y < height)
            grid[y][x].type = type;
    }

    std::vector<Tile> findPath()
    {
        std::pair<int, int> monsterPos, playerPos;
        bool monsterFound = false, playerFound = false;

        // Find monster and player positions
        for (int y = 0; y < height; ++y) 
        {
            for (int x = 0; x < width; ++x) 
            {
                if (grid[y][x].type == TileType::Monster) 
                {
                    monsterPos = { x, y };
                    monsterFound = true;
                }
                else if (grid[y][x].type == TileType::Player) 
                {
                    playerPos = { x, y };
                    playerFound = true;
                }
            }
        }

        if (!monsterFound || !playerFound) return {};

        std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));
        std::vector<std::vector<std::pair<int, int>>> parent(height, std::vector<std::pair<int, int>>(width, { -1, -1 }));

        std::queue<std::pair<int, int>> q;
        q.push(monsterPos);
        visited[monsterPos.second][monsterPos.first] = true;

        ///////////////////////////////////////////////////////////////////////
        // Diagonals // 8 Possible movements (including diagonals)
        ///////////////////////////////////////////////////////////////////////
        //
        int directions[8][2] = 
        {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0},  // Cardinal directions
            {1, 1}, {-1, -1}, {1, -1}, {-1, 1} // Diagonal directions
        };

        ///////////////////////////////////////////////////////////////////////
        // NO Diagonals // Cardinal directions
        ///////////////////////////////////////////////////////////////////////
        //
        //int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        //
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////

        // BFS for shortest path
        while (!q.empty()) 
        {
            auto [x, y] = q.front();
            q.pop();

            if (x == playerPos.first && y == playerPos.second)
                break;

            for (auto& [dx, dy] : directions) 
            {
                int nx = x + dx, ny = y + dy;

                if (nx >= 0 && nx < width && ny >= 0 && ny < height &&
                    !visited[ny][nx] && grid[ny][nx].type == TileType::Empty) 
                {
                    visited[ny][nx] = true;
                    parent[ny][nx] = { x, y };
                    q.push({ nx, ny });
                }
            }
        }

        // Backtrack to get the path
        std::vector<Tile> path;
        std::pair<int, int> current = playerPos;

        while (current != monsterPos) 
        {
            auto [px, py] = parent[current.second][current.first];
            if (px == -1 && py == -1) return {}; // No valid path found
            path.push_back(grid[current.second][current.first]);
            current = { px, py };
        }

        std::reverse(path.begin(), path.end());
        return path;
    }
};





// Struct for priority queue nodes
struct Node 
{
    int x, y;
    double f, g, h; // f = g + h
    Node(int x, int y, double g, double h) : x(x), y(y), g(g), h(h), f(g + h) {}

    // Comparator for priority queue (min-heap)
    bool operator>(const Node& other) const 
    {
        return f > other.f;
    }
};

class GameGridAStar
{
private:
    int width, height;
    std::vector<std::vector<Tile>> grid;

public:
    GameGridAStar(int w, int h) : width(w), height(h), grid(h, std::vector<Tile>(w, Tile(0, 0, TileType::Empty)))
    {
        for (int y = 0; y < h; ++y)
            for (int x = 0; x < w; ++x)
                grid[y][x] = Tile(x, y, TileType::Empty);
    }

    void setTile(int x, int y, TileType type) 
    {
        if (x >= 0 && x < width && y >= 0 && y < height)
            grid[y][x].type = type;
    }

    std::vector<Tile> findPath() 
    {
        std::pair<int, int> monsterPos, playerPos;
        bool monsterFound = false, playerFound = false;

        // Find monster and player positions
        for (int y = 0; y < height; ++y) 
        {
            for (int x = 0; x < width; ++x) 
            {
                if (grid[y][x].type == TileType::Monster) 
                {
                    monsterPos = { x, y };
                    monsterFound = true;
                }
                else if (grid[y][x].type == TileType::Player) 
                {
                    playerPos = { x, y };
                    playerFound = true;
                }
            }
        }

        if (!monsterFound || !playerFound) return {};

        std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));
        std::vector<std::vector<std::pair<int, int>>> parent(height, std::vector<std::pair<int, int>>(width, { -1, -1 }));

        // Min-heap (priority queue) to store nodes sorted by lowest f-cost
        std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;

        // Lambda for Euclidean heuristic
        auto heuristic = [](int x1, int y1, int x2, int y2) 
            {
            return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); // Euclidean distance
            };

        pq.push(Node(monsterPos.first, monsterPos.second, 0, heuristic(monsterPos.first, monsterPos.second, playerPos.first, playerPos.second)));
        visited[monsterPos.second][monsterPos.first] = true;

        // 8 Possible movements (including diagonals)
        int directions[8][2] = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}, // Cardinal directions
            {1, 1}, {-1, -1}, {1, -1}, {-1, 1} // Diagonal directions
        };

        // A* Search Algorithm
        while (!pq.empty()) 
        {
            Node current = pq.top();
            pq.pop();

            int x = current.x, y = current.y;
            if (x == playerPos.first && y == playerPos.second) break;

            for (auto& [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;

                if (nx >= 0 && nx < width && ny >= 0 && ny < height &&
                    !visited[ny][nx] && grid[ny][nx].type == TileType::Empty) {

                    double gNew = current.g + ((dx == 0 || dy == 0) ? 1 : 1.414); // Cost: 1 for straight, sqrt(2) for diagonal
                    double hNew = heuristic(nx, ny, playerPos.first, playerPos.second);
                    pq.push(Node(nx, ny, gNew, hNew));

                    visited[ny][nx] = true;
                    parent[ny][nx] = { x, y };
                }
            }
        }

        // Backtrack to get the path
        std::vector<Tile> path;
        std::pair<int, int> current = playerPos;

        while (current != monsterPos) 
        {
            auto [px, py] = parent[current.second][current.first];
            if (px == -1 && py == -1) return {}; // No valid path found
            path.push_back(grid[current.second][current.first]);
            current = { px, py };
        }

        std::reverse(path.begin(), path.end());
        return path;
    }
};






class PathFinderTest
{
public:

    PathFinderTest();
    ~PathFinderTest();
};
