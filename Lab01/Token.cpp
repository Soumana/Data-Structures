//
// Created by Soumana Sylla on 8/27/19.
//

#include <iostream>
#include <iomanip>
#include "Token.hpp"

Token::Token(int line, int pos): _isOpenTag{false},
                                 _isCloseTag{false},
                                 _isCloseAngleBracket{false},
                                 _isCloseStandAloneTag{false},
                                 _tagName{""},
                                 _lineNumber{line},
                                 _charPos{pos},
                                 _eof{false},
                                 _isOpenAngleBracket{false} {}

bool &Token::isOpenTag() { return _isOpenTag; }
bool &Token::isCloseTag() { return _isCloseTag; }

bool &Token::isCloseAngleBracket() { return _isCloseAngleBracket; }

bool &Token::endOfFile() { return _eof; }
bool &Token::isCloseStandAloneTag() { return _isCloseStandAloneTag; }

std::string Token::tagName() { return _tagName; }

bool &Token::isOpenAngleBracket() { return _isOpenAngleBracket; }

void Token::makeOpenTag(std::string name) {
    _tagName = name;
    isOpenTag() = true;
}

void Token::makeCloseTag(std::string name) {
    _tagName = name;
    isCloseTag() = true;
}

void Token::print() {
    if(isOpenTag()) {
        std::cout << "[" << std::setw(2) << _lineNumber << ", " <<  std::setw(3) << _charPos << "] ";
        std::cout << "<" << tagName() << " ";
    }
    else if(isCloseStandAloneTag()) {
        std::cout << "[" << std::setw(2) << _lineNumber << ", " <<  std::setw(3) << _charPos << "] ";
        std::cout << "/>";
    }
    else if(isCloseAngleBracket()) {
        std::cout << "[" << std::setw(2) << _lineNumber << ", " <<  std::setw(3) << _charPos << "] ";
        std::cout << ">";
    }
    else if(isCloseTag()) {
        std::cout << "[" << std::setw(2) << _lineNumber << ", " <<  std::setw(3) << _charPos << "] ";
        std::cout << "</" << tagName();
    }
    else if(isOpenAngleBracket()) {
        std::cout << "[" << std::setw(2) << _lineNumber << ", " <<  std::setw(3) << _charPos << "] ";
        std::cout << "<";
    }
    else {
        std::cout << "[" << std::setw(2) << _lineNumber << ", " <<  std::setw(3) << _charPos << "] ";
        std::cout << "unknown token";
    }
}