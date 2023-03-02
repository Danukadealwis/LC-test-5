#pragma once
#include <cstdio>
#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <cmath>
#define USER_INPUT_SIZE 10

using namespace std;
namespace LargeNumbers {
    enum class InputStatus {
        VALID,
        NO_INPUT,
        INVALID_INPUT,
        OUT_OF_RANGE,
        MULTIPLE_INPUTS
    };
    class LargeNumberCalculator {
        public:
            InputStatus GetInputNumber(unsigned int &input_number);
            unsigned int GetReverseNumber(unsigned int number);
            void DisplayMessage(InputStatus input_status);
            string CalculateResult(unsigned int value, unsigned int exponent);
            string AddStrings(string addend_1, string addend_2);
            string MultiplyStrings(const string &input_1, const string &input_2);
    };
}