#include "headers/Physics.hpp"
#include "headers/Car.hpp"
#include "raylib.h"
#include <iostream>

Physics::Physics() {}

// bool line_line(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4)
// {
//     // check line line collision and draw circle at intersectoin
//     float x1 = p1.x;
//     float y1 = p1.y;
//     float x2 = p2.x;
//     float y2 = p2.y;
//     float x3 = p3.x;
//     float y3 = p3.y;
//     float x4 = p4.x;
//     float y4 = p4.y;
//     float denom = (y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1);
//     float ua = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / denom;
//     float ub = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / denom;
//     if (ua > 0 && ua < 1 && ub > 0 && ub < 1)
//     {
//         DrawCircle(x1 + ua * (x2 - x1), y1 + ua * (y2 - y1), 5, GREEN);
//         return true;
//     }
//     return false;
// }

void Physics::MapSensorsDistance(std::vector<Sensor> lines, std::vector<Vector2> map)
{
    // check if lines collides with map using line line
    for (unsigned int i = 0; i < lines.size(); i++)
    {
        for (unsigned int j = 0; j < map.size(); j++)
        {
            float x1 = lines[i].start.x;
            float y1 = lines[i].start.y;
            float x2 = lines[i].end.x;
            float y2 = lines[i].end.y;
            float x3 = map[j].x;
            float y3 = map[j].y;
            float x4 = map[j + 1].x;
            float y4 = map[j + 1].y; 
            float denom = (y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1);
            float ua = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / denom;
            float ub = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / denom;
            if (ua > 0 && ua < 1 && ub > 0 && ub < 1)
            {
                DrawCircle(x1 + ua * (x2 - x1), y1 + ua * (y2 - y1), 8, RED);
            }
            
        }
    }
}