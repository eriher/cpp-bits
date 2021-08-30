#include <gtest/gtest.h>

#include "fibonacci.h"

namespace {
    TEST(FibonacciTest,1and2){
        Fibonacci fib;
        ASSERT_EQ(fib.numInSeq(1),0);
        ASSERT_EQ(fib.numInSeq(2),1);
    }

    TEST(FibonacciTest,3){
        Fibonacci fib;
        ASSERT_EQ(fib.numInSeq(3),1);
    }
    
    TEST(FibonacciTest,11){
        Fibonacci fib;
        ASSERT_EQ(fib.numInSeq(11),55);
    }
    TEST(FibonacciTest,50){
        Fibonacci fib;
        ASSERT_EQ(fib.numInSeq(50),7778742049);
    }
}
