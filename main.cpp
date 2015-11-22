#include "treehuffman.h"
#include "file.h"
#include "bitvector.h"
#include<QDebug>
#include <fstream>



int main(int argc, char *argv[])
{

    BitVector bitArray = BitVector();
    File obj = File("teste.txt");
    TreeHuffman teste = TreeHuffman();
    std::ofstream fileObjectOutput;
    for(unsigned int i=0 ; i<256 ; i++)
    {
        char p = i;
        Nodes aux = Nodes(p, obj.getFrequency((int)i));
        teste.addNodes(aux);
    }
    //teste.Teste();
    teste.BuildHuffman();
    teste.BuildCodification(teste.getRoot());
    //teste.printTree(teste.getRoot());
    teste.TreeHuffamanRepresetation(teste.getRoot());
    bitArray.setbit(QString().setNum(teste.TrashCalcutalion(),2),3);
    bitArray.setbit(QString().setNum(teste.getTreeRepresetation().size(),2),13);
    bitArray.setbit(QString().setNum(obj.getNome().size(),2),8);
    fileObjectOutput.open("saida.huff",std::ios::binary);
    for(int i=0; i<bitArray.getQbitarray().size()-1;i++)
    {
        fileObjectOutput<<bitArray.getQbitarray().at(i).toLatin1();
    }
    fileObjectOutput<<obj.getNome().toStdString();
    fileObjectOutput<<teste.getTreeRepresetation().toStdString();
    bitArray.clearBitVector();
    for(int i=0 ; i<obj.toString().size() ; i++)
    {
        char character = obj.toString().at(i).toLatin1();
        bitArray.setbit(teste.getHuffmanRepresetation(character));
    }

    for(int i=0 ; i<bitArray.getsize(); i++)
    {
        qDebug()<<bitArray.bitVectorAt(i);
    }



    QString file = obj.toString();
    for(int i=0 ; i<file.size();i++)
    {
        //qDebug()<<teste.getTreeRepresetation();

    }




}
