/********************************************************************************
** Form generated from reading UI file 'guipanel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIPANEL_H
#define UI_GUIPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "analogwidgets/led.h"

QT_BEGIN_NAMESPACE

class Ui_GUIPanel
{
public:
    QPushButton *runMQTTButton;
    QLabel *statusLabel;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *leHost;
    QLineEdit *topic;
    Led *led;
    Led *led_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *GUIPanel)
    {
        if (GUIPanel->objectName().isEmpty())
            GUIPanel->setObjectName(QString::fromUtf8("GUIPanel"));
        GUIPanel->resize(428, 227);
        runMQTTButton = new QPushButton(GUIPanel);
        runMQTTButton->setObjectName(QString::fromUtf8("runMQTTButton"));
        runMQTTButton->setGeometry(QRect(300, 10, 98, 27));
        statusLabel = new QLabel(GUIPanel);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(70, 200, 331, 17));
        pushButton = new QPushButton(GUIPanel);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 190, 64, 27));
        label = new QLabel(GUIPanel);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 71, 16));
        label_2 = new QLabel(GUIPanel);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 37, 71, 16));
        leHost = new QLineEdit(GUIPanel);
        leHost->setObjectName(QString::fromUtf8("leHost"));
        leHost->setGeometry(QRect(100, 10, 164, 20));
        topic = new QLineEdit(GUIPanel);
        topic->setObjectName(QString::fromUtf8("topic"));
        topic->setGeometry(QRect(100, 35, 164, 20));
        led = new Led(GUIPanel);
        led->setObjectName(QString::fromUtf8("led"));
        led->setEnabled(true);
        led->setGeometry(QRect(100, 80, 81, 81));
        led->setChecked(false);
        led->setColor(QColor(85, 170, 255));
        led_2 = new Led(GUIPanel);
        led_2->setObjectName(QString::fromUtf8("led_2"));
        led_2->setEnabled(true);
        led_2->setGeometry(QRect(230, 80, 81, 81));
        led_2->setChecked(false);
        led_2->setColor(QColor(85, 170, 255));
        label_3 = new QLabel(GUIPanel);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 170, 71, 20));
        label_4 = new QLabel(GUIPanel);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(230, 170, 81, 16));

        retranslateUi(GUIPanel);

        QMetaObject::connectSlotsByName(GUIPanel);
    } // setupUi

    void retranslateUi(QWidget *GUIPanel)
    {
        GUIPanel->setWindowTitle(QCoreApplication::translate("GUIPanel", "GUIPanel", nullptr));
        runMQTTButton->setText(QCoreApplication::translate("GUIPanel", "Inicio", nullptr));
        statusLabel->setText(QCoreApplication::translate("GUIPanel", "Detenido", nullptr));
        pushButton->setText(QCoreApplication::translate("GUIPanel", "Estado:", nullptr));
        label->setText(QCoreApplication::translate("GUIPanel", "MQTT Broker", nullptr));
        label_2->setText(QCoreApplication::translate("GUIPanel", "Topic", nullptr));
        leHost->setText(QCoreApplication::translate("GUIPanel", "localhost", nullptr));
        topic->setText(QCoreApplication::translate("GUIPanel", "rxtopic", nullptr));
#if QT_CONFIG(tooltip)
        led->setToolTip(QCoreApplication::translate("GUIPanel", "Color Led component", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        led->setWhatsThis(QCoreApplication::translate("GUIPanel", "Led indicator", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(tooltip)
        led_2->setToolTip(QCoreApplication::translate("GUIPanel", "Color Led component", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        led_2->setWhatsThis(QCoreApplication::translate("GUIPanel", "Led indicator", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_3->setText(QCoreApplication::translate("GUIPanel", "LEFT_BUTTON", nullptr));
        label_4->setText(QCoreApplication::translate("GUIPanel", "RIGHT_BUTTON", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUIPanel: public Ui_GUIPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIPANEL_H
