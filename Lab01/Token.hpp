//
// Created by Soumana Sylla on 8/27/19.
//

#ifndef LAB01_2_TOKEN_HPP
#define LAB01_2_TOKEN_HPP

#include <string>

class Token {

public:
    Token(int, int);
    bool &isOpenTag();
    bool &isCloseTag();

    bool &isCloseAngleBracket();

    bool &endOfFile();
    bool &isCloseStandAloneTag();

    bool &isOpenAngleBracket();

    std::string tagName();

    void makeOpenTag(std::string);
    void makeCloseTag(std::string);

    void print();

private:
    bool _isOpenTag, _isCloseTag, _isCloseAngleBracket,
        _eof, _isCloseStandAloneTag, _isOpenAngleBracket;

    std::string _tagName;
    int _lineNumber, _charPos;
};


#endif //LAB01_2_TOKEN_HPP
