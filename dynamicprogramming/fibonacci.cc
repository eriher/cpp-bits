#include "fibonacci.h"

Fibonacci::Fibonacci():lookup{0,1}{};

long long Fibonacci::numInSeq(int n){
    if(lookup.size() >= n)
        return lookup[n-1];
    long long result = numInSeq(n-1)+numInSeq(n-2);
    lookup.push_back(result);
    return result;
};

void Fibonacci::printLookup(){
    for(auto i = 0; i < lookup.size(); i++){
        std::cout << lookup[i] << ", ";
    }
    std::cout << std::endl;
};