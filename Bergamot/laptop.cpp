#include "laptop.h"
#include "goods.h"
#include <QString>


Laptop::Laptop(const QString newComp, const QString newName, const double newPrice, const double disc, const double diagonal, const double weight, const QString proc, const int mem) :Goods(newComp, newName, newPrice, disc)
{
    Diagonal = diagonal;
    Weight = weight;
    Processor = proc;
    Memory = mem;
}

inline Laptop::Laptop()
{
    Diagonal = 17.3;
    Weight = 2.69;
    Processor = "Intel";
    Memory = 500;
}
