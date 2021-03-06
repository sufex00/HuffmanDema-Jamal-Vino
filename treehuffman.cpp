#include "treehuffman.h"
#include "file.h"
#include <QDebug>
#include <algorithm>
#include <QFileInfo>
#include <iostream>
#include<QString>

using namespace std;


TreeHuffman::TreeHuffman()
{
    this-> BagHuffman.reserve(260);   // escolhemos 260 para que não haja eventuais problemas de estouro de memória
}
void TreeHuffman::ordena() // função de ordenação
{
    std::sort (this->BagHuffman.begin(), this->BagHuffman.end());
}

void TreeHuffman::addNodes(Nodes newNodes){
    if(newNodes.getFrequency()>0)
    {
        this->BagHuffman.append(newNodes); // adiconando em filas o que estamos recebendo
        this->ordena();
    }
    //sort (this->BagHuffman.begin(), this->BagHuffman.end());
}
void TreeHuffman::Teste() //Função feita para testar se ele está ordenando tudo ok
{
    this->ordena();
    for(int i = 0; i < BagHuffman.size(); i++)
    {
        qDebug() << "Elemento: " << BagHuffman.at(i).getElement()<< "Frequencia :" << BagHuffman.at(i).getFrequency();
    }
}
void TreeHuffman::BuildHuffman() // Função feita para a parte mais importante a construção da árvore.
{
    int last;
    int beforeLast;
    int PlusLasts; // varável para a soma dos ultimos números.

    while(this->BagHuffman.size()!=1)
    {
        last = this->BagHuffman.at(this->BagHuffman.size() -1).getFrequency();
        beforeLast = this->BagHuffman.at(this->BagHuffman.size() -2).getFrequency();

        PlusLasts = last + beforeLast;

        Nodes *NodeL = new Nodes(); // criando esse node para transformar os elementos em ponteiros;; Node esquerdo
        Nodes *NodeR = new Nodes(); // Node direito

        *NodeL = this->BagHuffman.at(this->BagHuffman.size()-1);
        *NodeR = this->BagHuffman.at(this->BagHuffman.size() -2);

        Nodes LastNode = Nodes(NodeL, NodeR,PlusLasts);

        this->BagHuffman.remove(this->BagHuffman.size()-2, 2 );
        this->addNodes(LastNode);

    }
    this->root = this->BagHuffman[0];//Não pode ser usado o .at porque o valor dele não pode ser 'const'
}
void TreeHuffman::printTree(Nodes* node, int level)
{
    if(node->isLeaf() != true)
    {
        printTree(node->getLeft(), level +1);
        cout << qPrintable(QString("\t").repeated(level)) << node->getFrequency() << endl;
        printTree(node->getRight(), level +1);
    }
    if(node->isLeaf())
    {
        cout << qPrintable(QString("\t").repeated(level)) << "c=" << node->getCodification().toLatin1().data() << "e=" <<  node->getElement() <<endl;
    }
}

void TreeHuffman::BuildCodification(Nodes *root,long int level)
{
    if(root->isLeaf() == false)
    {
        BuildCodification(root->getRight(), 10*level + 1);
        BuildCodification(root->getLeft(),10*level);
    }

    if(root->isLeaf() == true)
    {

        root->setCodification(level);
        unsigned int character = root->getElement();
        this->huffmanRepresentationArray.insert(root->getElement(),root->getCodification());
    }
}

    QByteArray TreeHuffman::Sequency(Nodes *root)
    {


    }

void TreeHuffman::TreeHuffamanRepresetation(Nodes *root)
{
    if(root->isLeaf() == false)
    {
        this->treerepresetation.append(QString('*'));
        TreeHuffamanRepresetation(root->getLeft());
        TreeHuffamanRepresetation(root->getRight());
    }
    if(root->isLeaf()== true)
    {
        if(root->getElement() == '*'|| root->getElement()=='!')
        {
            this->treerepresetation.append(QString('!'));
        }
        this->treerepresetation.append(QString(root->getElement()));
    }

}
Nodes *TreeHuffman::getRoot()
{
    return  &this->BagHuffman[0];
}

QString TreeHuffman::getHuffmanRepresetation(char position)
{
    return this->huffmanRepresentationArray[position];

}

int TreeHuffman::TrashCalcutalion()
{
    int numberBits=0;

    int trash;

    File obj = File("teste.txt");

    for(unsigned int i=0; i<256; i++)
    {
        char p=i;
        numberBits += this->huffmanRepresentationArray[p].size() * obj.getFrequency((int)i);

    }
    trash= 8-(numberBits%8);
    if(trash ==8)
        trash=0;
    return trash;
}

QString TreeHuffman::getTreeRepresetation()
{
    return this->treerepresetation;
}

//------------- Transformar bits em Bytes--------------------

//QByteArray TreeHuffman::bitToByte(QBitArray bits)
//{
//    QByteArray bytes;

//    bytes.resize(bits.count()/8+1);
//    bytes.fill(0);

//    for(int b=0; b < bits.count(); ++b)
//        bytes[b/8] = (bytes.at(b/8) | ((bits[b]?1:0)<<(b%8)));

//    return bytes;
//}

//-------------------------------------------------------------


//QByteArray TreeHuffman::Header(QString path, int Trash){
//    QByteArray out;
//    QString name = QFileInfo(path).fileName();
//    out.append(QString::setNum(Trash,2));
//    out.append(QString::setNum(treerepresetation,2));
//    out.append(char(name.size()));
//    out.append(name);
//    out.append(treerepresetation);


//}
//-------------------------------------------------------------

//void TreeHuffman::createHeader(QString path,int trash){
//    buildRep(root);
//    QString trashStr;
//    QString treeLength;
//    QString pathLength;
//    pathLength.setNum(path.length(),2);
//    trashStr.setNum(trash,2);
//    treeLength.setNum(repTree.length(),2);
//    if(trashStr.length() != 3)
//        trashStr.insert(0,QString('0').repeated(3 - trashStr.length()));
//    if(treeLength.length() != 13)
//        treeLength.insert(0,QString('0').repeated(13 - treeLength.length()));
//    if(pathLength.length() != 256)
//        pathLength.insert(0,QString('0').repeated(256 - pathLength.length()));
//    //qDebug() << Q_FUNC_INFO << "Data Header:" << trashStr << treeLength << pathLength;
//    header = Util::toBinaryString(trashStr + treeLength);
//    header += Util::toBinaryString(pathLength);
//    header += path;
//    header += repTree;
//}
//--------------------------------------------------------------
