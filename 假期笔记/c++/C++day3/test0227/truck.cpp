#include "truck.h"


Truck::Truck(int wheels, int weight, int passenger_load, int pay_load):
    Vehicle(wheels, weight),
    passenger_load(passenger_load),
    pay_load(pay_load)
{
    
}

void Truck::show()
{
    Vehicle::show();
    cout<<passenger_load<<" "<<pay_load<<endl;
}
