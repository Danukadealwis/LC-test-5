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

    output = largeNumberCalculator.CalculateResult(123,321);
    CHECK(output == "72367033806371673149109894141163778628811792657571658906010558390395"
                    "87036379840174409528068615550773640492165707028496172182896059297790"
                    "95426370988976972231026226285667876540913278254539915951402057014129"
                    "61364188732408936197890553699715836951569999800431957769217006743321"
                    "02625751793276416466231948791496253330274136820721118949461532655279"
                    "06677204112854741626367651689072119241349733743044960196353766658585"
                    "59941735703924836467756917247995469583487467791524582153744522107597"
                    "86527779813608007416148528042427407693108399448711171956224970254036"
                    "28557129111322659662357543553535167033390430015061185207603595777378"
                    "69472018617942120590873170710805078696371738906375721785723");

}

