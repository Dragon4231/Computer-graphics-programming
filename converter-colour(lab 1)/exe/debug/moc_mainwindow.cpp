/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[397];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(4, 56, 4), // "arg1"
QT_MOC_LITERAL(5, 61, 23), // "on_comboBox_2_activated"
QT_MOC_LITERAL(6, 85, 23), // "on_comboBox_3_activated"
QT_MOC_LITERAL(7, 109, 22), // "on_lineEdit_textEdited"
QT_MOC_LITERAL(8, 132, 24), // "on_lineEdit_2_textEdited"
QT_MOC_LITERAL(9, 157, 24), // "on_lineEdit_3_textEdited"
QT_MOC_LITERAL(10, 182, 31), // "on_horizontalSlider_sliderMoved"
QT_MOC_LITERAL(11, 214, 8), // "position"
QT_MOC_LITERAL(12, 223, 33), // "on_horizontalSlider_2_sliderM..."
QT_MOC_LITERAL(13, 257, 33), // "on_horizontalSlider_3_sliderM..."
QT_MOC_LITERAL(14, 291, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(15, 323, 5), // "index"
QT_MOC_LITERAL(16, 329, 33), // "on_comboBox_2_currentIndexCha..."
QT_MOC_LITERAL(17, 363, 33) // "on_comboBox_3_currentIndexCha..."

    },
    "MainWindow\0on_pushButton_clicked\0\0"
    "on_comboBox_activated\0arg1\0"
    "on_comboBox_2_activated\0on_comboBox_3_activated\0"
    "on_lineEdit_textEdited\0on_lineEdit_2_textEdited\0"
    "on_lineEdit_3_textEdited\0"
    "on_horizontalSlider_sliderMoved\0"
    "position\0on_horizontalSlider_2_sliderMoved\0"
    "on_horizontalSlider_3_sliderMoved\0"
    "on_comboBox_currentIndexChanged\0index\0"
    "on_comboBox_2_currentIndexChanged\0"
    "on_comboBox_3_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

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
       3,    1,   80,    2, 0x08 /* Private */,
       5,    1,   83,    2, 0x08 /* Private */,
       6,    1,   86,    2, 0x08 /* Private */,
       7,    1,   89,    2, 0x08 /* Private */,
       8,    1,   92,    2, 0x08 /* Private */,
       9,    1,   95,    2, 0x08 /* Private */,
      10,    1,   98,    2, 0x08 /* Private */,
      12,    1,  101,    2, 0x08 /* Private */,
      13,    1,  104,    2, 0x08 /* Private */,
      14,    1,  107,    2, 0x08 /* Private */,
      16,    1,  110,    2, 0x08 /* Private */,
      17,    1,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_comboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_comboBox_2_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_comboBox_3_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_lineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_lineEdit_2_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_lineEdit_3_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_horizontalSlider_2_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_horizontalSlider_3_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_comboBox_2_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_comboBox_3_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
