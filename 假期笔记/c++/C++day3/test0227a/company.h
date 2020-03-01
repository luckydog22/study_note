#ifndef COMPANY_H
#define COMPANY_H

#include "developer.h"

class Company
{
public:
    Company();
    
    Developer* recruit();
    void work(Developer* dev);
};

#endif // COMPANY_H
