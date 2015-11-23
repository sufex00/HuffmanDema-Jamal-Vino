#ifndef HUFFDECOTIFICATION_H
#define HUFFDECOTIFICATION_H
#include<QString>
#include"nodes.h"


class huffdecotification
{
    int sizeName;              //Tamanho do nome original do arquivo
    int sizeTree;              //Tamanho da representação da arvore
    int trash;                 //Tamanho do lixo
    int sizeFile;              //Tamanho
    QString fileName;          //Nome original do arquivo
    QString treeRepresetation; //Representação da arvore
    int position;              //Posição atual do curso
    char *FileObjectInput;     //Nome do arquivo
    bool isEndBool;            //Verificador se o arquivo acabou
public:
    huffdecotification(QString FileOutput);
    QString TreeRepresentation();
    bool isEnd();
    bool isElement(Nodes* node,QString HuffmanCodification);
    char getElementTree(Nodes* node,QString HuffmanCodification);
    int getTrash();
    int getSize();
    void printTree(Nodes* node, int level=0);
    QString TreeHuffmanTreeLeft(QString huff);
    QString TreeHuffmanTreeRight(QString huff);
    Nodes* generation(QString Tree);
    QString getFileName();
};

#endif // HUFFDECOTIFICATION_H
