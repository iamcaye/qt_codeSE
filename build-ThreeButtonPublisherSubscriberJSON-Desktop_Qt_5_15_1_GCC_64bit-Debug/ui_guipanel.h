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
#include "color_wheel.hpp"
#include "qwt_knob.h"

QT_BEGIN_NAMESPACE

class Ui_GUIPanel
{
public:
    QPushButton *runButton;
    QLabel *statusLabel;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *leHost;
    QLineEdit *topic;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QwtKnob *Knob;
    QLabel *label_7;
    QLabel *label_8;
    color_widgets::ColorWheel *colorWheel;

    void setupUi(QWidget *GUIPanel)
    {
        if (GUIPanel->objectName().isEmpty())
            GUIPanel->setObjectName(QString::fromUtf8("GUIPanel"));
        GUIPanel->resize(618, 394);
        runButton = new QPushButton(GUIPanel);
        runButton->setObjectName(QString::fromUtf8("runButton"));
        runButton->setGeometry(QRect(300, 10, 98, 27));
        statusLabel = new QLabel(GUIPanel);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(70, 370, 331, 17));
        pushButton = new QPushButton(GUIPanel);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 370, 64, 27));
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
        pushButton_2 = new QPushButton(GUIPanel);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 80, 101, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color:red"));
        pushButton_2->setCheckable(true);
        pushButton_3 = new QPushButton(GUIPanel);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(140, 80, 101, 51));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color:green"));
        pushButton_3->setCheckable(true);
        pushButton_4 = new QPushButton(GUIPanel);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(260, 80, 101, 51));
        pushButton_4->setAutoFillBackground(false);
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color:blue"));
        pushButton_4->setCheckable(true);
        label_3 = new QLabel(GUIPanel);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 140, 421, 16));
        pushButton_6 = new QPushButton(GUIPanel);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(140, 180, 101, 51));
        pushButton_6->setStyleSheet(QString::fromUtf8(""));
        pushButton_6->setCheckable(true);
        pushButton_7 = new QPushButton(GUIPanel);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(260, 180, 101, 51));
        pushButton_7->setAutoFillBackground(false);
        pushButton_7->setStyleSheet(QString::fromUtf8(""));
        pushButton_7->setCheckable(true);
        pushButton_5 = new QPushButton(GUIPanel);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 180, 101, 51));
        pushButton_5->setStyleSheet(QString::fromUtf8(""));
        pushButton_5->setCheckable(true);
        label_4 = new QLabel(GUIPanel);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 240, 81, 16));
        label_5 = new QLabel(GUIPanel);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(160, 240, 91, 16));
        label_6 = new QLabel(GUIPanel);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(280, 240, 81, 16));
        Knob = new QwtKnob(GUIPanel);
        Knob->setObjectName(QString::fromUtf8("Knob"));
        Knob->setGeometry(QRect(430, 190, 101, 111));
        Knob->setUpperBound(1.000000000000000);
        label_7 = new QLabel(GUIPanel);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(460, 40, 55, 16));
        label_8 = new QLabel(GUIPanel);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(460, 190, 55, 16));
        colorWheel = new color_widgets::ColorWheel(GUIPanel);
        colorWheel->setObjectName(QString::fromUtf8("colorWheel"));
        colorWheel->setGeometry(QRect(470, 70, 100, 100));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(colorWheel->sizePolicy().hasHeightForWidth());
        colorWheel->setSizePolicy(sizePolicy);

        retranslateUi(GUIPanel);

        QMetaObject::connectSlotsByName(GUIPanel);
    } // setupUi

    void retranslateUi(QWidget *GUIPanel)
    {
        GUIPanel->setWindowTitle(QCoreApplication::translate("GUIPanel", "GUIPanel", nullptr));
        runButton->setText(QCoreApplication::translate("GUIPanel", "Inicio", nullptr));
        statusLabel->setText(QCoreApplication::translate("GUIPanel", "Detenido", nullptr));
        pushButton->setText(QCoreApplication::translate("GUIPanel", "Estado:", nullptr));
        label->setText(QCoreApplication::translate("GUIPanel", "MQTT Broker", nullptr));
        label_2->setText(QCoreApplication::translate("GUIPanel", "Topic", nullptr));
        leHost->setText(QCoreApplication::translate("GUIPanel", "localhost", nullptr));
        topic->setText(QCoreApplication::translate("GUIPanel", "/rpi/GPIOTiva", nullptr));
        pushButton_2->setText(QCoreApplication::translate("GUIPanel", "Enciende", nullptr));
        pushButton_3->setText(QCoreApplication::translate("GUIPanel", "Enciende", nullptr));
        pushButton_4->setText(QCoreApplication::translate("GUIPanel", "Enciende", nullptr));
        label_3->setText(QCoreApplication::translate("GUIPanel", "Ojo, el naranja no esta implementado en el codigo de partida para la CC3200", nullptr));
        pushButton_6->setText(QCoreApplication::translate("GUIPanel", "Enciende", nullptr));
        pushButton_7->setText(QCoreApplication::translate("GUIPanel", "Enciende", nullptr));
        pushButton_5->setText(QCoreApplication::translate("GUIPanel", "Enciende", nullptr));
        label_4->setText(QCoreApplication::translate("GUIPanel", "RPI_PIN_2", nullptr));
        label_5->setText(QCoreApplication::translate("GUIPanel", "RPI_PIN_3", nullptr));
        label_6->setText(QCoreApplication::translate("GUIPanel", "RPI_PIN_4", nullptr));
        label_7->setText(QCoreApplication::translate("GUIPanel", "RGB Color", nullptr));
        label_8->setText(QCoreApplication::translate("GUIPanel", "Intensity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUIPanel: public Ui_GUIPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIPANEL_H
