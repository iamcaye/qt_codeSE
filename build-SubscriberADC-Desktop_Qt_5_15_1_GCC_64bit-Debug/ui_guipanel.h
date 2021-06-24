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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

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
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLCDNumber *lcdCh1;
    QLCDNumber *lcdCh2;
    QLCDNumber *lcdCh3;
    QLCDNumber *lcdCh4;
    QLabel *label_3;
    QDoubleSpinBox *SpinBox;

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
        gridLayoutWidget = new QWidget(GUIPanel);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 80, 241, 91));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lcdCh1 = new QLCDNumber(gridLayoutWidget);
        lcdCh1->setObjectName(QString::fromUtf8("lcdCh1"));
        lcdCh1->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(lcdCh1, 0, 0, 1, 1);

        lcdCh2 = new QLCDNumber(gridLayoutWidget);
        lcdCh2->setObjectName(QString::fromUtf8("lcdCh2"));
        lcdCh2->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(lcdCh2, 0, 1, 1, 1);

        lcdCh3 = new QLCDNumber(gridLayoutWidget);
        lcdCh3->setObjectName(QString::fromUtf8("lcdCh3"));
        lcdCh3->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(lcdCh3, 1, 0, 1, 1);

        lcdCh4 = new QLCDNumber(gridLayoutWidget);
        lcdCh4->setObjectName(QString::fromUtf8("lcdCh4"));
        lcdCh4->setSmallDecimalPoint(false);
        lcdCh4->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(lcdCh4, 1, 1, 1, 1);

        label_3 = new QLabel(GUIPanel);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(290, 80, 81, 19));
        SpinBox = new QDoubleSpinBox(GUIPanel);
        SpinBox->setObjectName(QString::fromUtf8("SpinBox"));
        SpinBox->setGeometry(QRect(290, 100, 71, 31));
        SpinBox->setMinimum(0.500000000000000);
        SpinBox->setMaximum(50.000000000000000);

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
        topic->setText(QCoreApplication::translate("GUIPanel", "/rpi/ADC", nullptr));
        label_3->setText(QCoreApplication::translate("GUIPanel", "Frecuencia", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUIPanel: public Ui_GUIPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIPANEL_H
