//
// Created by Soumana Sylla on 2019-11-07.
//

#include "Pair.hpp"
#include <iostream>

Pair::Pair(std::string attributeName, std::string attributeValue) : _attributeName{attributeName},
                                                                    _attributeStringValue{attributeValue},
                                                                    _isNumber{false} {}

Pair::Pair(std::string attributeName, double attributeNumberValue) : _attributeName{attributeName},
                                                                     _attributeNumberValue{attributeNumberValue},
                                                                     _isNumber{true} {}

bool Pair::isDouble() { return _isNumber; }

double Pair::numberValue() { return _attributeNumberValue; }

std::string Pair::attributeName() { return _attributeName; }

std::string Pair::stringValue() { return _attributeStringValue; }

void Pair::printPair(Pair pair) {
    std::cout << "" << pair.attributeName() << "" << " : ";
    if(isDouble()) {
        std::cout << pair.numberValue() << std::endl;
    }
    else {
        std::cout << "" << pair.stringValue() << "" << std::endl;
    }
}
