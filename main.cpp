#include "raylib.h"
#include "headers/Car.hpp"
#include "headers/MapParser.hpp"
#include "headers/Physics.hpp"
#include "headers/Sensor.h"
#include "headers/FileHandler.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

int main()
{
    InitWindow(1200, 900, "Car Window");
    Vector2 p = {150, 570};
    Vector2 s = {20, 40};
    Color c = RED;
    Car car = Car(p, s, c);
    MapParser mapParser = MapParser("assets/map.txt");
    std::vector<Vector2> map = mapParser.getMapAndBoundary();
    std::vector<Sensor> sensors;
    Physics physics = Physics();
    std::ofstream filehandler("data_outputs.csv");
    filehandler << "Gas,Brake,steerLeft,steerRight,FrontSensor,frontLeftSensor,LeftSensor,BackLeftSensor,BackSensor,BackRightSensor,RightSensor,frontRightSensor" << std::endl;
    // FileHandler fileHandler = FileHandler("./data/sensor_input.csv","Gas,Brake,steerLeft,steerRight,FrontSensor,frontLeftSensor,LeftSensor,BackLeftSensor,BackSensor,BackRightSensor,RightSensor,frontRightSensor");
    SetTargetFPS(60);

    std::vector<float> distances;
    std::vector<Vector2> carPoints;
    int *inputs = new int[4];
    for (int i = 0; i < 4; i++)
    {
        inputs[i] = 0;
    }
    int x = 1;
    while (!WindowShouldClose())
    {
        BeginDrawing();
        DrawFPS(10, 10);
        DrawText("AI CAR", 560, 290, 40, RED);
        DrawText("Press 'R' to record input and sensor data", 450, 340, 20, RED);
        ClearBackground(WHITE);
        sensors = car.getSensors();
        distances = physics.MapSensorsDistance(sensors, map);
        inputs = car.getInputs();
        // std::cout<<"Gas: "<<inputs[0]<<" Brake: "<<inputs[1]<<" steerLeft: "<<inputs[2]<<" steerRight: "<<inputs[3]<<std::endl;
        // draw distances on screen 8 seprate texts
        std::string s1d = "SENSOR1: " + std::to_string(distances[0]);
        std::string s2d = "SENSOR2: " + std::to_string(distances[1]);
        std::string s3d = "SENSOR3: " + std::to_string(distances[2]);
        std::string s4d = "SENSOR4: " + std::to_string(distances[3]);
        std::string s5d = "SENSOR5: " + std::to_string(distances[4]);
        std::string s6d = "SENSOR6: " + std::to_string(distances[5]);
        std::string s7d = "SENSOR7: " + std::to_string(distances[6]);
        std::string s8d = "SENSOR8: " + std::to_string(distances[7]);

        DrawText(s1d.c_str(), 150, 704, 20, GREEN);
        DrawText(s2d.c_str(), 400, 704, 20, GREEN);
        DrawText(s3d.c_str(), 620, 704, 20, GREEN);
        DrawText(s4d.c_str(), 850, 704, 20, GREEN);
        DrawText(s5d.c_str(), 150, 800, 20, GREEN);
        DrawText(s6d.c_str(), 400, 800, 20, GREEN);
        DrawText(s7d.c_str(), 620, 800, 20, GREEN);
        DrawText(s8d.c_str(), 850, 800, 20, GREEN);
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        car.update();
        mapParser.draw();
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // write all inputs and sensor data to file
        // write to file only while x%2 == 0 and increment when ctrl+r is pressed
        if (x % 2 == 0)
        {
            std::string outputText = std::to_string(inputs[0]) + "," + std::to_string(inputs[1]) + "," + std::to_string(inputs[2]) + "," + std::to_string(inputs[3]) + "," + std::to_string(distances[0]) + "," + std::to_string(distances[1]) + "," + std::to_string(distances[2]) + "," + std::to_string(distances[3]) + "," + std::to_string(distances[4]) + "," + std::to_string(distances[5]) + "," + std::to_string(distances[6]) + "," + std::to_string(distances[7]);
            filehandler << outputText << std::endl;
            DrawText("Recording...", 1000, 10, 20, RED);
        }
        if(IsKeyPressed(KEY_R))
        {
            x = x+1 ; 
        }
        std::cout << x << std::endl;
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::string carposs = "CarCoordinates "
                              "x:" +
                              std::to_string(car.getPos().x) + ", y:" + std::to_string(car.getPos().y);

        std::string carang = "CarAngle " + std::to_string(car.getAngle());

        std::string carspeed = "CarSpeed " + std::to_string(car.getSpeed());

        DrawText(carposs.c_str(), 100, 10, 20, BLACK);
        DrawText(carang.c_str(), 100, 30, 20, BLACK);
        DrawText(carspeed.c_str(), 600, 10, 20, BLACK);
        EndDrawing();
    }
    // fileHandler.close();
    filehandler.close();
    std::cout<< "file closed Successfully"<<std::endl; 
    CloseWindow();
    return 0;
}