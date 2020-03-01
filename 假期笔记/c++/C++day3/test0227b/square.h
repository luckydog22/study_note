#ifndef SQUARE_H
#define SQUARE_H

#include "shap.h"

class Square : public Shap
{
private:
    int a;
public:
    Square(int a);
    int getPerimeter();
    string getType();
};

#endif // SQUARE_H
