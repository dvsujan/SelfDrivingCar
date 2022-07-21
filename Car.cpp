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
    for(int i = 0 ; i<4 ; i++){ 
        inputs[i] = 0;
    }
}

void Car::show()
{
    // rlTranslatef(carPos.x, carPos.y, 0);    
    // rlRotatef(angle*50, 0, 0, -1);
    // DrawRectangle(carPos.x, carPos.y, carSize.x, carSize.y, carColor);
}

void Car::update()
{
    for(int i =0 ;i<4 ;i++){
        inputs[i] = 0;
    }
    if (IsKeyDown(KEY_UP))
    {
        speed += acceleration;
        inputs[0] = 1;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        speed -= acceleration;
        inputs[1] = 1; 
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
            angle += 0.03 * flip;
            inputs[2] = 1; 
        }
        if (IsKeyDown(KEY_RIGHT))
        {
            angle -= 0.03 * flip;
            inputs[3] = 1; 
        }
    }
    carPos.x += speed * sin(angle);
    carPos.y += speed * cos(angle);
    sensorManager.update(carPos,-angle);
    carRectangle.update({carPos.x-carSize.x/2, carPos.y-carSize.y/2}, carSize, -angle);
}

Vector2 Car::getPos(){ return carPos;}
float Car::getSpeed(){ return speed;}
float Car::getAngle(){ 
    //angle should be between 0 and 180
    if(angle > 180){
        angle = angle - 360;
    }
    if(angle < -180){
        angle = angle + 360;
    }
    return angle;

}
std::vector<Sensor> Car::getSensors(){ return sensorManager.getLines();}
std::vector<Vector2> Car::getCarRectPoints(){ return carRectangle.getPoints();}
void Car::stopMoving(){ speed = 0;}
void Car::setCarColor(Color carColor){ carRectangle.setColor(carColor); }

int* Car::getInputs(){ return inputs;} 