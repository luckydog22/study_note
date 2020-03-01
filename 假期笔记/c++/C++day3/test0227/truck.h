#ifndef TRUCK_H
#define TRUCK_H

#include "vehicle.h"

class Truck : public Vehicle
{
private:
    int passenger_load;
    int pay_load;
public:
    Truck(int wheels, int weight, int passenger_load, int pay_load);
    void show();
};

#endif // TRUCK_H
