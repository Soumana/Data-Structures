//
// Created by Soumana Sylla on 8/27/19.
//

#ifndef LAB01_2_TOKENIZER_HPP
#define LAB01_2_TOKENIZER_HPP

#include <string>
#include <fstream>
#include "Token.hpp"

class Tokenizer {

public:
    Tokenizer(std::string);
    Token getToken();
    void unGetToken();

private:
    int lineNumber, charPosition;
    std::string inputFileName;
    std::ifstream inputStream;

    Token lastToken;

    bool charOfInterest(char c);
    bool hasUngottenToken;
};


#endif //LAB01_2_TOKENIZER_HPP
