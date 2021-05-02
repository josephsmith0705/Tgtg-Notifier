#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QDialog>
#include <QMqttClient>
#include <QTimer>

namespace Ui {
class ChatWindow;

}

class ChatWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = nullptr, QString hostname = "");
    ~ChatWindow();
    QTimer *timer;

public slots:
    void timerSlot();

private slots:
    void updateLogStateChange();

    void on_buttonPublish_clicked();

    void brokerConnected();

private:
    Ui::ChatWindow *ui;
    QMqttClient *mqtt_client;
};

#endif // CHATWINDOW_H
