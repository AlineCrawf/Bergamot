#ifndef USER_H
#define USER_H

#include <QString>
#include <QFile>

class User
{
public:
    User();
    User (QString name,double TotalSum);
    void AddToBuyList(QString newGoods);
    QString Info();
private:
    QString Name;
    QFile *buyList = new QFile("E:\\Programming\\Bergamot\\Bergamot\\BuyList");
    double TotalSum;

};

#endif // USER_H
