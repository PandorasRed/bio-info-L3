#ifndef NWMATRIX_HPP
#define NWMATRIX_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <Data.hpp>
#include <BetterCell.hpp>
class NWMatrix{
    public:
    BetterCell* matrix; //the full matrix for the algorithm
    Data data; // the entry
    int ls1; //the length of the string1;
    int ls2; //the lenght of the string2;
    NWMatrix(Data data); 
    ~NWMatrix();
    BetterCell  processing();
};

#endif //NWMATRIX_HPP