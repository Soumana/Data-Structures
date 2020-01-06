//
// Created by Ali A. Kooshesh on 2019-08-26.
//

#ifndef POSTFIXEVALUATOR_TOKEN_HPP
#define POSTFIXEVALUATOR_TOKEN_HPP

class Token {
public:
    Token();
    bool &isNumber();
    bool &isNumber() const;
    void numberValue(int n);
    int numberValue();
    int numberValue() const;
    bool &endOfFile();
    bool &endOfLine();
    char &arithSymbol();
    bool isArithSymbol();
    void print(bool newLine=false);

private:
    bool _isNumber, _eof, _eol;

    char _arithSymbol;
    int _number;
};

#endif //POSTFIXEVALUATOR_TOKEN_HPP
