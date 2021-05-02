/********************************************************************************
** Form generated from reading UI file 'userlist.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERLIST_H
#define UI_USERLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserList
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditHostname;
    QPushButton *pushButtonConnect;

    void setupUi(QDialog *UserList)
    {
        if (UserList->objectName().isEmpty())
            UserList->setObjectName(QString::fromUtf8("UserList"));
        UserList->resize(400, 300);
        verticalLayoutWidget = new QWidget(UserList);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(39, 9, 321, 241));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget = new QWidget(UserList);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 260, 381, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEditHostname = new QLineEdit(horizontalLayoutWidget);
        lineEditHostname->setObjectName(QString::fromUtf8("lineEditHostname"));

        horizontalLayout->addWidget(lineEditHostname);

        pushButtonConnect = new QPushButton(horizontalLayoutWidget);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));

        horizontalLayout->addWidget(pushButtonConnect);


        retranslateUi(UserList);

        QMetaObject::connectSlotsByName(UserList);
    } // setupUi

    void retranslateUi(QDialog *UserList)
    {
        UserList->setWindowTitle(QApplication::translate("UserList", "MQTT Messenger - Contacts", nullptr));
        lineEditHostname->setPlaceholderText(QApplication::translate("UserList", "Manually enter hostname...", nullptr));
        pushButtonConnect->setText(QApplication::translate("UserList", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserList: public Ui_UserList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLIST_H
