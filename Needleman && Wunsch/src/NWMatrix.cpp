#include <NWMatrix.hpp>
    NWMatrix::NWMatrix(Data tdata){
        data=tdata;
        ls1=data.string1.length();
        ls2=data.string2.length();
        score=new int[ls1*ls2];
        direction=new int[ls1*ls2];

    }
    //the destructor
    NWMatrix::~NWMatrix(){
    }
    /**
     *  process the matrix after creation(possibly in the constructor later);
     * 
     */
    void  NWMatrix::processing(){
        for(int i=0;i<ls1;i++){
            score[i]=i*data.gappenalty; // to setup the first line;
            direction[i]=1;// to alway setup the before to the left;
        }
        int j=0;
        for(j=ls1;j<ls1*ls2;j+=ls1){
            score[j]=((j/ls1)-1)*data.gappenalty; // to setup the first colum;
            direction[j]=2;// to alway setup the before to the top;
        }
        for(int i=1;i<ls1;i++){
            for(int j=1;j<ls2;j++){
                std::pair<int,int> tmp=best(data.string1.at(i),data.string2.at(j),score[(i+j*ls1)-1],score[(i+(j-1)*ls1)],score[(i+(j-1)*ls1)-1]);
                score[i+j*ls1]=tmp.second;
                direction[i+j*ls1]=tmp.first;
            }
        }
    }
    /**
     * return the cell before and the score of the cell we want in the form of a pair;
     * @param a  char of the string1 to compare
     * @param b  char of the string2 to compare
     * @param left score of the cell to the left
     * @param top score of the cell to the top
     * @param diagonal  score of the cell top-left
     * @return the pair which said the score and which cell before has been taken, 3-bit style so we can have more than 1 cell at a time;
     */
    std::pair<int,int> NWMatrix::best(char a,char b, int left,int top,int diagonal){
        std::pair<char,char> c= std::make_pair(a,b);
        int tmp=data.score.at(c);
        diagonal+=tmp;
        left+=data.gappenalty;
        top+=data.gappenalty;
        if(diagonal==left && left==top){
            return std::make_pair(7,diagonal);
        }else{
            if(diagonal>left && diagonal > top){
                return std::make_pair(4,diagonal);
            }else if(diagonal<left && left>top){
                return std::make_pair(2,left);
            }else if(diagonal<left && left<top){
                return std::make_pair(1,top);
            }else if(diagonal==left && left>top){
                return std::make_pair(6,diagonal);
            }else if(diagonal==top && left<top){
                return std::make_pair(5,diagonal);
            }else{// if(top==left && top>diagonal)
                return std::make_pair(3,left);
            }
        }

    }
    std::pair<std::string, std::string> NWMatrix::alignment(){
        std::string a="";
        std::string b="";
        std::pair<std::string, std::string> tmps(a,b);
        int tmp=ls1*ls2 -1;
        return this->recalignment(tmps,tmp);
    }
    std::pair<std::string,std::string> NWMatrix::recalignment(std::pair<std::string,std::string> a, int i){
        if (i==0){
            return a;
        }else{
            int d=direction[i];
            switch(d){
                case 1: //top
                    a.first.push_back(data.string1.at(i%ls1));
                    a.second.push_back('-');
                    return this->recalignment(a,i-(ls1));
                    break;
                case 2: //left
                    a.first.push_back('-');
                    a.second.push_back(data.string1.at(i/ls1));
                    return this->recalignment(a,i-1);
                    break;
                case 3:
                    a.first.push_back('-');
                    a.second.push_back(data.string1.at(i/ls1));
                    return this->recalignment(a,i-1);
                    break;
                case 4:
                    a.first.push_back(data.string1.at(i%ls1));
                    a.second.push_back(data.string2.at(i/ls1));
                    return this->recalignment(a,i-(ls1+1));
                    break;
                case 5:
                    a.first.push_back(data.string1.at(i%ls1));
                    a.second.push_back(data.string2.at(i/ls1));
                    return this->recalignment(a,i-(ls1+1));
                    break;
                case 6:
                    a.first.push_back(data.string1.at(i%ls1));
                    a.second.push_back(data.string2.at(i/ls1));
                    return this->recalignment(a,i-(ls1+1));
                    break;
                case 7:
                    a.first.push_back(data.string1.at(i%ls1));
                    a.second.push_back(data.string2.at(i/ls1));
                    return this->recalignment(a,i-(ls1+1));
                    break;
            }
        }
        return a;

    }
    


    