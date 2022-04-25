#include <Data.hpp>
    Data::Data(std::map<std::pair<char,char>, int> tscore,std::string s1, std::string s2, int penalty){
        score=tscore;
        string1=s1;
        string2=s2;
        gappenalty=penalty;
    } 
    Data::Data(){

    }
    //the destructor
    Data::~Data(){
    }

