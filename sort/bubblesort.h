#include <vector>

template<typename T>
static std::vector<T> BubbleSort(std::vector<T> vec){
    auto swaps = true;
    while(swaps){
        swaps = false;
        for(auto i = 0, j = 1; j < vec.size(); i++,j++){
            if(vec[i]>vec[j]){
                swaps = true;
                auto temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
    return vec;
}