#ifndef SENSORMANAGER_HPP
#define SENSORMANAGER_HPP

#include"raylib.h"
#include<vector> 
#include "Sensor.h"
class SensorManager{ 
private:
    std::vector<Sensor> lines;
    Vector2 carPos = {0,0};
    void show(); 
    void rotate(float angle); 
public:
    SensorManager();  
    void update(Vector2 CarPos, float angle);
    std::vector<Sensor> getLines(); 
}; 

#endif // SENSORMANAGER_HPP