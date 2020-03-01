#ifndef TABLE_H
#define TABLE_H

#include <string>

using namespace std;

class Table
{
protected:
    string color;
    int height;
public:
    Table(string color, int height);
};

#endif // TABLE_H
