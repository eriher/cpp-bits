#include <vector>


template<typename T>
static std::vector<T> SelectionSort(std::vector<T> vec){
    for(auto i = 0; i < vec.size(); i++){
        auto low = i;
        for(auto j = i+1; j < vec.size(); j++){
            if(vec[j] < vec[low])
                low = j;
        }
        if(low != i){
            auto temp = vec[i];
            vec[i] = vec[low];
            vec[low] = temp;
        }
    }
    return vec;
}