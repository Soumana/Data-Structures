//
// Created by Soumana Sylla on 11/19/19.
//

#include "Number.hpp"
#include <iostream>
#include <map>

Number::Number(int n) : intNumber{n},
                        _isNumber{true} {}


Number::Number(std::string s) : strNumber{s},
                                _isNumber{false} {}


bool Number::isNumber() {
    return _isNumber;
}

std::string Number::initialRomanNumber() {
    return strNumber;
}

bool Number::isALegalRomanNumber() {
    Number n(strNumber);
    int romanToDecimal = n.intValue();
    intNumber = romanToDecimal;
    std::string decimalToRoman = romanValue();

    if(decimalToRoman == strNumber) {
        return true;
    }
    return false;
}

int Number::intValue() {
    if(isNumber()) {
        return intNumber;
    }
    int count = 0;

    for(int i = 0; i < strlen(strNumber.c_str()); i++) {
        if(strNumber[i] == 'I' || strNumber[i] == 'X' || strNumber[i] == 'C') {
            if(i != strlen(strNumber.c_str() - 1)) {
                if(strNumber[i] == 'I') {
                    if(strNumber[i+1] == 'V' || strNumber[i+1] == 'X') {
                        count--;
                    }
                    else{
                        count++;
                    }
                }
                else if(strNumber[i] == 'X') {
                    if(strNumber[i+1] == 'L' || strNumber[i+1] == 'C') {
                        count -= 10;
                    }
                    else {
                        count += 10;
                    }
                }
                else if(strNumber[i] == 'C') {
                    if(strNumber[i+1] == 'D' || strNumber[i+1] == 'M') {
                        count -= 100;
                    }
                    else {
                        count += 100;
                    }
                }
            }
            else {
                if(strNumber[i] == 'I') {
                    count++;
                }
                else if(strNumber[i] == 'X') {
                    count += 10;
                }
                else if(strNumber[i] == 'C') {
                    count += 100;
                }
            }

        }
        else if(strNumber[i] == 'V') {
            count += 5;
        }
        else if(strNumber[i] == 'L') {
            count += 50;
        }
        else if(strNumber[i] == 'D') {
            count += 500;
        }
        else if(strNumber[i] == 'M') {
            count += 1000;
        }
    }
    return count;
}

std::string Number::romanValue() {
    std::string decToRoman;

    int tempIntNumber = intNumber;

    int romanValues[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    std::map<int, std::string> romanNumeralMap = {
            {1000, "M"},
            {500,  "D"},
            {100,  "C"},
            {50,   "L"},
            {10,   "X"},
            {5,    "V"},
            {1,    "I"},
            {900, "CM"},
            {400, "CD"},
            {90, "XC"},
            {40, "XL"},
            {9, "IX"},
            {4, "IV"}
    };

    for(int i = 0; i < 13; i++) {
        if(tempIntNumber >= romanValues[i]) {
            while(romanValues[i] <= tempIntNumber) {
                decToRoman += romanNumeralMap[romanValues[i]];
                tempIntNumber -= romanValues[i];
            }
        }
    }
    return decToRoman;
}

