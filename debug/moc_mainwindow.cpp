/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "find_path",
    "",
    "checkForUpdateReady",
    "set_descr_and_img",
    "set_chosen_maps",
    "set_default_maps",
    "readSocket",
    "on_pushButtonClose_clicked",
    "on_checkBoxChooseAll_stateChanged",
    "arg1",
    "on_pushButtonOnMode_clicked",
    "on_pushButtonOffMode_clicked",
    "changeItemColor"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[11];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[18];
    char stringdata5[16];
    char stringdata6[17];
    char stringdata7[11];
    char stringdata8[27];
    char stringdata9[34];
    char stringdata10[5];
    char stringdata11[28];
    char stringdata12[29];
    char stringdata13[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 9),  // "find_path"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 19),  // "checkForUpdateReady"
        QT_MOC_LITERAL(42, 17),  // "set_descr_and_img"
        QT_MOC_LITERAL(60, 15),  // "set_chosen_maps"
        QT_MOC_LITERAL(76, 16),  // "set_default_maps"
        QT_MOC_LITERAL(93, 10),  // "readSocket"
        QT_MOC_LITERAL(104, 26),  // "on_pushButtonClose_clicked"
        QT_MOC_LITERAL(131, 33),  // "on_checkBoxChooseAll_stateCha..."
        QT_MOC_LITERAL(165, 4),  // "arg1"
        QT_MOC_LITERAL(170, 27),  // "on_pushButtonOnMode_clicked"
        QT_MOC_LITERAL(198, 28),  // "on_pushButtonOffMode_clicked"
        QT_MOC_LITERAL(227, 15)   // "changeItemColor"
    },
    "MainWindow",
    "find_path",
    "",
    "checkForUpdateReady",
    "set_descr_and_img",
    "set_chosen_maps",
    "set_default_maps",
    "readSocket",
    "on_pushButtonClose_clicked",
    "on_checkBoxChooseAll_stateChanged",
    "arg1",
    "on_pushButtonOnMode_clicked",
    "on_pushButtonOffMode_clicked",
    "changeItemColor"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x0a,    1 /* Public */,
       3,    0,   81,    2, 0x0a,    2 /* Public */,
       4,    0,   82,    2, 0x0a,    3 /* Public */,
       5,    0,   83,    2, 0x0a,    4 /* Public */,
       6,    0,   84,    2, 0x0a,    5 /* Public */,
       7,    0,   85,    2, 0x08,    6 /* Private */,
       8,    0,   86,    2, 0x08,    7 /* Private */,
       9,    1,   87,    2, 0x08,    8 /* Private */,
      11,    0,   90,    2, 0x08,   10 /* Private */,
      12,    0,   91,    2, 0x08,   11 /* Private */,
      13,    0,   92,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'find_path'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'checkForUpdateReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'set_descr_and_img'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'set_chosen_maps'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'set_default_maps'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readSocket'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonClose_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_checkBoxChooseAll_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pushButtonOnMode_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonOffMode_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeItemColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->find_path(); break;
        case 1: _t->checkForUpdateReady(); break;
        case 2: _t->set_descr_and_img(); break;
        case 3: _t->set_chosen_maps(); break;
        case 4: _t->set_default_maps(); break;
        case 5: _t->readSocket(); break;
        case 6: _t->on_pushButtonClose_clicked(); break;
        case 7: _t->on_checkBoxChooseAll_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->on_pushButtonOnMode_clicked(); break;
        case 9: _t->on_pushButtonOffMode_clicked(); break;
        case 10: _t->changeItemColor(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
