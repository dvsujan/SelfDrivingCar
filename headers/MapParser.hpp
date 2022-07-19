#ifndef MAPPARSER_HPP
#define MAPPARSER_HPP
#include "raylib.h"
#include <fstream>
#include <vector>
#include <string> //

struct pair
{
    float x;
    float y;
};

struct Map
{
    std::vector<pair> points;
    Color color;
};

class MapParser
{
private:
    std::string mapPath;
    Map map;
    std::vector<Vector2> boundary ;  
public:
    MapParser(std::string mapPath);
    void getMap();
    void draw();
    std::vector<Vector2> getMapAndBoundary();
};

#endif