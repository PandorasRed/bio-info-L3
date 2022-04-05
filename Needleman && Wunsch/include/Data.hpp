#ifndef DATA_HPP
#define DATA_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <map>
class Data{
    public:
    std::map<std::pair<char,char>, int> score;//to check the score with 2char as entry; maybe gonna do a new object in place of the pair
    int gappenalty;// the gappenalty
    std::string string1; //string1 to compare
    std::string string2; //string2 to compare
    Data(std::map<std::pair<char,char>, int> tscore,std::string s1, std::string s2, int penalty); 
    Data();//stupid compilator
    ~Data();
};
#endif //DATA_HPP