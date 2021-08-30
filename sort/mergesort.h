#include <vector>

template<typename T>
static std::vector<T> MergeSort(std::vector<T> vec){
    if(vec.size()<=1){
        return vec;
    }
    auto mid = vec.size()/2;
    auto left = MergeSort(std::vector<T>(vec.begin(),vec.begin()+mid));
    auto right = MergeSort(std::vector<T>(vec.begin()+mid,vec.end()));
    //merge
    std::vector<T> result;
    auto it1 = left.begin();
    auto it2 = right.begin();
    while(it1 != left.end() && it2 != right.end()){
        if(*it1 < *it2){
            result.push_back(*it1);
            it1++;
        }
        else{
            result.push_back(*it2);
            it2++;
        }
    }
    while(it1 != left.end())
        result.push_back(*it1++);
    while(it2 != right.end())
        result.push_back(*it2++);
    return result;
}

template<typename T>
static void MergeSort(std::vector<T>& vec, size_t start, size_t end){
    if(start<end){
        auto mid = (start+end)/2;
        MergeSort(vec,start,mid);
        MergeSort(vec,mid+1,end);
        
        //Merge
        auto leftIt = vec.begin()+start;
        auto rightIt = vec.begin()+mid+1;
        auto leftEnd = rightIt;
        auto rightEnd = vec.begin()+end+1;

        std::vector<T> temp;
        while(leftIt != leftEnd && rightIt != rightEnd){
            if(*leftIt < *rightIt){
                temp.push_back(*(leftIt++));
            }
            else{
                temp.push_back(*(rightIt++));
            }
        }
        while(leftIt != leftEnd)
            temp.push_back(*leftIt++);
        while(rightIt != rightEnd)
            temp.push_back(*rightIt++);
        
        auto vecIt = vec.begin()+start;
        for(auto it = temp.begin(); it != temp.end(); it++){
            *(vecIt++) = *it;
        }
    }
}
