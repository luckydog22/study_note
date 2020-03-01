#ifndef SHAP_H
#define SHAP_H

#include <string>

using namespace std;

class Shap
{
public:
    virtual int getPerimeter() = 0;
    virtual string getType() = 0;
};

#endif // SHAP_H
