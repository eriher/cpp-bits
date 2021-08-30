#include "knapsack.h"

Knapsack::Knapsack(int capacity):capacity(capacity),lookup(capacity+1,std::vector<int>{0}){};

int Knapsack::storeItems(std::vector<std::pair<int,int>> items){
    //increment capacity by 1 and consider each item
    //either we go with previous or we take item and what fits in remaining capacity
    //items need to be sorted according to weight
    std::sort(items.begin(),items.end(),[](auto& a, auto& b) {return a.first < b.second;});
    for(auto& row:lookup)
        row.resize(items.size()+1,0);
    
    for(auto i = 1; i < lookup.size(); i++){
        for(auto j = 1; j < lookup[i].size(); j++){
            int capacity = i;
            int weight = items[j-1].first;
            int value = items[j-1].second;
            if(weight <= capacity){
                lookup[i][j] = std::max(lookup[i][j-1],value+lookup[capacity-weight][j-1]);
            } else {
                lookup[i][j] = lookup[i][j-1];
            }
        }
    }
    //printLookup();
    return lookup[lookup.size()-1][lookup[0].size()-1];
}

int Knapsack::getCapacity(){
    return capacity;
}

void Knapsack::printLookup(){
    for(auto i = 0; i < lookup.size(); i++){
        std::cout << i << ": ";
        for(auto j = 0; j < lookup[i].size(); j++){
            std::cout << lookup[i][j] << ", ";
        }
        std::cout << std::endl;
    }
};