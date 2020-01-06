//
// Created by Soumana Sylla on 2019-11-07.
//

#ifndef PROJECT02_JSONTOKEN_HPP
#define PROJECT02_JSONTOKEN_HPP

#include <string>

class JSONToken {
public:
    JSONToken();

    bool &isOpenBracket();  // [
    bool &isCloseBracket(); // ]

    bool &isOpenBrace();   // {
    bool &isCloseBrace();  // }

    bool &isColon();

    bool &isComma();

    bool &isAttributeString();

    bool &isAttributeNum();

    bool &endOfFile();

    std::string attributeString();

    double attributeNum();

    void makeAttributeName(std::string);

    void makeAttributeNum(double);

    void print();

private:
    bool _isOpenBracket, _isCloseBracket, _isOpenBrace, _isCloseBrace,
            _isColon, _isComma, _eof, _isAttributeString, _isAttributeNum;

    double _attributeNum;

    std::string _attributeString;
};

#endif //PROJECT02_JSONTOKEN_HPP
