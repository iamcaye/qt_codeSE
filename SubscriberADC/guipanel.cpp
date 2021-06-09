#include "guipanel.h"
#include "ui_guipanel.h"
#include <QSerialPort>      // Comunicacion por el puerto serie
#include <QSerialPortInfo>  // Comunicacion por el puerto serie
#include <QMessageBox>      // Se deben incluir cabeceras a los componentes que se vayan a crear en la clase

#include <QJsonObject>
#include <QJsonDocument>
// y que no estén incluidos en el interfaz gráfico. En este caso, la ventana de PopUp <QMessageBox>
// que se muestra al recibir un PING de respuesta

#include<stdint.h>      // Cabecera para usar tipos de enteros con tamaño
#include<stdbool.h>     // Cabecera para usar booleanos


GUIPanel::GUIPanel(QWidget *parent) :  // Constructor de la clase
    QWidget(parent),
    ui(new Ui::GUIPanel)               // Indica que guipanel.ui es el interfaz grafico de la clase
  , transactionCount(0)
{
    ui->setupUi(this);                // Conecta la clase con su interfaz gráfico.
    setWindowTitle(tr("Interfaz de Control")); // Título de la ventana

    // Creación del cliente MQTT y "enganche" a sus señales
    _client=new QMQTT::Client(QHostAddress::LocalHost, 1883); //localhost y lo otro son valores por defecto
    connect(_client, SIGNAL(connected()), this, SLOT(onMQTT_Connected()));
    connect(_client, SIGNAL(received(const QMQTT::Message &)), this, SLOT(onMQTT_Received(const QMQTT::Message &)));
    connect(_client, SIGNAL(subscribed(const QString &)), this, SLOT(onMQTT_subscribed(const QString &)));
    connect(_client, SIGNAL(error(const QMQTT::ClientError)), this, SLOT(onMQTT_error(QMQTT::ClientError))); // MQTT OPCIONAL

    MQTTconnected=false;                 // Todavía no hemos establecido la conexión MQTT
}

GUIPanel::~GUIPanel() // Destructor de la clase
{
    delete ui;   // Borra el interfaz gráfico asociado a la clase
}


// SLOT asociado a pulsación del boton de Estado
void GUIPanel::on_pushButton_clicked()
{
    ui->statusLabel->setText(tr("")); // Borra mensaje de estado
}

// SLOT asociado a pulsación del botón MQTT
void GUIPanel::on_runMQTTButton_clicked()
{
    startClient();
}

// Funciones MQTT

// Ejecuta cliente para conexión por MQTT
void GUIPanel::startClient()
{
    _client->setHostName(ui->leHost->text());
    _client->setPort(1883);
    _client->setKeepAlive(300);
    _client->setCleanSession(true);
    _client->connectToHost();
}

/* -----------------------------------------------------------
 MQTT Client Slots
 -----------------------------------------------------------*/
void GUIPanel::onMQTT_Connected()
{
    QString topic(ui->topic->text());

    ui->runMQTTButton->setEnabled(false);

    // Se indica que se ha realizado la conexión en la etiqueta 'statusLabel'
    ui->statusLabel->setText(tr("Ejecucion, conectado al servidor"));

    MQTTconnected=true;

    _client->subscribe(topic,0); //Se suscribe al mismo topic en el que publica...
}

// SLOT asociado a suscripción a un topic MQTT
void GUIPanel::onMQTT_subscribed(const QString &topic)
{
     ui->statusLabel->setText(tr("subscribed %1").arg(topic));
}


// OPCIONAL: Respuesta ante ERRORES MQTT
void GUIPanel::onMQTT_error(QMQTT::ClientError err)
{
    //todo: should emit on server suback

    QString errInfo;
    switch(err) {
    // 0	The connection was refused by the peer (or timed out).
    case QAbstractSocket::ConnectionRefusedError:
        errInfo = tr("Connection Refused");
        break;
    //	 1	The remote host closed the connection. Note that the client socket (i.e., this socket) will be closed after the remote close notification has been sent.
    case QAbstractSocket::RemoteHostClosedError:
        errInfo = tr("Remote Host Closed");
        break;
    //	2	The host address was not found.
    case QAbstractSocket::HostNotFoundError:
        errInfo = tr("Host Not Found Error");
        break;
    // 	3	The socket operation failed because the application lacked the required privileges.
    case QAbstractSocket::SocketAccessError:
        errInfo = tr("Socket Access Error");
        break;
    // 	4	The local system ran out of resources (e.g., too many sockets).
    case QAbstractSocket::SocketResourceError:
        errInfo = tr("Socket Resource Error");
        break;
    // 	5	The socket operation timed out.
    case QAbstractSocket::SocketTimeoutError:
        errInfo = tr("Socket Timeout Error");
        break;
    default:
        errInfo = tr("Socket Error");
    }
    ui->statusLabel->setText(tr("%1").arg(errInfo));
    ui->runMQTTButton->setEnabled(true);
}

// SLOT asociado a recepción de mensajes MQTT
void GUIPanel::onMQTT_Received(const QMQTT::Message &message)
{
    if (MQTTconnected)
    {
        QJsonParseError error;
        QJsonDocument mensaje=QJsonDocument::fromJson(message.payload(),&error);

        if ((error.error==QJsonParseError::NoError)&&(mensaje.isObject()))
        {
            QJsonObject objeto_json=mensaje.object();
            QJsonValue ch1 = objeto_json["ADCch0"];
            QJsonValue ch2 = objeto_json["ADCch1"];
            QJsonValue ch3 = objeto_json["ADCch2"];
            QJsonValue ch4 = objeto_json["ADCch3"];

            if(ch1.isDouble() || ch2.isDouble() || ch3.isDouble() || ch4.isDouble())
            {
                ui->lcdCh1->display(((double)ch1.toDouble()));
                ui->lcdCh2->display(((double)ch2.toDouble()));
                ui->lcdCh3->display(((double)ch3.toDouble()));
                ui->lcdCh4->display(((double)ch4.toDouble()));
            }

        }
    }

}



void GUIPanel::on_SpinBox_valueChanged(double arg1)
{
    QJsonObject objeto_json;
    objeto_json["ADCFrec"]= (float)arg1;

    QJsonDocument mensaje(objeto_json);

    QMQTT::Message msg(0, "/rpi/controltopic", mensaje.toJson());

    _client->publish(msg);
}

