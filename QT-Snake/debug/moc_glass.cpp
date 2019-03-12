/****************************************************************************
** Meta object code from reading C++ file 'glass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../glass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'glass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Glass_t {
    QByteArrayData data[17];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Glass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Glass_t qt_meta_stringdata_Glass = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Glass"
QT_MOC_LITERAL(1, 6, 15), // "signalGlassInit"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "setScore"
QT_MOC_LITERAL(4, 32, 17), // "changePauseButton"
QT_MOC_LITERAL(5, 50, 14), // "sendNextFigure"
QT_MOC_LITERAL(6, 65, 7), // "Figure*"
QT_MOC_LITERAL(7, 73, 14), // "stopNextFigure"
QT_MOC_LITERAL(8, 88, 5), // "bool*"
QT_MOC_LITERAL(9, 94, 7), // "setRows"
QT_MOC_LITERAL(10, 102, 4), // "rows"
QT_MOC_LITERAL(11, 107, 10), // "setColumns"
QT_MOC_LITERAL(12, 118, 7), // "columns"
QT_MOC_LITERAL(13, 126, 13), // "slotGlassInit"
QT_MOC_LITERAL(14, 140, 11), // "slotNewGame"
QT_MOC_LITERAL(15, 152, 9), // "pauseGame"
QT_MOC_LITERAL(16, 162, 8) // "stopGame"

    },
    "Glass\0signalGlassInit\0\0setScore\0"
    "changePauseButton\0sendNextFigure\0"
    "Figure*\0stopNextFigure\0bool*\0setRows\0"
    "rows\0setColumns\0columns\0slotGlassInit\0"
    "slotNewGame\0pauseGame\0stopGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Glass[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       2,   90, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    1,   70,    2, 0x06 /* Public */,
       4,    0,   73,    2, 0x06 /* Public */,
       5,    1,   74,    2, 0x06 /* Public */,
       7,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   80,    2, 0x0a /* Public */,
      11,    1,   83,    2, 0x0a /* Public */,
      13,    0,   86,    2, 0x0a /* Public */,
      14,    0,   87,    2, 0x0a /* Public */,
      15,    0,   88,    2, 0x0a /* Public */,
      16,    0,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 8,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt,   10,
    QMetaType::Void, QMetaType::UInt,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      10, QMetaType::UInt, 0x00095103,
      12, QMetaType::UInt, 0x00095103,

       0        // eod
};

void Glass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Glass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalGlassInit(); break;
        case 1: _t->setScore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changePauseButton(); break;
        case 3: _t->sendNextFigure((*reinterpret_cast< Figure*(*)>(_a[1]))); break;
        case 4: _t->stopNextFigure((*reinterpret_cast< bool*(*)>(_a[1]))); break;
        case 5: _t->setRows((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 6: _t->setColumns((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 7: _t->slotGlassInit(); break;
        case 8: _t->slotNewGame(); break;
        case 9: _t->pauseGame(); break;
        case 10: _t->stopGame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Glass::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Glass::signalGlassInit)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Glass::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Glass::setScore)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Glass::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Glass::changePauseButton)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Glass::*)(Figure * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Glass::sendNextFigure)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Glass::*)(bool * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Glass::stopNextFigure)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Glass *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< uint*>(_v) = _t->rows(); break;
        case 1: *reinterpret_cast< uint*>(_v) = _t->rows(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Glass *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRows(*reinterpret_cast< uint*>(_v)); break;
        case 1: _t->setColumns(*reinterpret_cast< uint*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Glass::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Glass.data,
    qt_meta_data_Glass,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Glass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Glass::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Glass.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Glass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Glass::signalGlassInit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Glass::setScore(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Glass::changePauseButton()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Glass::sendNextFigure(Figure * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Glass::stopNextFigure(bool * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
