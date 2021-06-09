#ifndef GUIPANEL_H
#define GUIPANEL_H

#include <QWidget>
#include <QtSerialPort/qserialport.h>
#include "qmqtt.h"

namespace Ui {
class GUIPanel;
}

class GUIPanel : public QWidget
{
    Q_OBJECT
    
public:
    //GUIPanel(QWidget *parent = 0);
    explicit GUIPanel(QWidget *parent = 0);
    ~GUIPanel(); // Da problemas
    
private slots:

    void on_runMQTTButton_clicked();
    void on_pushButton_clicked();

    void onMQTT_Received(const QMQTT::Message &message);
    void onMQTT_Connected(void);    
    void onMQTT_subscribed(const QString &topic);
    void onMQTT_error(QMQTT::ClientError err);

    void on_SpinBox_valueChanged(double arg1);

private: // funciones privadas
    void startClient();
    void activateRunButton();
private:
    Ui::GUIPanel *ui;
    int transactionCount;
    QMQTT::Client *_client;
    bool MQTTconnected;
};

#endif // GUIPANEL_H
