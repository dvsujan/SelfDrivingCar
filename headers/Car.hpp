#ifndef CAR_HPP
#define CAR_HPP
#include<raylib.h>
#include"SensorManager.hpp"
#include "Sensor.h"
#include "RectangleC.hpp"
#include<vector> //
class Car{ 
private: 
    Vector2 carPos  ; 
    Vector2 carSize ; 
    Color carColor;  
    float speed = 0 ;
    float acceleration = 0.2 ; 
    float maxSpeed = 5 ;
    float friction = 0.05 ;
    float angle = 0 ; 
    void show();
    SensorManager sensorManager;
    RectangleC carRectangle;
    int inputs[4];
public:
    Car(){ 
    }
    Car(Vector2 carPos , Vector2 carSize , Color carColor);
    void update(); 
    Vector2 getPos() ;
    float getSpeed() ;
    float getAngle() ;
    std::vector<Sensor> getSensors();
    std::vector<Vector2> getCarRectPoints();
    void stopMoving();
    void setCarColor(Color carColor);
    int* getInputs();
};
#endif // CAR_HPP 