#ifndef BETTER_CELL_HPP
#define BETTER_CELL_HPP
#include <iostream>
#include <fstream>
#include <string>
class BetterCell{
    public:
    int val;
    bool* before; //[0]=left [1]=top [2]=diagonnaly
    BetterCell();
    ~BetterCell();
};

#endif //BETTER_CELL_HPP