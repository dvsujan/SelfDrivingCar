#include "headers/MapParser.hpp"
#include "headers/Car.hpp"
#include "headers/SensorManager.hpp"
#include <string>
#include <sstream>
#include <fstream> 
#include <vector>
#include<iostream> 

MapParser::MapParser(std::string mapPath)
{
    this->mapPath = mapPath;
    Vector2 bp1 = {120,55}; 
    Vector2 bp2 = {1116,55};
    Vector2 bp3 = {1116,635};
    Vector2 bp4 = {120,635};
    boundary.push_back(bp1);
    boundary.push_back(bp2);
    boundary.push_back(bp3);
    boundary.push_back(bp4);
    getMap();  
}

std::vector<std::string> split(std::string str, char delimiter)
{
    std::vector<std::string> internal;
    std::stringstream ss(str); // Turn the string into a stream.
    std::string tok;
    while(getline(ss, tok, delimiter))
    {
        internal.push_back(tok);
    }
    return internal; 
}

void MapParser::getMap()
{
    map.color = BLACK;
    std::ifstream file(mapPath);
    std::string line;
    while (std::getline(file, line))
    {
        std::vector<std::string> points = split(line, ' ');
        // for(int i = 0;  i< points.size(); i++){ 
        //     std::cout<<points[i]<<" ";
        // }
        // std::cout<< points[0]<<" "<<points[1] ; 
        float x = std::stof(points[0]);
        float y = std::stof(points[1]);
        map.points.push_back({x, y});
        // std::cout<< std::endl;  
    }
}

void MapParser::draw(){
    for(unsigned int i = 0; i < map.points.size()-1; i++){
        Vector2 start = {map.points[i].x, map.points[i].y};
        Vector2 end = {map.points[i+1].x, map.points[i+1].y};
        DrawLineEx(start, end,2, map.color);
    }
    Vector2 s= {map.points[map.points.size()-1].x, map.points[map.points.size()-1].y};
    Vector2 e = {map.points[0].x, map.points[0].y}; 
    DrawLineEx(s,e,2, map.color);
    //draw boundary lines
    for(unsigned int i = 0; i < boundary.size()-1; i++){
        Vector2 start = {boundary[i].x, boundary[i].y};
        Vector2 end = {boundary[i+1].x, boundary[i+1].y};
        DrawLineEx(start, end,4 ,map.color);
    }
    DrawLineEx(boundary[boundary.size()-1], boundary[0], 2, map.color);
}
 
std::vector<Vector2> MapParser::getMapAndBoundary(){
    //combine map and boundary
    std::vector<Vector2> mapAndBoundary;
    for(unsigned int i = 0; i < map.points.size(); i++){
        mapAndBoundary.push_back({map.points[i].x, map.points[i].y});
    }
    for(unsigned int i = 0; i < boundary.size(); i++){
        mapAndBoundary.push_back({boundary[i].x, boundary[i].y});
    }
    return mapAndBoundary;
}