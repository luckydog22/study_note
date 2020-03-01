#ifndef ROUNDTABLE_H
#define ROUNDTABLE_H

#include "circle.h"
#include "table.h"

class RoundTable : public Circle, public Table
{
public:
    RoundTable(int r, string color, int height);
    void show();
};

#endif // ROUNDTABLE_H
