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
    float maxSpeed = 10 ;
    float friction = 0.05 ;
    float angle = 0 ; 
    void show();
    SensorManager sensorManager;
    RectangleC carRectangle;
public:
    Car(){ 
    }
    Car(Vector2 carPos , Vector2 carSize , Color carColor);
    void update(); 
    Vector2 getPos() ;
    std::vector<Sensor> getSensors();
};
#endif // CAR_HPP 