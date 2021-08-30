// tasksSummation.cpp

#include <chrono>
#include <future>
#include <iostream>
#include <random>
#include <thread>
#include <utility>
#include <vector>

constexpr long long size = 100000000;

constexpr long long fir = 25000000;
constexpr long long sec = 50000000;
constexpr long long thi = 75000000;
constexpr long long fou = 100000000;

long sumUp(const std::vector<int>& val, unsigned long long beg, unsigned long long end){
    unsigned long long sum={};
    for (auto i = beg; i < end; ++i){
        sum += val[i];
    }
    return sum;
}

int main(){

    std::cout << std::endl;
    std::vector<int> randValues;
    randValues.reserve(size);

    std::mt19937 engine;
    std::uniform_int_distribution<> uniformDist(1,10);
    for (long long i = 0; i < size; ++i)
        randValues.push_back(uniformDist(engine));

    auto fut1= std::async(sumUp, std::ref(randValues), 0, fir);
    auto fut2= std::async(sumUp, std::ref(randValues), fir, sec);
    auto fut3= std::async(sumUp, std::ref(randValues), sec, thi);
    auto fut4= std::async(sumUp, std::ref(randValues), thi, fou);
    
    {
        const auto sta = std::chrono::system_clock::now();

        auto sum= fut1.get() + fut2.get() + fut3.get() + fut4.get();

        std::chrono::duration<double> dur= std::chrono::system_clock::now() - sta;
        std::cout << "Time for parallel addition " << dur.count() << " seconds" << std::endl;
        std::cout << "Result: " << sum << std::endl;
        std::cout << std::endl;
    }
    {
        const auto sta = std::chrono::steady_clock::now();
        const unsigned long long sum = std::accumulate(randValues.begin(), randValues.end(), 0);

        const std::chrono::duration<double> dur =
            std::chrono::steady_clock::now() - sta;

        std::cout << "Time for mySummation " << dur.count() << " seconds" << std::endl;
        std::cout << "Result: " << sum << std::endl;
        std::cout << std::endl;
    }




}