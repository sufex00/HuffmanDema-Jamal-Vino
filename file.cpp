#include "file.h"
#include <QDebug>
#include <QString>
#include <QByteArray>
#include<QFile>


// O construtor abre todas as informações que a classe precisa para ser aberta

File::File(QString Endereco)
    {

        //Todas as vezes que eu quiser alterar algo numa classe tenho que usar esse this.
        std::ifstream file;
        this-> Dir = Endereco;

        file.open (this->Dir.toLatin1().data(), std::ifstream::in);

        QString aux1 = this->toString();

       //Esse for pega tudo que tem no arquivo, lido no aux, e ordena

        for(int i = 0; i<aux1.size(); i++){

        //O unsigned serve para retirar a parte negativa do número, o ponto at serve para indicara a posição que está o caractere
        unsigned int aux2 = aux1.at(i).toLatin1();

        this->frequency[aux2]++;
        }
    }

    QString File::toString()
    {

        QFile file(this->Dir);
        if(!file.open(QIODevice::ReadOnly))
            return QString(this->Dir);

        char ToRead;

        QString PathFile;

        QTextStream in(&file);
        while(!in.atEnd()){
            PathFile.append(in.readAll());
        }

        return PathFile;
    }

    int File::getFrequency(int character)
    {
        return this->frequency[character];
    }

    QString File::getNome()
    {
        return this->Dir;
    }
