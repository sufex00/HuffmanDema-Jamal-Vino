QT += core
QT -= gui

TARGET = TreehuffmanOnly
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    treehuffman.cpp \
    nodes.cpp \
    file.cpp \
    bitvector.cpp

HEADERS += \
    treehuffman.h \
    nodes.h \
    file.h \
    bitvector.h

