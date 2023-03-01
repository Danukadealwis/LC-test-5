#include "large-numbers.hpp"

using namespace std;

InputStatus GetInputNumber(unsigned long &input_number){
    char user_input[USER_INPUT_SIZE];
    cin.getline(user_input, USER_INPUT_SIZE);
    auto input_1 = strtok(user_input, " ");
    if (!input_1){
        return InputStatus::NO_INPUT;
    }
    auto input_2 = strtok(nullptr, " ");
    if (input_2){
        return InputStatus::MULTIPLE_INPUTS;
    }
    for(int i = 0; i < strlen(input_1); ++i) {
        auto current_char = input_1[i];
        if(!isdigit(current_char))
            return InputStatus::INVALID_INPUT;
    }
    if(!sscanf(input_1, "%lu", &input_number)){
        return InputStatus::INVALID_INPUT;
    }
    if(input_number < 0 || input_number > 99999){
        return InputStatus::OUT_OF_RANGE;
    }
    return InputStatus::VALID;
}

void DisplayMessage(InputStatus input_status){
    switch(input_status){
        case InputStatus::INVALID_INPUT:
            cout << "Number was invalid" << endl;
            break;
        case InputStatus::OUT_OF_RANGE:
            cout << "Number was out of range" << endl;
            break;
        case InputStatus::MULTIPLE_INPUTS:
            cout << "There were multiple inputs" << endl;
            break;
        default :
            break;
    }
    cout << "Enter a number (0-99999): ";
}

unsigned long GetReverseNumber(unsigned long number){
    unsigned long reversed_number = 0, remainder;

    while(number != 0) {
        remainder = number % 10;
        reversed_number = reversed_number * 10 + remainder;
        number /= 10;
    }

    return reversed_number;
}

unsigned long CalculateResult(unsigned long value, unsigned long exponent){
    if(exponent == 0) return 1;
    if(exponent == 1) return value;
    unsigned long output = value;
    while (exponent > 1 ) {
        output *= value;
        exponent--;
    }
    return output;
}



int main(){
    unsigned long value_a;
    InputStatus input_status = InputStatus::NO_INPUT;
    while(input_status != InputStatus::VALID ){
        DisplayMessage(input_status);
        input_status = GetInputNumber(value_a);
    }
    auto value_b = GetReverseNumber(value_a);
    const auto value_c = CalculateResult(value_a, value_b);
    cout << value_c << endl;
}

