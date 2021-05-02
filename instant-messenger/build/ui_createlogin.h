/********************************************************************************
** Form generated from reading UI file 'createlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATELOGIN_H
#define UI_CREATELOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateLogin
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *lineEdit_username;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *lineEdit_password;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_createAccount;
    QLabel *label;

    void setupUi(QDialog *CreateLogin)
    {
        if (CreateLogin->objectName().isEmpty())
            CreateLogin->setObjectName(QString::fromUtf8("CreateLogin"));
        CreateLogin->resize(500, 250);
        CreateLogin->setMaximumSize(QSize(500, 250));
        groupBox = new QGroupBox(CreateLogin);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(80, 40, 341, 151));
        groupBox->setAlignment(Qt::AlignCenter);
        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(50, 30, 241, 66));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font;
        font.setPointSize(9);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_4);

        lineEdit_username = new QLineEdit(layoutWidget_2);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_username->sizePolicy().hasHeightForWidth());
        lineEdit_username->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(lineEdit_username);


        horizontalLayout_3->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_5);

        lineEdit_password = new QLineEdit(layoutWidget_2);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        sizePolicy.setHeightForWidth(lineEdit_password->sizePolicy().hasHeightForWidth());
        lineEdit_password->setSizePolicy(sizePolicy);
        lineEdit_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_6->addWidget(lineEdit_password);


        horizontalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(80, 100, 181, 41));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        pushButton_createAccount = new QPushButton(horizontalLayoutWidget);
        pushButton_createAccount->setObjectName(QString::fromUtf8("pushButton_createAccount"));
        pushButton_createAccount->setFont(font);

        horizontalLayout_7->addWidget(pushButton_createAccount);

        label = new QLabel(CreateLogin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 270, 241, 41));

        retranslateUi(CreateLogin);

        QMetaObject::connectSlotsByName(CreateLogin);
    } // setupUi

    void retranslateUi(QDialog *CreateLogin)
    {
        CreateLogin->setWindowTitle(QApplication::translate("CreateLogin", "MQTT Messenger - New Account", nullptr));
        groupBox->setTitle(QApplication::translate("CreateLogin", "Create Account", nullptr));
        label_4->setText(QApplication::translate("CreateLogin", "Username", nullptr));
        label_5->setText(QApplication::translate("CreateLogin", "Password", nullptr));
        pushButton_createAccount->setText(QApplication::translate("CreateLogin", "Create Account", nullptr));
        label->setText(QApplication::translate("CreateLogin", "Username requirements:\n"
"-Must be unique\n"
"-Must be between 5-20 characters", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateLogin: public Ui_CreateLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATELOGIN_H
