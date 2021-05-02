#include "include/chatwindow.h"
#include "ui_chatwindow.h"
#include "include/mainwindow.h"

#include <QtCore/QDateTime>
#include <QtMqtt/QMqttClient>
#include <QtWidgets/QMessageBox>
#include <thread>
#include <chrono>

ChatWindow::ChatWindow(QWidget *parent, QString hostname) :
    QDialog(parent),
    ui(new Ui::ChatWindow)
{
    ui->setupUi(this);

    mqtt_client = new QMqttClient(this);
    mqtt_client->setHostname(hostname); //The hostname is set using the hostname passed from userlist, selected by the user
    mqtt_client->setPort(1883);

    //Assign slots to different signals from mqtt client
    connect(mqtt_client, &QMqttClient::connected,this, &ChatWindow::brokerConnected);
    connect(mqtt_client, &QMqttClient::stateChanged, this, &ChatWindow::updateLogStateChange);
    connect(mqtt_client, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const
            QMqttTopicName &topic){
        const QString content = QLatin1Char('\n')
                +QDateTime::currentDateTime().toString()
                +QLatin1Char('\n')
                +message
                +QLatin1Char('\n');
        ui->editLog->insertPlainText(content);
    });
    updateLogStateChange();
    mqtt_client->connectToHost();
    //Create a timer, link it's finish to a slot, and start the timer at 1000 milliseconds. This will later be used to check inactivity every second
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),
              this, SLOT(timerSlot()));
    timer->start(1000);
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

void ChatWindow::updateLogStateChange()
{
    //Inserts text into editLog to inform the user of any state changes from the mqtt connection
    if (mqtt_client->state() == 0){
        ui->editLog->insertPlainText(QDateTime::currentDateTime().toString()
                +QLatin1String("\nDisconnected\n"));
    }
    else if (mqtt_client->state() == 1){
        ui->editLog->insertPlainText(QDateTime::currentDateTime().toString()
                +QLatin1String("\nConnecting...\n"));
    }
    else if (mqtt_client->state() == 2){
        ui->editLog->insertPlainText(QDateTime::currentDateTime().toString()
                +QLatin1String("\nConnected\n"));
    }
}

void ChatWindow::on_buttonPublish_clicked()
{
    extern QString username;
    QString topic = "topic1"; //This should be changed in the future to allow for group chats, identified by their topic
    QString message = username+": "+ui->lineEditMessage->text();
    if (mqtt_client->publish(topic, message.toUtf8())== -1)
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
    ui->lineEditMessage->setText("");
}

void ChatWindow::brokerConnected()
{
    QString topic = "topic1"; //This should be changed in the future to allow for group chats, identified by their topic

    auto subscription = mqtt_client->subscribe(topic);
    if (!subscription){
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
        return;
    }
}

void ChatWindow::timerSlot()
{
    /*
    //hide(); Currently the timer hides the chat window x seconds after the window opens - instead, it should measure inactivity
    QMessageBox::critical(this, QLatin1String("Bump"), QLatin1String("Hello! Are you active?"));
    bool running = true;
    while (running = true){
        //Check whether the system is idle for too long
        timer->start(1000);
    }*/

}
