#ifndef CREATELOGIN_H
#define CREATELOGIN_H

#include <QDialog>
#include "userlist.h"

bool checkUsername(QString username);
void storeLogin(QString username,QString password);

namespace Ui {

class CreateLogin;
}

class CreateLogin : public QDialog
{
    Q_OBJECT

public:
    explicit CreateLogin(QWidget *parent = nullptr);
    ~CreateLogin();

private slots:
    void on_pushButton_createAccount_clicked();

private:
    Ui::CreateLogin *ui;
    UserList *userList;
};

#endif // CREATELOGIN_H
