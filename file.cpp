#include "file.h"
#include <QDebug>
#include <QString>
#include<QFile>


// O construtor abre todas as informações que a classe precisa para ser aberta

File::File(QString Endereco)
    {

        //Todas as vezes que eu quiser alterar algo numa classe tenho que usar esse this.
        std::ifstream file;
        this-> Dir = Endereco;

        this->size=1;

        file.open (this->Dir.toLatin1().data(), std::ifstream::in);

        QString aux1 = this->toString();

        this->file=this->toString();

        std::ifstream ifs;
        ifs.open (this->Dir.toLatin1().data(), std::ios::binary);
        char c;
        c = ifs.get();
        int i=0;
        while (ifs.good())
        {
           this->frequency[this->toString(i)]++;
           c = ifs.get();
           size++;
           i++;
        }

       //Esse for pega tudo que tem no arquivo, lido no aux, e ordena


    }

    QByteArray File::toString()
    {

        QString PathFile;
        QString aux;
        std::ifstream ifs;
        ifs.open (this->Dir.toLatin1().data(), std::ios::binary);
        unsigned int c = ifs.get();
        QByteArray p = QByteArray();
        while (ifs.good())
        {
            if(c<0)
                p.append(c+256);
            else
                p.append(c);
            c = ifs.get();
        }
        return p;
    }

    int File::toString(int position)
    {
        QByteArray p = QByteArray();
        if(file.at(position)<0)
            return file.at(position)+256;
        else
            return file.at(position);
    }

    int File::readFile(int initPosition)
    {
        std::ifstream inputFile;
        inputFile.open (this->Dir.toLatin1().data(), std::ios::binary);
        QString file;
        char buff;
        inputFile.seekg(initPosition);
        inputFile.get(buff);
        if(buff<0)file.append(QString().setNum(buff+256));
        else
            file=(QString(QString().setNum((int)buff)));
        return file.toInt();
    }

    QString File::readFile(int initPosition, int sizeRead)
    {
        QString file;
        std::ifstream inputFile;
        inputFile.open (this->Dir.toLatin1().data(), std::ios::binary);
        if(sizeRead==-1)
        {

            inputFile.seekg(0,inputFile.end);
            sizeRead=inputFile.tellg();
            inputFile.seekg(0, inputFile.beg);
        }
        for(int i=initPosition;i<initPosition+sizeRead;i++)
        {
            file.append(readFile(i));
        }
        return file;
    }

    int File::getFrequency(int character)
    {
        return this->frequency[character];
    }

    QString File::getNome()
    {
        return this->Dir;
    }

    int File::getSize()
    {
        return this->size;
    }

