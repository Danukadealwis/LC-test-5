#include <doctest/doctest.h>
#include "../../large-numbers/LargeNumbers.hpp"

using namespace LargeNumbers;
TEST_CASE("Test Add Strings"){
    LargeNumberCalculator largeNumberCalculator;
    auto output = largeNumberCalculator.AddStrings("123","23");
    CHECK(output == "146");

    output = largeNumberCalculator.AddStrings("12","0");
    CHECK(output == "12");

    output = largeNumberCalculator.AddStrings("23812","273");
    CHECK(output == "24085");
}

TEST_CASE("Test Multiply Strings"){
    LargeNumberCalculator largeNumberCalculator;

    auto output = largeNumberCalculator.MultiplyStrings("12","13");
    CHECK(output == "156");

    output = largeNumberCalculator.MultiplyStrings("0","13");
    CHECK(output == "0");

    output = largeNumberCalculator.MultiplyStrings("0231","13");
    CHECK(output == "3003");
    output = largeNumberCalculator.MultiplyStrings("1228563","548");
    CHECK(output == "673252524");
    output = largeNumberCalculator.MultiplyStrings("81","9");
    CHECK(output == "729");

    output = largeNumberCalculator.MultiplyStrings("5159780352","12");
    CHECK(output == "61917364224");
}

TEST_CASE("Test Exponential Arithmetic"){
    LargeNumberCalculator largeNumberCalculator;
    auto output = largeNumberCalculator.CalculateResult(3,3);
    CHECK(output == "27");

    output = largeNumberCalculator.CalculateResult(9,9);
    CHECK(output == "387420489");

    output = largeNumberCalculator.CalculateResult(12,12);
    CHECK(output == "8916100448256");

}

