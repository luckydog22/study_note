#include "company.h"
#include "manito.h"
#include "smallbird.h"
#include <ctime>
#include <cstdlib>

Company::Company()
{
    srand(time(0));
}

Developer *Company::recruit()
{
    //����ָ��Developer *����ָ���������new Manito  new SmallBird
    switch(rand()%2)
    {
    case 0:
        return new Manito;
    case 1:
        return new SmallBird;
    }
}

void Company::work(Developer *dev)
{
    dev->develop();
}

