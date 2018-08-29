#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    QString to_hash(QString passwd);
    ~Registration();

private slots:
    void on_okButton_clicked();

    void on_passwdEdit_textChanged(const QString &arg1);

    void on_reppassEdit_textChanged(const QString &arg1);

    void on_nameEdit_textChanged(const QString &arg1);

private:
    Ui::Registration *ui;
};

#endif // REGISTRATION_H
