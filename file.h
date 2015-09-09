#ifndef FILE_H
#define FILE_H

#include<fstream>
#include<QString>


class File
{
    std::ifstream inputFile;
    QString fileName;
    int frequency[256];
public:
    File(QString fileName);
    QString toString();
    int getFrequency(char character);


};

#endif // FILE_H
