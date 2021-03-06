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

    _client=new QMQTT::Client(QHostAddress::LocalHost, 1883); //localhost y lo otro son valores por defecto


    connect(_client, SIGNAL(connected()), this, SLOT(onMQTT_Connected()));    
    connect(_client, SIGNAL(received(const QMQTT::Message &)), this, SLOT(onMQTT_Received(const QMQTT::Message &)));
    connect(_client, SIGNAL(subscribed(const QString &)), this, SLOT(onMQTT_subscribed(const QString &)));    

    connected=false;                 // Todavía no hemos establecido la conexión USB
}

GUIPanel::~GUIPanel() // Destructor de la clase
{
    delete ui;   // Borra el interfaz gráfico asociado a la clase
}


// Establecimiento de la comunicación USB serie a través del interfaz seleccionado en la comboBox, tras pulsar el
// botón RUN del interfaz gráfico. Se establece una comunicacion a 9600bps 8N1 y sin control de flujo en el objeto
// 'serial' que es el que gestiona la comunicación USB serie en el interfaz QT
void GUIPanel::startClient()
{
    _client->setHostName(ui->leHost->text());
    _client->setPort(1883);
    _client->setKeepAlive(300);
    _client->setCleanSession(true);
    _client->connectToHost();

}

// Funcion auxiliar de procesamiento de errores de comunicación (usada por startSlave)
void GUIPanel::processError(const QString &s)
{
    activateRunButton(); // Activa el botón RUN
    // Muestra en la etiqueta de estado la razón del error (notese la forma de pasar argumentos a la cadena de texto)
    ui->statusLabel->setText(tr("Status: Not running, %1.").arg(s));
}

// Funcion de habilitacion del boton de inicio/conexion
void GUIPanel::activateRunButton()
{
    ui->runButton->setEnabled(true);
}

// SLOT asociada a pulsación del botón RUN
void GUIPanel::on_runButton_clicked()
{
    startClient();
}


void GUIPanel::onMQTT_subscribed(const QString &topic)
{
     ui->statusLabel->setText(tr("subscribed %1").arg(topic));
}


void GUIPanel::on_pushButton_clicked()
{
    ui->statusLabel->setText(tr(""));
}


void GUIPanel::onMQTT_Received(const QMQTT::Message &message)
{
    bool previousblockinstate,checked;
    if (connected)
    {
        //Deshacemos el escalado

        QColor c;
        QJsonParseError error;
        QJsonDocument mensaje=QJsonDocument::fromJson(message.payload(),&error);
        int rgb[3];
        double g_intensidad = 0.5f;

        if ((error.error==QJsonParseError::NoError)&&(mensaje.isObject()))
        { //Tengo que comprobar que el mensaje es del tipo adecuado y no hay errores de parseo...

            QJsonObject objeto_json=mensaje.object();
            QJsonValue entrada=objeto_json["redLed"]; //Obtengo la entrada redLed. Esto lo puedo hacer porque el operador [] está sobrecargado
            QJsonValue entrada2=objeto_json["greenLed"]; //Obtengo la entrada orangeLed. Esto lo puedo hacer porque el operador [] está sobrecargado
            QJsonValue entrada3=objeto_json["blueLed"]; //Obtengo la entrada greenLed. Esto lo puedo hacer porque el operador [] está sobrecargado
            QJsonValue pin2 = objeto_json["pin2"];
            QJsonValue pin3 = objeto_json["pin3"];
            QJsonValue pin4 = objeto_json["pin4"];

            QJsonValue r = objeto_json["redRGB"];
            QJsonValue g = objeto_json["greenRGB"];
            QJsonValue b = objeto_json["blueRGB"];

            QJsonValue intensidad = objeto_json["intensityRGB"];

            if(intensidad.isDouble())
            {
                ui -> Knob -> blockSignals(true);
                g_intensidad = intensidad.toDouble();
                ui -> Knob -> setValue(g_intensidad);
                ui -> Knob -> blockSignals(false);
            }

            if(!r.isUndefined())
            {
                rgb[0] = r.toInt();
            }

            if(!g.isUndefined())
            {
                rgb[1] = g.toInt();
            }

            if(!b.isUndefined())
            {
                rgb[2] = b.toInt();
            }

            if(rgb[0] != 0 || rgb[1] != 0 || rgb[2] != 0)
            {
                ui->colorWheel->blockSignals(true);   //Esto es para evitar que el cambio de valor
                c.setRgb(rgb[0], rgb[1], rgb[2], 255);
                ui -> colorWheel -> setColor(c);
                ui->colorWheel->blockSignals(false);
            }

            if (entrada.isBool())
            {   //Compruebo que es booleano...

                checked=entrada.toBool(); //Leo el valor de objeto (si fuese entero usaria toInt(), toDouble() si es doble....
                previousblockinstate=ui->pushButton_2->blockSignals(true);   //Esto es para evitar que el cambio de valor
                                                                     //provoque otro envio al topic por el que he recibido

                ui->pushButton_2->setChecked(checked);
                if (checked)
                {
                    ui->pushButton_2->setText("Apaga");

                }
                else
                {
                    ui->pushButton_2->setText("Enciende");
                }
                ui->pushButton_2->blockSignals(previousblockinstate);
            }            
            if (entrada2.isBool())
            {   //Compruebo que es booleano...

                checked=entrada2.toBool(); //Leo el valor de objeto (si fuese entero usaria toInt(), toDouble() si es doble....
                previousblockinstate=ui->pushButton_3->blockSignals(true);   //Esto es para evitar que el cambio de valor
                                                                     //provoque otro envio al topic por el que he recibido

                ui->pushButton_3->setChecked(checked);
                if (checked)
                {
                    ui->pushButton_3->setText("Apaga");

                }
                else
                {
                    ui->pushButton_3->setText("Enciende");
                }
                ui->pushButton_3->blockSignals(previousblockinstate);
            }
            if (entrada3.isBool())
            {   //Compruebo que es booleano...

                checked=entrada3.toBool(); //Leo el valor de objeto (si fuese entero usaria toInt(), toDouble() si es doble....
                previousblockinstate=ui->pushButton_4->blockSignals(true);   //Esto es para evitar que el cambio de valor
                                                                     //provoque otro envio al topic por el que he recibido

                ui->pushButton_4->setChecked(checked);
                if (checked)
                {
                    ui->pushButton_4->setText("Apaga");

                }
                else
                {
                    ui->pushButton_4->setText("Enciende");
                }
                ui->pushButton_4->blockSignals(previousblockinstate);
            }

            if (pin2.isBool())
            {   //Compruebo que es booleano...

                checked=pin2.toBool(); //Leo el valor de objeto (si fuese entero usaria toInt(), toDouble() si es doble....
                previousblockinstate=ui->pushButton_5->blockSignals(true);   //Esto es para evitar que el cambio de valor
                                                                     //provoque otro envio al topic por el que he recibido

                ui->pushButton_5->setChecked(checked);
                if (checked)
                {
                    ui->pushButton_5->setText("Apaga");

                }
                else
                {
                    ui->pushButton_5->setText("Enciende");
                }
                ui->pushButton_5->blockSignals(previousblockinstate);
            }

            if (pin3.isBool())
            {   //Compruebo que es booleano...

                checked=pin3.toBool(); //Leo el valor de objeto (si fuese entero usaria toInt(), toDouble() si es doble....
                previousblockinstate=ui->pushButton_6->blockSignals(true);   //Esto es para evitar que el cambio de valor
                                                                     //provoque otro envio al topic por el que he recibido

                ui->pushButton_6->setChecked(checked);
                if (checked)
                {
                    ui->pushButton_6->setText("Apaga");

                }
                else
                {
                    ui->pushButton_6->setText("Enciende");
                }
                ui->pushButton_6->blockSignals(previousblockinstate);
            }

            if (pin4.isBool())
            {   //Compruebo que es booleano...

                checked=pin4.toBool(); //Leo el valor de objeto (si fuese entero usaria toInt(), toDouble() si es doble....
                previousblockinstate=ui->pushButton_7->blockSignals(true);   //Esto es para evitar que el cambio de valor
                                                                     //provoque otro envio al topic por el que he recibido

                ui->pushButton_7->setChecked(checked);
                if (checked)
                {
                    ui->pushButton_7->setText("Apaga");

                }
                else
                {
                    ui->pushButton_7->setText("Enciende");
                }
                ui->pushButton_7->blockSignals(previousblockinstate);
            }
        }


    }
}


/* -----------------------------------------------------------
 MQTT Client Slots
 -----------------------------------------------------------*/
void GUIPanel::onMQTT_Connected()
{
    QString topic(ui->topic->text());

    ui->runButton->setEnabled(false);

    // Se indica que se ha realizado la conexión en la etiqueta 'statusLabel'
    ui->statusLabel->setText(tr("Ejecucion, conectado al servidor"));

    connected=true;

    _client->subscribe(topic,0); //Se suscribe al mismo topic en el que publica...
    _client->subscribe("/rpi/PWM", 0);
}



void GUIPanel::SendMessage()
{

    QJsonObject objeto_json;
    //Añade un campo "redLed" al objeto JSON, con el valor (true o false) contenido en checked
    objeto_json["redLed"]=ui->pushButton_2->isChecked(); //Puedo hacer ["redLed"] porque el operador [] está sobrecargado.
    //Añade un campo "orangeLed" al objeto JSON, con el valor (true o false) contenido en checked
    objeto_json["greenLed"]=ui->pushButton_3->isChecked(); //Puedo hacer ["orangeLed"] porque el operador [] está sobrecargado.
    //Añade un campo "greenLed" al objeto JSON, con el valor (true o false) contenido en checked
    objeto_json["blueLed"]=ui->pushButton_4->isChecked();

    QJsonDocument mensaje(objeto_json); //crea un objeto de tivo QJsonDocument conteniendo el objeto objeto_json (necesario para obtener el mensaje formateado en JSON)

    QMQTT::Message msg(0, ui->topic->text(), mensaje.toJson()); //Crea el mensaje MQTT contieniendo el mensaje en formato JSON

    //Publica el mensaje
    _client->publish(msg);

}

void GUIPanel::SendPinsMessage()
{

    QJsonObject objeto_json;
    objeto_json["pin2"]=ui->pushButton_5->isChecked();
    objeto_json["pin3"]=ui->pushButton_6->isChecked();
    objeto_json["pin4"]=ui->pushButton_7->isChecked();

    QJsonDocument mensaje(objeto_json);

    QMQTT::Message msg(0, ui->topic->text(), mensaje.toJson());

    _client->publish(msg);

}

void GUIPanel::on_pushButton_2_toggled(bool checked)
{
    //Rojo
    if (checked)
    {
        ui->pushButton_2->setText("Apaga");

    }
    else
    {
        ui->pushButton_2->setText("Enciende");
    }
    SendMessage();
}

void GUIPanel::on_pushButton_4_toggled(bool checked)
{
    //Verde
    if (checked)
    {
        ui->pushButton_4->setText("Apaga");

    }
    else
    {
        ui->pushButton_4->setText("Enciende");
    }
    SendMessage();
}

void GUIPanel::on_pushButton_3_toggled(bool checked)
{
    //Orange
    if (checked)
    {
        ui->pushButton_3->setText("Apaga");

    }
    else
    {
        ui->pushButton_3->setText("Enciende");
    }
    SendMessage();
}

void GUIPanel::on_pushButton_5_toggled(bool checked)
{
   if(checked)
   {
       ui -> pushButton_5 -> setText("Apaga");
   }
   else
   {
       ui -> pushButton_5 -> setText("Enciende");
   }
    SendPinsMessage();
}

void GUIPanel::on_pushButton_6_toggled(bool checked)
{
   if(checked)
   {
       ui -> pushButton_6 -> setText("Apaga");
   }
   else
   {
       ui -> pushButton_6 -> setText("Enciende");
   }
    SendPinsMessage();
}

void GUIPanel::on_pushButton_7_toggled(bool checked)
{
   if(checked)
   {
       ui -> pushButton_7 -> setText("Apaga");
   }
   else
   {
       ui -> pushButton_7 -> setText("Enciende");
   }
    SendPinsMessage();
}

void GUIPanel::on_colorWheel_colorChanged(const QColor &arg1)
{
    int colores[3] = {0, 0, 0};
    arg1.getRgb(&colores[0], &colores[1], &colores[2]);

    QJsonObject objeto_json;

    objeto_json["redRGB"] = colores[0];
    objeto_json["greenRGB"] = colores[1];
    objeto_json["blueRGB"] = colores[2];

    QJsonDocument mensaje(objeto_json);

    QMQTT::Message msg(0, "/rpi/PWM", mensaje.toJson());

    _client->publish(msg);
}

void GUIPanel::on_Knob_valueChanged(double value)
{
    QJsonObject objeto_json;

    objeto_json["intensityRGB"] = value;

    QJsonDocument mensaje(objeto_json);

    QMQTT::Message msg(0, "/rpi/PWM", mensaje.toJson());

    _client->publish(msg);
}
