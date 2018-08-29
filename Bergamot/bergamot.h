#ifndef BERGAMOT_H
#define BERGAMOT_H

#include <QMainWindow>
#include <user.h>

namespace Ui {
class Bergamot;
}

class Bergamot : public QMainWindow
{
    Q_OBJECT

public:
    explicit Bergamot(QWidget *parent = nullptr);
    ~Bergamot();

private slots:
    void on_registButton_clicked();

    void on_loginButton_clicked();

private:
    Ui::Bergamot *ui;
};

#endif // BERGAMOT_H
