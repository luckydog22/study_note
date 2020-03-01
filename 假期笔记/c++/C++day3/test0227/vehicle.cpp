#include "vehicle.h"


Vehicle::Vehicle(int wheels, int weight):
    wheels(wheels),
    weight(weight)
{
    
}

void Vehicle::show()
{
    cout<<wheels<<" "<<weight<<endl;   
}
