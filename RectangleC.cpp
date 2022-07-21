#include"headers/RectangleC.hpp"
#include"raylib.h"
#include<math.h> 

RectangleC::RectangleC()
{
    this->p1 = {0, 0};
    this->p2 = {0, 0};
    this->p3 = {0, 0};
    this->p4 = {0, 0};  
    this->Size = {100, 100};
}

void RectangleC::rotate(float angle)
{
    float x1 = p1.x;
    float y1 = p1.y;
    float x2 = p2.x;
    float y2 = p2.y;
    float x3 = p3.x;
    float y3 = p3.y;
    float x4 = p4.x;
    float y4 = p4.y;
    float x = (x1 + x2 + x3 + x4) / 4;
    float y = (y1 + y2 + y3 + y4) / 4;
    float newX1 = x + (x1 - x) * cos(angle) - (y1 - y) * sin(angle);
    float newY1 = y + (x1 - x) * sin(angle) + (y1 - y) * cos(angle);
    float newX2 = x + (x2 - x) * cos(angle) - (y2 - y) * sin(angle);
    float newY2 = y + (x2 - x) * sin(angle) + (y2 - y) * cos(angle);
    float newX3 = x + (x3 - x) * cos(angle) - (y3 - y) * sin(angle);
    float newY3 = y + (x3 - x) * sin(angle) + (y3 - y) * cos(angle);
    float newX4 = x + (x4 - x) * cos(angle) - (y4 - y) * sin(angle);
    float newY4 = y + (x4 - x) * sin(angle) + (y4 - y) * cos(angle);
    p1.x = newX1;
    p1.y = newY1;
    p2.x = newX2;
    p2.y = newY2;
    p3.x = newX3;
    p3.y = newY3;
    p4.x = newX4;
    p4.y = newY4;
}
void RectangleC::show()
{
    DrawLineEx(p1,p2,2,color);
    DrawLineEx(p2,p3,2,color);
    DrawLineEx(p3,p4,2,color);
    DrawLineEx(p4,p1,2,color);
}

void RectangleC::update(Vector2 carPos,Vector2 size,float angle)
{
    this->Size = size ; 
    this->p1 = carPos;
    this->p2 = {carPos.x + Size.x, carPos.y};
    this->p3 = {carPos.x + Size.x, carPos.y + Size.y};
    this->p4 = {carPos.x, carPos.y + Size.y};
    this->angle = angle;
    this->rotate(angle);
    show(); 
}
std::vector<Vector2> RectangleC::getPoints()
{
    std::vector<Vector2> points;
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);
    return points;
}
void RectangleC::setColor(Color color)
{
    this->color = color;
}