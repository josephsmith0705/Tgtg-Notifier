/********************************************************************************
** Form generated from reading UI file 'chatwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW_H
#define UI_CHATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ChatWindow
{
public:
    QGroupBox *groupBox;
    QPushButton *buttonPublish;
    QLineEdit *lineEditMessage;
    QPlainTextEdit *editLog;

    void setupUi(QDialog *ChatWindow)
    {
        if (ChatWindow->objectName().isEmpty())
            ChatWindow->setObjectName(QString::fromUtf8("ChatWindow"));
        ChatWindow->resize(600, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChatWindow->sizePolicy().hasHeightForWidth());
        ChatWindow->setSizePolicy(sizePolicy);
        ChatWindow->setMinimumSize(QSize(600, 600));
        ChatWindow->setMaximumSize(QSize(99999, 99999));
        groupBox = new QGroupBox(ChatWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 581, 591));
        buttonPublish = new QPushButton(groupBox);
        buttonPublish->setObjectName(QString::fromUtf8("buttonPublish"));
        buttonPublish->setGeometry(QRect(488, 520, 71, 61));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonPublish->sizePolicy().hasHeightForWidth());
        buttonPublish->setSizePolicy(sizePolicy1);
        lineEditMessage = new QLineEdit(groupBox);
        lineEditMessage->setObjectName(QString::fromUtf8("lineEditMessage"));
        lineEditMessage->setGeometry(QRect(10, 524, 471, 51));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEditMessage->sizePolicy().hasHeightForWidth());
        lineEditMessage->setSizePolicy(sizePolicy2);
        editLog = new QPlainTextEdit(groupBox);
        editLog->setObjectName(QString::fromUtf8("editLog"));
        editLog->setGeometry(QRect(10, 30, 551, 481));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(editLog->sizePolicy().hasHeightForWidth());
        editLog->setSizePolicy(sizePolicy3);

        retranslateUi(ChatWindow);

        QMetaObject::connectSlotsByName(ChatWindow);
    } // setupUi

    void retranslateUi(QDialog *ChatWindow)
    {
        ChatWindow->setWindowTitle(QApplication::translate("ChatWindow", "MQTT Messenger - Chat", nullptr));
        groupBox->setTitle(QString());
        buttonPublish->setText(QApplication::translate("ChatWindow", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWindow: public Ui_ChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
