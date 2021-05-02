#ifndef USERLIST_H
#define USERLIST_H

#include <QDialog>
#include "chatwindow.h"

std::vector<std::string> readFile (std::string filename);

namespace Ui {
class UserList;

std::vector<QString> readFile(QString filename);
}

class UserList : public QDialog
{
    Q_OBJECT

public:
    explicit UserList(QWidget *parent = nullptr);
    ~UserList();

private slots:
    void on_pushButtonConnect_clicked();

    void createButtons();

private:
    Ui::UserList *ui;
    ChatWindow *chatWindow;
    QPushButton *button;

};

#endif // USERLIST_H
