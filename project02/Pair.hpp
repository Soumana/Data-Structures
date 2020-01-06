//
// Created by Soumana Sylla on 2019-11-07.
//

#ifndef PROJECT02_PAIR_HPP
#define PROJECT02_PAIR_HPP

#include <string>

class Pair {
public:
    Pair(std::string attributeName, std::string attributeValue);
    Pair(std::string attributeName, double);
    bool isDouble();  // is the datatype of the value of this attribute a double?
    double numberValue();
    std::string stringValue();
    std::string attributeName();
    void printPair(Pair pair);

private:
    std::string _attributeName, _attributeStringValue;
    double _attributeNumberValue;
    bool _isNumber;
};




#endif //PROJECT02_PAIR_HPP
