#include <vector>
#include <iostream>
/**
 * How many ways can we change N with the given denominations
**/
class CoinChanger{
    public:
        //CoinChanger();
        CoinChanger(std::vector<int>);
        int howManyWays(int);
        void printLookup();
    private:
        std::vector<int> coins;
        std::vector<std::vector<int>> lookup;
};