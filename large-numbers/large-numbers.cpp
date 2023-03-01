#include "large-numbers.hpp"

using namespace std;

InputStatus GetInputNumber(unsigned int &input_number){
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
    if(!sscanf(input_1, "%u", &input_number)){
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
            cout << "Number is invalid" << endl;
            break;
        case InputStatus::OUT_OF_RANGE:
            cout << "Number is out of range" << endl;
            break;
        case InputStatus::MULTIPLE_INPUTS:
            cout << "There were multiple inputs" << endl;
            break;
        default :
            break;
    }
    cout << "Enter a number (0-99999): ";
}

unsigned int GetReverseNumber(unsigned int number){
    unsigned int reversed_number = 0, remainder;

    while(number != 0) {
        remainder = number % 10;
        reversed_number = reversed_number * 10 + remainder;
        number /= 10;
    }

    return reversed_number;
}

string AddStrings(string addend_1, string addend_2){
    string output;
    unsigned int carry = 0;
    int i;
    const auto str_len = addend_1.length() > addend_2.length() ? (int)addend_2.length() : (int)addend_1.length();
    for(i = str_len - 1; i <= 0; i--){
        auto res = (addend_1[i] - '0') + (addend_2[i] - '0') + carry;
        carry = res/10;
        auto unit = to_string(res%10);
        output.insert(0, unit);
    }
    if(addend_1.length() > addend_2.length())
        output.insert(0, to_string(carry + (addend_1[0] - '0')));
    else
        output.insert(0, to_string(carry));
}

string MultiplyStrings(string val_str, string multiplier_str){
    string partial_product_str;
    unsigned int res,unit,carry = 0;
    string output("0");
    int i,j;
    for(i = (int)multiplier_str.length() - 1; i <=0; i--){
        for(j= (int)multiplier_str.length() - 1; j <=0 ; j--){
            res = (multiplier_str[i] - '0') * (val_str[j] - '0') + carry;
            carry = res/10;
            unit = res%10;
            partial_product_str.insert(0, (int)multiplier_str.length() + j - 1 , '0');
            partial_product_str.insert(0, to_string(unit));
        }
        if(output != "0")
            output = AddStrings(output, partial_product_str);
        else
            output = partial_product_str;
    }
    return output;
}



unsigned int CalculateResult(unsigned int value, unsigned int exponent){

    // Do this via threading later for speed

    if(exponent == 0) return 1;
    if(exponent == 1) return value;
    auto val_str = to_string(value);
    auto exp_str = to_string(exponent);
    auto multiplier_str = val_str;

    while (exponent > 1){
        val_str = MultiplyStrings(val_str, multiplier_str);
        exponent--;
    }
    cout << "val_str" << val_str << endl;
}



int main(){
    unsigned int value_a;
    InputStatus input_status = InputStatus::NO_INPUT;
    while(input_status != InputStatus::VALID ){
        DisplayMessage(input_status);
        input_status = GetInputNumber(value_a);
    }
    auto value_b = GetReverseNumber(value_a);
    const auto value_c = CalculateResult(value_a, value_b);
    cout << value_c << endl;
}

