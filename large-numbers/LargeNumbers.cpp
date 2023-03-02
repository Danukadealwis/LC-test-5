#include "LargeNumbers.hpp"

using namespace std;
using namespace LargeNumbers;

static void RemoveLeadingZeros(string &str){
    if (str[0] == '0' && str.length() > 1) {
        str.erase(str.begin());
        RemoveLeadingZeros(str);
    }
}

InputStatus LargeNumberCalculator::GetInputNumber(unsigned int &input_number){
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
    for(auto i = 0; i < (int)strlen(input_1); ++i) {
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

void LargeNumberCalculator::DisplayMessage(InputStatus input_status){
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

unsigned int LargeNumberCalculator::GetReverseNumber(unsigned int number){
    unsigned int reversed_number = 0, remainder;

    while(number != 0) {
        remainder = number % 10;
        reversed_number = reversed_number * 10 + remainder;
        number /= 10;
    }

    return reversed_number;
}

string LargeNumberCalculator::AddStrings(string addend_1, string addend_2){
    string output;
    unsigned int carry = 0;
//    static_assert(addend_1.length() > 0 )
    RemoveLeadingZeros(addend_1);
    RemoveLeadingZeros(addend_2);
    const auto str_len = addend_1.length() > addend_2.length() ? (int)addend_2.length() : (int)addend_1.length();
    for(auto i = 0; i < str_len; i++){
        auto res = (addend_1[addend_1.length() - i - 1] - '0') + (addend_2[addend_2.length() - i - 1] - '0') + carry;
        carry = res/10;
        auto unit = to_string(res%10);
        output.insert(0, unit);
    }
    if(addend_1.length() > addend_2.length())
        output.insert(0, AddStrings(to_string(carry),(addend_1.substr(0,addend_1.length() - addend_2.length()))));
    else if (addend_1.length() < addend_2.length())
        output.insert(0, AddStrings(to_string(carry),(addend_2.substr(0,addend_2.length() - addend_1.length()))));
    else if(carry > 0)
        output.insert(0, to_string(carry));
    return output;
}



string LargeNumberCalculator::MultiplyStrings(const string &input_1, const string &input_2){
    string partial_product_str;
    unsigned int res,unit,carry = 0;
    string output("0");
    auto val_str = input_1.length() > input_2.length() ? input_1 : input_2;
    auto multiplier_str = input_1.length() > input_2.length() ? input_2 : input_1;
    RemoveLeadingZeros(val_str);
    RemoveLeadingZeros(multiplier_str);
    for(auto i = (int)multiplier_str.length() - 1; i >=0; i--){
        for(auto j= (int)val_str.length() - 1; j >=0 ; j--){
            res = (multiplier_str[i] - '0') * (val_str[j] - '0') + carry;
            carry = res/10;
            unit = res%10;
            if (i != (int)val_str.length() - 1 && j == (int)val_str.length() - 1)
                partial_product_str.insert(0, (int)multiplier_str.length() - i -1 , '0');
            partial_product_str.insert(0, to_string(unit));
        }
        partial_product_str.insert(0, to_string(carry));
        if(output != "0")
            output = AddStrings(output, partial_product_str);
        else
            output = partial_product_str;
        partial_product_str = "";
        carry = 0;
    }
    RemoveLeadingZeros(output);
    return output;
}



string LargeNumberCalculator::CalculateResult(unsigned int value, unsigned int exponent){

    // Do this via threading later for speed

    auto val_str = to_string(value);
    auto exp_str = to_string(exponent);
    if(exponent == 0) return "1";
    if(exponent == 1) return val_str;
    auto output_str = val_str;
    while (exponent > 1){
        output_str = MultiplyStrings(val_str, output_str);
        exponent--;
    }
    return output_str;
}




