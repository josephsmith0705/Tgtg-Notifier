#include "include/userlist.h"
#include "ui_userlist.h"
#include <fstream>

UserList::UserList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserList)
{
    ui->setupUi(this);
    createButtons();
}

UserList::~UserList()
{
    delete ui;
}

void UserList::createButtons()
{
    std::vector<std::string> users = readFile("users.txt");
    std::vector<std::string> names = readFile("names.txt");
    //Creates a loop which makes a button for every ip address stored in users.txt
    for (int i=0; i<users.size();i++){
        auto button = new QPushButton(QString::fromUtf8(names[i].c_str()), this); //Creates the button with the text of the name from names.txt
        QObject::connect(button, &QPushButton::clicked, [=]() {
                    chatWindow = new ChatWindow(this, QString::fromUtf8(users[i].c_str())); //Each button will open chatWindow and pass the IP from users.txt
                    chatWindow->show();
                });
        ui->verticalLayout->addWidget(button); //Places the buttons in the GUI on the vertical layout
    }
}

void UserList::on_pushButtonConnect_clicked() //This is used for inputting a new IP address
{
    if (ui->lineEditHostname->text() != ""){
        chatWindow = new ChatWindow(this, ui->lineEditHostname->text());
        chatWindow->show();
    }
}


