#-------------------------------------------------
#
# Project created by QtCreator 2015-09-09T09:44:37
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Codificacao-Huffman
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    treehuffman.cpp \
    nodes.cpp \
    descompression.cpp \
    bitvector.cpp \
     FileTree.cpp

HEADERS += \
    treehuffman.h \
    nodes.h \
    descompression.h \
    bitvector.h \
     FileTree.h

