#include "headers/Physics.hpp"
#include "headers/Car.hpp"
#include "raylib.h"
#include <iostream>
#include<math.h> 

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
float Distance(float p1, float p2, float p3 , float p4){ 
    return sqrt(pow(p1 - p3, 2) + pow(p2 - p4, 2)); 
}

std::vector<float> Physics::MapSensorsDistance(std::vector<Sensor> lines, std::vector<Vector2> map)
{
    std::vector<float> distances(8);
    //
    // for (unsigned int i = 0; i < lines.size(); i++)
    // {
    //     for (unsigned int j = 0; j < map.size(); j++)
    //     {
    //         float x1 = lines[i].start.x;
    //         float y1 = lines[i].start.y;
    //         float x2 = lines[i].end.x;
    //         float y2 = lines[i].end.y;
    //         float x3 = map[j].x;
    //         float y3 = map[j].y;
    //         float x4 = map[j + 1].x;
    //         float y4 = map[j + 1].y; 
    //         float denom = (y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1);
    //         float ua = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / denom;
    //         float ub = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / denom;

    //         if (ua > 0 && ua < 1 && ub > 0 && ub < 1)
    //         {
    //             DrawCircle(x1 + ua * (x2 - x1), y1 + ua * (y2 - y1), 8, RED);
    //             distances.push_back(Distance(x1 + ua * (x2 - x1), y1 + ua * (y2 - y1), x3, y3));
    //         }

    //     }
    // }
    //store all the distances from lines to map in distances vector according to their index in lines vector if they are not insert 0
    for(unsigned int i = 0 ; i< distances.size(); i++){ 
        distances[i] = 0;
    }
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
                distances[i] = Distance(x1 + ua * (x2 - x1), y1 + ua * (y2 - y1), x3, y3); 
            }

        }
    }

    return distances ; 
}

bool Physics::CarMap(std::vector<Vector2> car, std::vector<Vector2> map)
{
   //check using line line collision if the car is in the map car is a 4 pointed rectangle 
    //and map is a polygon
    //check if car is colliding with the map 
    //if it is colliding return true else return false
    for (unsigned int i = 0; i < car.size(); i++)
    {
       //check for collision without using loop 
        float x1 = car[i].x;
        float y1 = car[i].y;
        float x2 = car[i + 1].x;
        float y2 = car[i + 1].y;
        float x3 = map[0].x;
        float y3 = map[0].y;
        float x4 = map[1].x;
        float y4 = map[1].y; 
        float denom = (y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1);
        float ua = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / denom;
        float ub = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / denom;
        if (ua > 0 && ua < 1 && ub > 0 && ub < 1)
        {
            
            return true;
        } 
    }
    return false;
}