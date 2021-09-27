// ADS101 Algoritmer og Datastrukturer for spill 2020
// Dag Nylund, Høgskolen i Innlandet

#include <iostream>
#include "plainrectangle.h"
using namespace std;

int main()
{
    Vector2d a{0, 0};
    Vector2d b{1, 0};
    Vector2d c{1, 1};
    Vector2d d{0, 1};

    PlainRectangle rect{a, b, c, d};
    rect.subDivide(a, b, c, d, 2);
    rect.print();
    return 0;
}
