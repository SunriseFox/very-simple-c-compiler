TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt



SOURCES += \
    main.cpp \
    symbol.cpp \
    tree.cpp \
    scope.cpp

HEADERS += \
    common.h \
    pch.h \
    symbol.h \
    tree.h \
    main.tab.h \
    scope.h
