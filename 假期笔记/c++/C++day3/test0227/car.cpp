#include "car.h"


Car::Car(int wheels, int weight, int passenger_load):
    Vehicle(wheels, weight),
    passenger_load(passenger_load)
{
    
}

void Car::show()
{
    Vehicle::show();//���ø����show
    cout<<passenger_load<<endl;
}
