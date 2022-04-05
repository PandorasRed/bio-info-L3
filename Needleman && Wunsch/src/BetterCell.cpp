#include <BetterCell.hpp>
    BetterCell::BetterCell(){
        val=0;
        before=new bool[3];
    }
    //the destructor
    BetterCell::~BetterCell(){
        delete[] before;
    }

