#include "goods.h"

Goods::Goods()
{
    company = "Company inc";
    name = "Product";
    price = 0;
    max_discount = 0;
}


Goods::Goods(const QString newComp, const QString newName, const double newPrice, const double disc)
{
    company = newComp;
    name = newName;
    price = newPrice;
    max_discount = disc;
}

double Goods::getMaxDisc() const
{
    return this->max_discount;
}

double Goods::getPrice() const
{
    return this->price;
}

