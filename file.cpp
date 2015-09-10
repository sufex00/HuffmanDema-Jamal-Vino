#include "file.h"
#include<QDebug>

File::File(QString fileName)
{
    this->fileName=fileName;
    for(int i=0 ; i<256 ; i++)
    {
        this->frequency[i]=0;
    }
    QString file = this->toString();
    for(int i=0 ; i<file.size() ; i++)
    {
        int unsigned character;
        character=file.at(i).toLatin1();
        this->frequency[character]++;
    }
}

QString File::toString()
{
    char c;
    this->inputFile.open(this->fileName.toLatin1().data(), std::ios::binary);
    QString file;
    while(this->inputFile.get(c))
    {
        file.append(c);
    }
    this->inputFile.close();
    return file;
}

int File::getFrequency(char character)
{
    int unsigned intCharacter=character;
    return this->frequency[intCharacter];
}
