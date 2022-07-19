#include "headers/Physics.hpp"
#include "headers/Car.hpp"
#include"raylib.h"
#include<iostream>

Physics::Physics() {}

bool line_line(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4)
{
    float x1 = p1.x;
    float y1 = p1.y;

    float x2 = p2.x;
    float y2 = p2.y;

    float x3 = p3.x;
    float y3 = p3.y;

    float x4 = p4.x;
    float y4 = p4.y;

    float uA = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
    float uB = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
    if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1)
    {

        float intersectionX = x1 + (uA * (x2 - x1));
        float intersectionY = y1 + (uA * (y2 - y1));
        DrawCircle(intersectionX, intersectionY, 5, GREEN);
        return true;
    }
    return false;
}

// void Physics::checkCollision(std::vector<Sensor>lines, std::vector<Vector2> map)
// {
//     //check collison for all the lines in the map
//     for (unsigned int i = 0; i < map.size(); i++)
//     {
//         for (unsigned int j = 0; j < lines.size(); j++)
//         {
//             if (line_line(lines[j].start, lines[j].end, map[i], map[i + 1]))
//             {
//                 std::cout << "collision" << std::endl;
//             }
//         }
//     }
// }