#include "LargeNumbers.hpp"
using namespace std;
using namespace LargeNumbers;
int main(){
    LargeNumberCalculator largeNumberCalculator;
    unsigned int value_a;
    InputStatus input_status = InputStatus::NO_INPUT;
    while(input_status != InputStatus::VALID ){
        largeNumberCalculator.DisplayMessage(input_status);
        input_status = largeNumberCalculator.GetInputNumber(value_a);
    }
    auto value_b = largeNumberCalculator.GetReverseNumber(value_a);
    const auto value_c = largeNumberCalculator.CalculateResult(value_a, value_b);
    cout << "Result: " << value_a << "^" << value_b << " " << value_c << endl;
}