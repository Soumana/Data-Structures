//
// Created by Soumana Sylla on 12/3/19.
//

#ifndef PROJECT1_TOKENIZER_HPP
#define PROJECT1_TOKENIZER_HPP

#include "Token.hpp"
#include <fstream>

class Tokenizer {
public:
    Tokenizer(std::string);
    Token* getToken();

private:
    std::string inputFileName;
    std::ifstream inputStream;

    Token lastToken;
};

#endif //PROJECT1_TOKENIZER_HPP
