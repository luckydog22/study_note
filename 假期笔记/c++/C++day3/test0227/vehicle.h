#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

using namespace std;

class Vehicle
{
private:
    int wheels;
    int weight;
public:
    Vehicle(int wheels, int weight);
    void show();
};

#endif // VEHICLE_H
