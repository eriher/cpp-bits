#include <vector>

template<typename T>
static std::vector<T> QuickSort(std::vector<T> vec){
    if(vec.size() < 2)
        return vec;
    auto left = 0;
    auto right = vec.size()-1;
    auto midIndex = right/2;
    auto midValue = vec[midIndex];
    while(left < right){
        while(vec[left]<=midValue && left < midIndex)
            left++;
        while(vec[right]>=midValue && right > midIndex)
            right--;
        if(vec[left] > vec[right])
        {
            auto temp = vec[left];
            vec[left] = vec[right];
            vec[right] = temp;
            if (left==midIndex)
            {
                midIndex = right;
            } else if (right==midIndex){
                midIndex = left;
            }
        }
    }
    auto result = QuickSort(std::vector<T>{vec.begin(),vec.begin()+midIndex});
    result.push_back(midValue);
    auto upper = QuickSort(std::vector<T>{vec.begin()+midIndex+1,vec.end()});
    result.insert(result.end(),upper.begin(),upper.end());
    
    return result;
}

template<typename T>
static void QuickSort(std::vector<T>& vec, int _left, int _right){
    int left = _left;
    int right = _right;
    if(left<right)
    {   
        auto midIndex = (left+right)/2;
        auto midValue = vec[midIndex];
        while(left < right){
            while(vec[left]<=midValue && left < midIndex)
                left++;
            while(vec[right]>=midValue && right > midIndex)
                right--;
            if(vec[left] > vec[right])
            {
                auto temp = vec[left];
                vec[left] = vec[right];
                vec[right] = temp;
                if (left==midIndex)
                {
                    midIndex = right;
                } else if (right==midIndex){
                    midIndex = left;
                }
            }
        }
        QuickSort(vec,_left,midIndex-1);
        QuickSort(vec,midIndex+1,_right);
    }
}