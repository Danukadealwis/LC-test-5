#pragma once
#include <cstdio>
#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <cmath>
#define USER_INPUT_SIZE 10
        enum class InputStatus {
            VALID,
            NO_INPUT,
//            DECIMAL_VALUE,
            INVALID_INPUT,
            OUT_OF_RANGE,
            MULTIPLE_INPUTS
        };

        static InputStatus GetInputNumber(unsigned long &input_number);
        void DisplayMessage(InputStatus input_status);
        static unsigned long GetReverseNumber(unsigned long number);
//        long SquareAndPrint(const unsigned long &value_a, const unsigned long &value_b);
        unsigned long CalculateResult(unsigned long value, unsigned long exponent);
