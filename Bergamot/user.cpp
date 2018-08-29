#include "user.h"
#include<QTextStream>

User::User()
{
    this->Name = "";
    this->TotalSum = 0;
}

User::User(QString name, double newTotalSum)
{
    this->Name = name;
    this->TotalSum = newTotalSum;
}

void User::AddToBuyList(QString newGoods)
{
    QTextStream fout(this->buyList);
    fout<<newGoods<<"\r\n";
}

QString User::Info()
{
    return this->Name+" "+QString::number(this->TotalSum);
}
