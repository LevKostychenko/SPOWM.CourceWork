/****************************************************************************
** Meta object code from reading C++ file 'SniffManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CSniffer/SniffManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SniffManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SniffManager_t {
    QByteArrayData data[9];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SniffManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SniffManager_t qt_meta_stringdata_SniffManager = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SniffManager"
QT_MOC_LITERAL(1, 13, 14), // "package_append"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 13), // "close_sniffer"
QT_MOC_LITERAL(4, 43, 13), // "error_occured"
QT_MOC_LITERAL(5, 57, 17), // "SnifferException*"
QT_MOC_LITERAL(6, 75, 9), // "exception"
QT_MOC_LITERAL(7, 85, 11), // "start_sniff"
QT_MOC_LITERAL(8, 97, 10) // "stop_sniff"

    },
    "SniffManager\0package_append\0\0close_sniffer\0"
    "error_occured\0SnifferException*\0"
    "exception\0start_sniff\0stop_sniff"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SniffManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    1,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   44,    2, 0x0a /* Public */,
       8,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SniffManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SniffManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->package_append(); break;
        case 1: _t->close_sniffer(); break;
        case 2: _t->error_occured((*reinterpret_cast< SnifferException*(*)>(_a[1]))); break;
        case 3: _t->start_sniff(); break;
        case 4: _t->stop_sniff(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SniffManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SniffManager::package_append)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SniffManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SniffManager::close_sniffer)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SniffManager::*)(SnifferException * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SniffManager::error_occured)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SniffManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SniffManager.data,
    qt_meta_data_SniffManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SniffManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SniffManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SniffManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SniffManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SniffManager::package_append()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SniffManager::close_sniffer()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SniffManager::error_occured(SnifferException * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
