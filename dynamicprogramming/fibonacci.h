#include <vector>
#include <iostream>
/**
 * Get Nth fibonnaci number
**/
class Fibonacci{
    public:
        Fibonacci();
        long long numInSeq(int);
        void printLookup();
    private:
        std::vector<long long> lookup;
};