#ifndef READMATRIXFILEHPP
#define READMATRIXFILEHPP
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <cstring>  
std::map<std::pair<char,char>, int> makeMap(std::ifstream& fs);

#endif //READMATRIXFILEHPP