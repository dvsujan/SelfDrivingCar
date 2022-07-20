#include "raylib.h"
#include "headers/Car.hpp"
#include "headers/MapParser.hpp"
#include "headers/Physics.hpp"
#include "headers/Sensor.h"
#include <vector>
#include<string> 

int main()
{
    InitWindow(1200, 700, "Car Window");
    Vector2 p = {150, 570} ; 
    Vector2 s = {20,40} ; 
    Color c = RED ; 
    Car car = Car(p, s, c);
    MapParser mapParser = MapParser("assets/map.txt");
    std::vector<Vector2> map = mapParser.getMapAndBoundary();
    std::vector<Sensor> sensors ;   
    SetTargetFPS(60);
    Physics physics = Physics(); 
    //printing the sensors and map to check if they are correct
    // for (unsigned int i = 0; i < sensors.size(); i++)
    // {
    //     DrawLine(sensors[i].start.x, sensors[i].start.y, sensors[i].end.x, sensors[i].end.y, GREEN);
    // }
    // for (unsigned int i = 0; i < map.size(); i++)
    // {
    //     DrawCircle(map[i].x, map[i].y, 5, GREEN);
    // }

    while (!WindowShouldClose())
    {
        BeginDrawing();
        DrawFPS(10, 10);
        DrawText("AI CAR", 560, 290, 40, RED); 
        ClearBackground(WHITE);
        sensors = car.getSensors();
        physics.MapSensorsDistance(sensors, map); 
        car.update();
        mapParser.draw();
        std::string carposs = "CarCoordinates " "x:"+std::to_string(car.getPos().x)+", y:"+std::to_string(car.getPos().y); 
        DrawText(carposs.c_str(),100,10,20,BLACK); 
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}