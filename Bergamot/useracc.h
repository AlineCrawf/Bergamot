#ifndef USERACC_H
#define USERACC_H

#include <QDialog>

namespace Ui {
class UserAcc;
}

class UserAcc : public QDialog
{
    Q_OBJECT

public:
    explicit UserAcc(QWidget *parent = nullptr);
    ~UserAcc();

private:
    Ui::UserAcc *ui;
};

#endif // USERACC_H
