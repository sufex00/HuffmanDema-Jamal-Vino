QT += core
QT -= gui

TARGET = Huffman
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    file.cpp \
    cell.cpp \
    treehuffman.cpp

HEADERS += \
    file.h \
    cell.h \
    treehuffman.h

