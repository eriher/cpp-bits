#include <vector>
#include <algorithm>
#include <iostream>

class Knapsack{
    public:
        Knapsack(int);
        int storeItems(std::vector<std::pair<int,int>>);
        int getCapacity();
        void printLookup();
    private:
        int capacity;
        std::vector<std::vector<int>> lookup;
};