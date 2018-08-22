#include "smartphone.h"

SmartPhone::SmartPhone()
{
    OS = "Android";
}

SmartPhone::SmartPhone(const QString newComp, const QString newName, const double newPrice, const double disc, const QString newOS) :Goods (newComp, newName, newPrice, disc)
{
    OS = newOS;
}


