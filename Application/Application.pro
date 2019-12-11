QT += quick
QT += sql
QT += core
QT += gui
QT += quickcontrols2

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
    src/user.cpp \
    src/usermodel.cpp \
    src/userreader.cpp \
    src/customer.cpp \
    src/customerreader.cpp \
    src/customermodel.cpp \
    src/order.cpp \
    src/orderreader.cpp \
    src/ordermodel.cpp
RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH += $$PWD/qml
QML2_IMPORT_PATH += $$PWD/qml

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

INCLUDEPATH += $$PWD/include
INCLUDEPATH += $$PWD/../shared/include

LIBS += -L$$PWD/../shared/lib/ -lDBManager

HEADERS += \
    include/user.h \
    include/userreader.h \
    include/usermodel.h \
    include/customerreader.h \
    include/customer.h \
    include/customermodel.h \
    include/order.h \
    include/ordermodel.h \
    include/orderreader.h
