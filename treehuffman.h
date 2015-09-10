#ifndef TREEHUFFMAN_H
#define TREEHUFFMAN_H

#include"cell.h"
#include"file.h"
#include<vector>

class TreeHuffman
{
    std::vector<Cell> arrayHuffman;
    int size;
    //Cell poiter;
public:
    TreeHuffman(File inputFile);


};

#endif // TREEHUFFMAN_H
