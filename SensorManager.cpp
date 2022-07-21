#include "headers/SensorManager.hpp"
#include "raylib.h"
#include <math.h>
SensorManager::SensorManager()
{
    lines.push_back({{carPos.x, carPos.y}, {carPos.x, carPos.y + 100}, BLACK});
    lines.push_back({{carPos.x, carPos.y}, {carPos.x + 100, carPos.y + 100}, BLACK});
    lines.push_back({{carPos.x, carPos.y}, {carPos.x + 100, carPos.y}, BLACK});
    lines.push_back({{carPos.x, carPos.y}, {carPos.x +100, carPos.y -100}, BLACK});
    
    lines.push_back({{carPos.x, carPos.y}, {carPos.x, carPos.y - 100}, BLACK});
    lines.push_back({{carPos.x, carPos.y}, {carPos.x -100, carPos.y -100}, BLACK});
    lines.push_back({{carPos.x, carPos.y}, {carPos.x -100, carPos.y}, BLACK});
    lines.push_back({{carPos.x , carPos.y }, {carPos.x - 100, carPos.y + 100}, BLACK});
    // lines.push_back({{carPos.x + 10, carPos.y + 10}, {carPos.x + 10, carPos.y + 10}, BLACK});
}

void SensorManager::show()
{
    for (unsigned int i = 0; i < lines.size(); i++)
    {
        DrawLineEx(lines[i].start, lines[i].end,1, lines[i].color);
    }
}
void SensorManager::rotate(float angle){ 
    //rotate with respect to carPos
    for(unsigned int i = 0; i < lines.size(); i++){
        Vector2 start = {lines[i].start.x - carPos.x, lines[i].start.y - carPos.y};
        Vector2 end = {lines[i].end.x - carPos.x, lines[i].end.y - carPos.y};
        lines[i].start = {start.x * cos(angle) - start.y * sin(angle) + carPos.x, start.x * sin(angle) + start.y * cos(angle) + carPos.y};
        lines[i].end = {end.x * cos(angle) - end.y * sin(angle) + carPos.x, end.x * sin(angle) + end.y * cos(angle) + carPos.y};
    }
}

void SensorManager::update(Vector2 CarPos , float angle)
{
    this->carPos = CarPos; 
    lines[0].start = {carPos.x, carPos.y};
    lines[0].end = {carPos.x, carPos.y + 100};
    lines[1].start = {carPos.x, carPos.y};
    lines[1].end = {carPos.x + 100, carPos.y + 100};
    lines[2].start = {carPos.x, carPos.y};
    lines[2].end = {carPos.x + 100, carPos.y};
    lines[3].start = {carPos.x, carPos.y};
    lines[3].end = {carPos.x +100, carPos.y -100};

    lines[4].start = {carPos.x, carPos.y};
    lines[4].end = {carPos.x, carPos.y - 100};
    lines[5].start = {carPos.x, carPos.y};
    lines[5].end = {carPos.x -100, carPos.y -100};
    lines[6].start = {carPos.x, carPos.y};
    lines[6].end = {carPos.x -100, carPos.y};
    lines[7].start = {carPos.x , carPos.y };
    lines[7].end = {carPos.x - 100, carPos.y + 100};


    rotate(angle); 
    show();
}

std::vector<Sensor> SensorManager::getLines(){ 
    return lines;
}