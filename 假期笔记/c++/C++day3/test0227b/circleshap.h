#ifndef CIRCLESHAP_H
#define CIRCLESHAP_H

#include "shap.h"

class CircleShap : public Shap
{
private:
    int r;
public:
    CircleShap(int r);
    int getPerimeter();
    string getType();
};

#endif // CIRCLESHAP_H
