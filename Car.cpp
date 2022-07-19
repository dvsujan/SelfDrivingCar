#include "headers/Car.hpp"
#include "headers/RectangleC.hpp"
#include <math.h>
#include "rlgl.h"
#include "headers/Sensor.h"
#include<vector> 

Car::Car(Vector2 carPos, Vector2 carSize, Color carColor)
{
    this->carPos = carPos;
    this->carSize = carSize;
    this->carColor = carColor;
}

void Car::show()
{
    // rlTranslatef(carPos.x, carPos.y, 0);    
    // rlRotatef(angle*50, 0, 0, -1);
    // DrawRectangle(carPos.x, carPos.y, carSize.x, carSize.y, carColor);
}

void Car::update()
{
    if (IsKeyDown(KEY_UP))
    {
        speed -= acceleration;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        speed += acceleration;
    }
    if (speed > maxSpeed)
    {
        speed = maxSpeed;
    }
    if (speed < -maxSpeed / 2)
    {
        speed = -maxSpeed / 2;
    }
    if (speed > 0)
    {
        speed -= friction;
    }
    if (speed < 0)
    {
        speed += friction;
    }
    if (abs(speed) < friction)
    {
        speed = 0;
    }
    if (speed != 0)
    {
        int flip = speed > 0 ? 1 : -1;
        if (IsKeyDown(KEY_LEFT))
        {
            angle -= 0.07 * flip;
        }
        if (IsKeyDown(KEY_RIGHT))
        {
            angle += 0.03 * flip;
        }
    }
    carPos.x += speed * sin(angle);
    carPos.y += speed * cos(angle);
    sensorManager.update(carPos,-angle);
    carRectangle.update({carPos.x-carSize.x/2, carPos.y-carSize.y/2}, carSize, angle);
}

Vector2 Car::getPos(){ return carPos;}

std::vector<Sensor> Car::getSensors(){ return sensorManager.getLines();}