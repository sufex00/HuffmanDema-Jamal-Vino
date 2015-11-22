#include <QString>
#include <fstream>

class File
{
    //256 é escolhido pelo número de caracteres que dispõe a tabela ASC.
    int frequency[256]= {0};

    QString Dir;

    //std::ifstream file;

    //QFile Arquivo;

public:

    File(QString Endereco);
    QString toString();
    int getFrequency(int character);
    QString getNome();


};
