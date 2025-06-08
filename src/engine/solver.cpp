#include "solver.hpp"

ConnectEngine::ConnectEngine(){
}

int ConnectEngine::solve(uint64_t bitmap){
    static int temp = -1;

    if (temp > 5 ){
        temp = 0;
    }
    else{
        temp++;
    }

    return temp;
}
