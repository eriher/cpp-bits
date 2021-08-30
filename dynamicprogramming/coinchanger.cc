#include "coinchanger.h"

CoinChanger::CoinChanger(std::vector<int> c):coins(c),lookup(c.size(),std::vector<int>(1,0)){};

int CoinChanger::howManyWays(int n){
    // if(lookup.size() == 0){
    //     //first call, initilize and populate the lookuptable up to n
    //     lookup.resize(coins.size(),std::vector<int>(n+1,0));
    //     for(auto i = 1; i <= n; i++){
    //         int coin = coins[0];
    //         if(i == coins[0]) {
    //             lookup[0][i] = 1;
    //         } else if (i > coin) {
    //             lookup[0][i] = lookup[0][i-coin];
    //         }
    //     }
    //     for(auto i = 1; i < coins.size(); i++) {
    //         for(auto j = 1; j <= n; j++){
    //             auto coin = coins[i];
    //             if(j == coin) {
    //                 lookup[i][j] = 1+lookup[i-1][j];
    //             } else if (j > coin) {
    //                 lookup[i][j] = lookup[i][j-coin]+lookup[i-1][j];
    //             } else {
    //                 lookup[i][j] = lookup[i-1][j];
    //             }
    //         }
    //     }
    // }
    //std::cout << "n: " << n << std::endl;
    if(lookup[0].size()<=n){
        //std::cout << "not in cache" << std::endl;
        //N is not cached, need to calculate
        //start from previous end
        int startIndex = lookup[0].size()-1;
        //resize the table in one go instead of pusing one by one
        //std::cout << "lookup resized" << lookup.size() << ", " << lookup[0].size() << std::endl;
        //lookup.resize(coins.size(),std::vector<int>(10,0));
        for(auto i = 0; i < lookup.size(); i++)
            lookup[i].resize(n+1,0);
        //std::cout << "lookup resized" << lookup.size() << ", " << lookup[0].size() << std::endl;
        //first row is special case
        for(auto i = startIndex; i <= n; i++){
            int coin = coins[0];
            if(i == coins[0]) {
                lookup[0][i] = 1;
            } else if (i > coin) {
                lookup[0][i] = lookup[0][i-coin];
            }
        }
        for(auto i = 1; i < coins.size(); i++) {
            for(auto j = startIndex; j <= n; j++){
                auto coin = coins[i];
                if(j == coin) {
                    lookup[i][j] = 1+lookup[i-1][j];
                } else if (j > coin) {
                    lookup[i][j] = lookup[i][j-coin]+lookup[i-1][j];
                } else {
                    lookup[i][j] = lookup[i-1][j];
                }
            }
        }
    }
    return lookup[coins.size()-1][n];
};

void CoinChanger::printLookup(){
    for(auto i = 0; i < lookup.size(); i++){
        std::cout << coins[i] << ": ";
        for(auto j = 0; j < lookup[i].size(); j++){
            std::cout << lookup[i][j] << ", ";
        }
        std::cout << std::endl;
    }
};