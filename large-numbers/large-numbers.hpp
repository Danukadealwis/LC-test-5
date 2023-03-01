#pragma once
#include <cstdio>
#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <cmath>
#define USER_INPUT_SIZE 10
namespace LargeNumbers {
    class LargeNumberCalculator{
    private:
        enum class InputStatus {
            VALID,
            NO_INPUT,
//            DECIMAL_VALUE,
            INVALID_INPUT,
            OUT_OF_RANGE,
            MULTIPLE_INPUTS,

        };

        static InputStatus GetInputNumber(uint64_t &input_number);
        static void DisplayMessage(InputStatus input_status);
        static uint64_t GetReverseNumber(uint64_t number);
//        long SquareAndPrint(const uint64_t &value_a, const uint64_t &value_b);
        uint64_t SquareInteger(uint64_t value, uint64_t exponent);

    };
}