#include "include/createlogin.h"
#include "ui_createlogin.h"
#include<QMessageBox>

CreateLogin::CreateLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateLogin)
{
    ui->setupUi(this);
}

CreateLogin::~CreateLogin()
{
    delete ui;
}

void CreateLogin::on_pushButton_createAccount_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    if (username != "" && password != ""){
        if (checkUsername(username) == true){ //Checks if username is present in usernames.txt
            QMessageBox::warning(this, "Create account failed", "Username already in use");
        }
        else if ((username.length() < 5 || username.length() > 20) && (password.length() < 5 || password.length() > 20)){
            QMessageBox::warning(this, "Create account failed", "Username and password must be between 5-20 characters");
        }
        else if (username.length() < 5 || username.length() > 20){ //Checks if username is wrong length
            QMessageBox::warning(this, "Create account failed", "Username must be between 5-20 characters");
        }
        else if (password.length() < 5 || password.length() > 20){ //Checks if password is wrong length
            QMessageBox::warning(this, "Create account failed", "Password must be between 5-20 characters");
        }
        else{
            storeLogin(username,password);
            QMessageBox::information(this, "Account created successfully", "Username and password stored");
            hide();
            userList = new UserList(this);
            //chatWindow->setWindowState(Qt::WindowMaximized);
            userList->show();
        }
    }
}
