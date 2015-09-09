#include <QCoreApplication>
#include"file.h"
#include<QDebug>


int main(int argc, char *argv[])
{
    File inputFile("teste.txt");
    qDebug()<<inputFile.getFrequency('a');
    qDebug()<<inputFile.toString();
    qDebug()<<inputFile.toString();
    qDebug()<<inputFile.toString();
}

