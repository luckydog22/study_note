#include "oneinstance.h"
#include <cstdio>

OneInstance* OneInstance::instance = NULL;

OneInstance *OneInstance::getInstance()
{
    if(instance == NULL)
    {
        instance = new OneInstance;
    }
    return instance;
}

void OneInstance::releaceInstance()
{
    if(instance!=NULL)
    {
        delete instance;
        instance = NULL;
    }
}

OneInstance::OneInstance()
{
    
}

OneInstance::OneInstance(const OneInstance &other)
{
    
}

