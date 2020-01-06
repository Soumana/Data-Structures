//
// Created by Ali A. Kooshesh on 2019-08-26.
//

#ifndef POSTFIXEVALUATOR_TOKENIZER_HPP
#define POSTFIXEVALUATOR_TOKENIZER_HPP

#include <string>
#include <fstream>
#include "Token.hpp"

class Tokenizer {

public:
    Tokenizer(std::string);
    Token getToken();

private:
    std::string inputFileName;
    std::ifstream inputStream;

    bool isAnArithSymbol(char c);
};


#endif //POSTFIXEVALUATOR_TOKENIZER_HPP
