#include <readMatrixFile.hpp>


/**
 * @brief not finished for now
 * 
 * @param fs 
 */
void makeMap(std::ifstream& fs){
    std::string tmp;
    getline(fs,tmp);
    std::vector<char> chartmp;
    char n=',';
    do{
        if((n!=',')||(n!=',')){
            chartmp.push_back(n);
        }
        n=fs.get();
    }while((n!=EOF) );
    for(unsigned int i=0;i<chartmp.size();i++){
        std::cout<<chartmp[i]<<std::endl;
    }

    

}