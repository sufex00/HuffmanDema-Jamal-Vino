#include "compression.h"

compression::compression()
{

}

void compression::operation(TreatmentHeader TreatmentHeader)
{
    BitVector bitArray = BitVector();
    QString fileIn=QString(TreatmentHeader.getFileInput());
    //qDebug()<<fileIn;
    QString fileOut=QString(TreatmentHeader.getFileOutput());
    File obj = File(fileIn);
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
    fileObjectOutput.open(fileOut.toLatin1().data(),std::ios::binary);
    for(int i=0; i<bitArray.getQbitarray(false).size();i++)
    {
        fileObjectOutput<<bitArray.getQbitarray(false).at(i).toLatin1();
    }
    fileObjectOutput<<obj.getNome().toStdString();
    fileObjectOutput<<teste.getTreeRepresetation().toStdString();
    bitArray.clearBitVector();
    for(int i=0 ; i<obj.getSize() ; i++)
    {
        qDebug()<<(float)i/obj.getSize();
        char character = obj.toString(i);
        bitArray.setbit(teste.getHuffmanRepresetation(character));
    }
    for(int i=0; i<bitArray.getQbitarray().size();i++)
    {
        fileObjectOutput<<bitArray.getQbitarray().at(i).toLatin1();
    }
    bitArray.resize();
}

