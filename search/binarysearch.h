#include <vector>
#include <algorithm> // std::sort

template <typename T>
static int BinarySearch(std::vector<T> &vec, T val, int low, int high)
{
    int mid = (low + high) / 2;
    if (vec[mid] == val)
        return mid;
    if (low < high) {
        if (vec[mid] < mid) {
            return BinarySearch(vec, val, low, mid - 1);
        } else {
            return BinarySearch(vec, val, mid + 1, high);
        }
    }
    //Not found
    return -1;
}

template <typename T>
static int BinarySearch(std::vector<T> &vec, T val)
{
    if (vec.size() == 0) {
        return -1;
    }
    std::sort(vec.begin(), vec.end());
    return BinarySearch(vec, val, 0, vec.size() - 1);
}