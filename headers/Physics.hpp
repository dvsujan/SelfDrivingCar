#ifndef PHYSICS_HPP
#define PHYSICS_HPP
#include "raylib.h"
#include<vector>
#include"sensor.h"

class Physics{ 
private: 
public:
    Physics(); 
    // bool line_line(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4);
    void MapSensorsDistance(std::vector<Sensor> lines , std::vector<Vector2> map);
};

#endif // PHYSICS_HPP 