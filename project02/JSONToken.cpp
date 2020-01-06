//
// Created by Soumana Sylla on 2019-11-07.
//

#include "JSONToken.hpp"
#include "iostream"

JSONToken::JSONToken() : _isOpenBracket{false},
                         _isCloseBracket{false},
                         _isOpenBrace{false},
                         _isCloseBrace{false},
                         _isColon{false},
                         _isComma{false},
                         _eof{false},
                         _attributeString{""},
                         _isAttributeString{false},
                         _isAttributeNum{false},
                         _attributeNum{0.0} {}




bool &JSONToken::isOpenBracket() { return _isOpenBracket; }

bool &JSONToken::isCloseBracket() { return _isCloseBracket; }

bool &JSONToken::isOpenBrace() { return _isOpenBrace; }

bool &JSONToken::isCloseBrace() { return _isCloseBrace; }

bool &JSONToken::isColon() { return _isColon; }

bool &JSONToken::isComma() { return _isComma; }

bool &JSONToken::isAttributeString() { return _isAttributeString; }

bool &JSONToken::endOfFile() { return _eof; }

std::string JSONToken::attributeString() { return _attributeString; }

bool &JSONToken::isAttributeNum() { return _isAttributeNum; }

double JSONToken::attributeNum() { return _attributeNum; }

void JSONToken::makeAttributeName(std::string name) {
    isAttributeString() = true;
    _attributeString = name;
}

void JSONToken::makeAttributeNum(double num) {
    isAttributeNum() = true;
    _attributeNum = num;
}

void JSONToken::print() {
    if(isOpenBracket()) {
        std::cout << "[" << std::endl;
    }
    else if(isCloseBracket()) {
        std::cout << "]" << std::endl;
    }
    else if(isOpenBrace()) {
        std::cout << "{" << std::endl;
    }
    else if(isCloseBrace()) {
        std::cout << "}" << std::endl;
    }
    else if(isColon()) {
        std::cout << ":" << std::endl;
    }
    else if(isComma()) {
        std::cout << "," << std::endl;
    }
    else if(isAttributeString()) {
        std::cout << attributeString() << std::endl;
    }
    else if(isAttributeNum()) {
        std::cout << attributeNum() << std::endl;
    }
    else {
        std::cout << "unknown token" << std::endl;
    }
}






