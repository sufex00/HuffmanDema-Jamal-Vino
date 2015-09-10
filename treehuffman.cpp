#include "treehuffman.h"

TreeHuffman::TreeHuffman(File inputFile)
{
    this->size=0;
    this->arrayHuffman.reserve(260);
    for(unsigned int i=0 ; i<256 ; i++)
    {
        char character=i;
        Cell aux_cell = Cell (inputFile.getFrequency(i), character);
        this->arrayHuffman[size++]=aux_cell;
    }
}


