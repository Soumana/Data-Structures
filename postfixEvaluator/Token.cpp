//
// Created by Ali A. Kooshesh on 2019-08-26.
//

#include <iostream>
#include <iomanip>
#include "Token.hpp"

Token::Token(): _isNumber{false},
                _arithSymbol{'\0'},
                _eof{false},
                _eol(false) {}

bool &Token::isNumber() { return _isNumber; }

void Token::numberValue(int value) {
    isNumber() = true;
    _number = value;
}

int Token::numberValue() {
    return _number;
}

char &Token::arithSymbol() { return _arithSymbol; }
bool Token::isArithSymbol() { return _arithSymbol != '\0'; }

bool &Token::endOfFile() { return _eof; }
bool &Token::endOfLine() { return _eol; }


void Token::print(bool newLine) {
    std::string endLine = "";
    if(newLine)
        endLine = "\n";
    const auto divider = " ";
    if(isNumber()) {
        std::cout << numberValue() << divider << endLine;
    } else if(isArithSymbol()) {
        std::cout << arithSymbol() << divider << endLine;
    } else if(endOfLine()) {
        std::cout << "EOL" << divider << endLine;
    } else if(endOfFile()) {
        std::cout << "EOF" << endLine;
    } else {
        std::cout << "Token: I do not recognize this token!\n";
        exit(1);
    }
}
