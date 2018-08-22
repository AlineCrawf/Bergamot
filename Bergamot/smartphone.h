#ifndef SMARTPHONE_H
#define SMARTPHONE_H
#include "goods.h"

class SmartPhone : public Goods
{
private:
    QString OS;
public:
    SmartPhone();
    SmartPhone(const QString newComp, const QString newName, const double newPrice, const double disc,const QString newOS);
};

#endif // SMARTPHONE_H
