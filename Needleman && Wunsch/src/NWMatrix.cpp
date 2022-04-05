#include <NWMatrix.hpp>
    NWMatrix::NWMatrix(Data tdata){
        data=tdata;
        ls1=data.string1.length();
        ls2=data.string2.length();
        matrix=new BetterCell[ls1*ls2];//one dimmensional array because C++ is stupid;

    }
    //the destructor
    NWMatrix::~NWMatrix(){
    }

    BetterCell  NWMatrix::processing(){
        for(int i=0;i<ls1;i++){
            matrix[i].val=i*data.gappenalty; // to setup the first line;
            matrix[i].before[0]=true;// to alway setup the before to the left;
        }
        int j=0;
        for(j=ls1;j<ls1*ls2;j+=ls1);{
            matrix[j].val=(j/ls1)*data.gappenalty; // to setup the first line;
            matrix[j].before[0]=true;// to alway setup the before to the left;
        }
    }