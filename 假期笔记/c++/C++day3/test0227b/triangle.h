#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shap.h"

class Triangle : public Shap
{
private:
    int a;
    int b;
    int c;
public:
    Triangle(int a, int b, int c);
    int getPerimeter();
    string getType();
};

#endif // TRIANGLE_H
