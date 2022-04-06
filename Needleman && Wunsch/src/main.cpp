#include <main.hpp>

int main(int argc, char *argv[]){
    std::cout<<argc<<std::endl;
    std::string tmp(argv[1]);
    //we suppose user not ill-intentioned
    if(tmp=="-f"){ //case were we have 2 fasta file for the sequence
    	std::ifstream fs1(argv[2]);//ifstream of the fastaFile1
        std::ifstream fs2(argv[3]);//ifstream of the fastaFile2
        firstSuppr(fs1);
        firstSuppr(fs2);
        std::string tmp1=sequence(fs1);
        std::string tmp2=sequence(fs2);
        //int gappenalty=-8;

        std::map<std::pair<char,char>,int> matrix;




    }else{
        std::ifstream fs(argv[1]);//ifstream of the matrix file for test
        makeMap(fs);
    }



}