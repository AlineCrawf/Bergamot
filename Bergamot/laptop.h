#ifndef LAPTOP_H
#define LAPTOP_H
#include "QString"
#include "goods.h"

class Laptop : public Goods
{
private:
    double Diagonal;
    double Weight;
    QString Processor;
    int Memory;
public:
    Laptop();
    Laptop(const QString newComp, const QString newName, const double newPrice, const double disc, const double diagonal, const double weight, const QString proc, const int mem);
};

#endif // LAPTOP_H
