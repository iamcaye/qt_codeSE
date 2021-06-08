/****************************************************************************
** Meta object code from reading C++ file 'guipanel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ThreeButtonPublisherSubscriber/guipanel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'guipanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GUIPanel_t {
    QByteArrayData data[21];
    char stringdata0[344];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUIPanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUIPanel_t qt_meta_stringdata_GUIPanel = {
    {
QT_MOC_LITERAL(0, 0, 8), // "GUIPanel"
QT_MOC_LITERAL(1, 9, 20), // "on_runButton_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(4, 53, 15), // "onMQTT_Received"
QT_MOC_LITERAL(5, 69, 14), // "QMQTT::Message"
QT_MOC_LITERAL(6, 84, 7), // "message"
QT_MOC_LITERAL(7, 92, 16), // "onMQTT_Connected"
QT_MOC_LITERAL(8, 109, 17), // "onMQTT_subscribed"
QT_MOC_LITERAL(9, 127, 5), // "topic"
QT_MOC_LITERAL(10, 133, 23), // "on_pushButton_2_toggled"
QT_MOC_LITERAL(11, 157, 7), // "checked"
QT_MOC_LITERAL(12, 165, 23), // "on_pushButton_3_toggled"
QT_MOC_LITERAL(13, 189, 23), // "on_pushButton_4_toggled"
QT_MOC_LITERAL(14, 213, 23), // "on_pushButton_5_toggled"
QT_MOC_LITERAL(15, 237, 23), // "on_pushButton_6_toggled"
QT_MOC_LITERAL(16, 261, 23), // "on_pushButton_7_toggled"
QT_MOC_LITERAL(17, 285, 26), // "on_colorWheel_colorChanged"
QT_MOC_LITERAL(18, 312, 4), // "arg1"
QT_MOC_LITERAL(19, 317, 20), // "on_Knob_valueChanged"
QT_MOC_LITERAL(20, 338, 5) // "value"

    },
    "GUIPanel\0on_runButton_clicked\0\0"
    "on_pushButton_clicked\0onMQTT_Received\0"
    "QMQTT::Message\0message\0onMQTT_Connected\0"
    "onMQTT_subscribed\0topic\0on_pushButton_2_toggled\0"
    "checked\0on_pushButton_3_toggled\0"
    "on_pushButton_4_toggled\0on_pushButton_5_toggled\0"
    "on_pushButton_6_toggled\0on_pushButton_7_toggled\0"
    "on_colorWheel_colorChanged\0arg1\0"
    "on_Knob_valueChanged\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUIPanel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    1,   81,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    1,   85,    2, 0x08 /* Private */,
      10,    1,   88,    2, 0x08 /* Private */,
      12,    1,   91,    2, 0x08 /* Private */,
      13,    1,   94,    2, 0x08 /* Private */,
      14,    1,   97,    2, 0x08 /* Private */,
      15,    1,  100,    2, 0x08 /* Private */,
      16,    1,  103,    2, 0x08 /* Private */,
      17,    1,  106,    2, 0x08 /* Private */,
      19,    1,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::QColor,   18,
    QMetaType::Void, QMetaType::Double,   20,

       0        // eod
};

void GUIPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GUIPanel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_runButton_clicked(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->onMQTT_Received((*reinterpret_cast< const QMQTT::Message(*)>(_a[1]))); break;
        case 3: _t->onMQTT_Connected(); break;
        case 4: _t->onMQTT_subscribed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_2_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_3_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_4_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_pushButton_5_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_6_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_pushButton_7_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_colorWheel_colorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 12: _t->on_Knob_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMQTT::Message >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GUIPanel::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GUIPanel.data,
    qt_meta_data_GUIPanel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GUIPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUIPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GUIPanel.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GUIPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
