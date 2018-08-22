#ifndef GOODS_H
#define GOODS_H
#include <QString>
#include <QList>

class Goods
{
protected:
   // QList <Goods*> list_of_goods;
    QString company;
    QString name;//model
    double price;
    double max_discount;
public:
    Goods();

    Goods(const QString newComp, const QString newName, const double newPrice, const double disc);

    virtual double getMaxDisc() const;
    virtual double getPrice() const;
    virtual ~Goods() {}

};
#endif // GOODS_H
