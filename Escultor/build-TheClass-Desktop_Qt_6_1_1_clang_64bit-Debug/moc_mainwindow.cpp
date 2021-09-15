/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../TheClass/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[48];
    char stringdata0[342];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 4), // "setR"
QT_MOC_LITERAL(16, 0), // ""
QT_MOC_LITERAL(17, 4), // "setG"
QT_MOC_LITERAL(22, 4), // "setB"
QT_MOC_LITERAL(27, 9), // "pickColor"
QT_MOC_LITERAL(37, 9), // "drawShape"
QT_MOC_LITERAL(47, 12), // "updateCoords"
QT_MOC_LITERAL(60, 9), // "clickedXY"
QT_MOC_LITERAL(70, 9), // "clickedXZ"
QT_MOC_LITERAL(80, 9), // "clickedZY"
QT_MOC_LITERAL(90, 17), // "on_actionPutVoxel"
QT_MOC_LITERAL(108, 17), // "on_actionCutVoxel"
QT_MOC_LITERAL(126, 15), // "on_actionPutBox"
QT_MOC_LITERAL(142, 15), // "on_actionCutBox"
QT_MOC_LITERAL(158, 19), // "on_actionPutSpheare"
QT_MOC_LITERAL(178, 19), // "on_actionCutSpheare"
QT_MOC_LITERAL(198, 21), // "on_actionPutEllipsoid"
QT_MOC_LITERAL(220, 21), // "on_actionCutEllipsoid"
QT_MOC_LITERAL(242, 21), // "on_layerSliderXChange"
QT_MOC_LITERAL(264, 21), // "on_layerSliderYChange"
QT_MOC_LITERAL(286, 21), // "on_layerSliderZChange"
QT_MOC_LITERAL(308, 14), // "on_newSculptor"
QT_MOC_LITERAL(323, 18) // "on_actionExportOFF"

    },
    "MainWindow\0setR\0\0setG\0setB\0pickColor\0"
    "drawShape\0updateCoords\0clickedXY\0"
    "clickedXZ\0clickedZY\0on_actionPutVoxel\0"
    "on_actionCutVoxel\0on_actionPutBox\0"
    "on_actionCutBox\0on_actionPutSpheare\0"
    "on_actionCutSpheare\0on_actionPutEllipsoid\0"
    "on_actionCutEllipsoid\0on_layerSliderXChange\0"
    "on_layerSliderYChange\0on_layerSliderZChange\0"
    "on_newSculptor\0on_actionExportOFF"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  146,    2, 0x0a,    0 /* Public */,
       3,    1,  149,    2, 0x0a,    2 /* Public */,
       4,    1,  152,    2, 0x0a,    4 /* Public */,
       5,    0,  155,    2, 0x0a,    6 /* Public */,
       6,    2,  156,    2, 0x0a,    7 /* Public */,
       7,    2,  161,    2, 0x0a,   10 /* Public */,
       8,    0,  166,    2, 0x08,   13 /* Private */,
       9,    0,  167,    2, 0x08,   14 /* Private */,
      10,    0,  168,    2, 0x08,   15 /* Private */,
      11,    0,  169,    2, 0x08,   16 /* Private */,
      12,    0,  170,    2, 0x08,   17 /* Private */,
      13,    0,  171,    2, 0x08,   18 /* Private */,
      14,    0,  172,    2, 0x08,   19 /* Private */,
      15,    0,  173,    2, 0x08,   20 /* Private */,
      16,    0,  174,    2, 0x08,   21 /* Private */,
      17,    0,  175,    2, 0x08,   22 /* Private */,
      18,    0,  176,    2, 0x08,   23 /* Private */,
      19,    0,  177,    2, 0x08,   24 /* Private */,
      20,    0,  178,    2, 0x08,   25 /* Private */,
      21,    0,  179,    2, 0x08,   26 /* Private */,
      22,    0,  180,    2, 0x08,   27 /* Private */,
      23,    0,  181,    2, 0x08,   28 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setR((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setG((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setB((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->pickColor(); break;
        case 4: _t->drawShape((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->updateCoords((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->clickedXY(); break;
        case 7: _t->clickedXZ(); break;
        case 8: _t->clickedZY(); break;
        case 9: _t->on_actionPutVoxel(); break;
        case 10: _t->on_actionCutVoxel(); break;
        case 11: _t->on_actionPutBox(); break;
        case 12: _t->on_actionCutBox(); break;
        case 13: _t->on_actionPutSpheare(); break;
        case 14: _t->on_actionCutSpheare(); break;
        case 15: _t->on_actionPutEllipsoid(); break;
        case 16: _t->on_actionCutEllipsoid(); break;
        case 17: _t->on_layerSliderXChange(); break;
        case 18: _t->on_layerSliderYChange(); break;
        case 19: _t->on_layerSliderZChange(); break;
        case 20: _t->on_newSculptor(); break;
        case 21: _t->on_actionExportOFF(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
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
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 22;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
