#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

class Car : public Vehicle
{
private:
    int passenger_load ;
public:
    Car(int wheels, int weight, int passenger_load);
    void show();
};

#endif // CAR_H
