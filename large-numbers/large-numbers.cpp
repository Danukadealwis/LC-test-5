#include "large-numbers.hpp"


using namespace LargeNumbers;
using namespace std;


LargeNumberCalculator::InputStatus LargeNumberCalculator::GetInputNumber(uint64_t &input_number){
    char user_input[USER_INPUT_SIZE];
    cin.getline(user_input, USER_INPUT_SIZE);
    auto input_1 = strtok(user_input, " ");
    if (!input_1){
        return InputStatus::NO_INPUT;
    }
    auto input_2 = strtok(user_input, " ");
    if(input_2){
        return InputStatus::MULTIPLE_INPUTS;
    }
    if(!sscanf(input_1, "%d", &input_number)){
        return InputStatus::INVALID_INPUT;
    }
    if(input_number < 0 || input_number > 99999){
        return InputStatus::OUT_OF_RANGE;
    }
    return InputStatus::VALID;
}

void LargeNumberCalculator::DisplayMessage(InputStatus input_status){
    switch(input_status){
        case InputStatus::INVALID_INPUT:
            cout << "Input was invalid" << endl;
            break;
        case InputStatus::OUT_OF_RANGE:
            cout << "Input was out of range" << endl;
            break;
        case InputStatus::MULTIPLE_INPUTS:
            cout << "There were multiple inputs" << endl;
            break;
        default :
            break;
    }
    cout << "Enter a number (0-99999): ";
}

uint64_t LargeNumberCalculator::GetReverseNumber(uint64_t number){
    uint64_t reversed_number = 0, remainder;

    while(number != 0) {
        remainder = number % 10;
        reversed_number = reversed_number * 10 + remainder;
        number /= 10;
    }

    cout << "Reversed Number = " << reversed_number;

    return reversed_number;
}

uint64_t LargeNumberCalculator::SquareInteger(uint64_t value, uint64_t exponent){
    if(exponent == 0) return 1;
    if(exponent == 1) return value;
    uint64_t temp = SquareInteger(value, exponent/2);
    if(exponent % 2 == 0) { return temp * temp;}
    else { return value * temp *temp;}
}



void LargeNumberCalculator::Run(){
    uint64_t value_a;
    InputStatus input_status = InputStatus::NO_INPUT;
    while(input_status != InputStatus::VALID ){
        DisplayMessage(input_status);
        input_status = GetInputNumber(value_a);
    }
    const auto value_b = GetReverseNumber(value_a);
    const auto value_c = SquareInteger(value_a, value_b);
    cout << value_c << endl;

}

