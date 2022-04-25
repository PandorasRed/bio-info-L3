#include <readMatrixFile.hpp>


/**
 * @brief not finished for now
 * 
 * @param fs 
 */
std::map<std::pair<char,char>, int> makeMap(std::ifstream& fs){
    std::map<std::pair<char,char>, int> score;    
    char str[100]; // declare the size of string      
    fs.getline(str,100); // use getline() function to read a string from input stream  
    char *ptr; // declare a ptr pointer  
    ptr = std::strtok(str, " , "); // use strtok() function to separate string using comma (,) delimiter.  
    // use while loop to check ptr is not null  
    char firstletter[23];
    int i=0;
    while (ptr != NULL)  
    {  
        firstletter[i]=*ptr;
        i++;
        ptr = std::strtok (NULL, " , ");  
        
    }  
    for(int c=0;c<23;c++){
        std::string tmp;
        getline(fs,tmp);
        int value[23];
        int v=0;
        std::string valuetmp;
        for(unsigned int i=2;i<tmp.length();i++){
            if(tmp.at(i)==','){
                value[v]=std::stoi(valuetmp,nullptr,10);
                v++;
                valuetmp="";
            }else{
                valuetmp.push_back(tmp.at(i));

            }
        }
        
        for(int k=0;k<23;k++) {

            std::pair<char,char> duo=std::pair<char,char>(firstletter[k],tmp.at(0));
            score.insert( std::pair<std::pair<char,char>,int>(duo,value[k]) );
            //std::stoi(secondtmp[k]
        }

        
    }

    return score;
    /*std::string tmp;
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
    }*/

    

}