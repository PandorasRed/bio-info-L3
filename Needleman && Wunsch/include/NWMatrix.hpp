#ifndef NWMATRIX_HPP
#define NWMATRIX_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <Data.hpp>
class NWMatrix{
    public:
    int* score; //the matrix for the score
    int* direction; // the matrix to know the direction
    Data data; // the entry
    int ls1; //the length of the string1;
    int ls2; //the lenght of the string2;
    NWMatrix(Data data); 
    ~NWMatrix();
    void  processing();
    std::pair<int,int> best(char a,char b, int left,int top,int diagonal);
    std::pair<std::string, std::string> alignment();
    private:
    std::pair<std::string,std::string> recalignment(std::pair<std::string,std::string> a, int i);

};

#endif //NWMATRIX_HPP