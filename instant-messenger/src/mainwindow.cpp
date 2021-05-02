#include "include/mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <fstream>

QString username;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{

    delete ui;

}

void MainWindow::on_pushButton_login_clicked()
{
    username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text(); //Stores values of lineEdit as QStrings once button is pushed
    if (username != "" && password != ""){
        if (checkLogin(username, password) == true){ //Checks that the username and password match the stored usernames and passwords
            hide();
            userList = new UserList(this);
            userList->show();
        }
        else {
            QMessageBox::warning(this, "Login Failed", "Username and password do not match");
        }
    }
}

void MainWindow::on_pushButton_createAccount_clicked()
{
    hide();
    createLogin = new CreateLogin(this);
    createLogin->show();
}
