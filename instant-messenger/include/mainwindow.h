#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "userlist.h"
#include "createlogin.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

bool checkLogin(QString username, QString password);

extern QString username;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_login_clicked();
    void on_pushButton_createAccount_clicked();

private:
    Ui::MainWindow *ui;
    CreateLogin *createLogin;
    UserList *userList;
};

#endif // MAINWINDOW_H
