#include <vector>

template<typename T>
static int LinearSearch(std::vector<T>& vec, T val){
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] == val)
            return i;
    }
    return -1;
}