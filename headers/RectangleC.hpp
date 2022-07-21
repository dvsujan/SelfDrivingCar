#ifndef RECTANGLEC_HPP
#define RECTANGLEC_HPP
#include"raylib.h"
#include<vector>
//rectangle class from scratch using 4 points
class RectangleC
{
private:
    Vector2 p1;
    Vector2 p2;
    Vector2 p3;
    Vector2 p4;
    Vector2 Size;
    Color color = RED;
    float angle;
    void rotate(float angle);
    void show();
public:
    RectangleC();
    void update(Vector2 carPos,Vector2 size,float angle); 
    std::vector<Vector2> getPoints();
    void setColor(Color color);
};
#endif // RECTANGLE_HPP
