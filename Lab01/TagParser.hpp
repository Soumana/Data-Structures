//
// Created by Soumana Sylla on 8/27/19.
//

#ifndef LAB01_2_TAGPARSER_HPP
#define LAB01_2_TAGPARSER_HPP

#include "Tokenizer.hpp"
#include "Token.hpp"
#include <map>
#include <vector>

class TagParser {

public:
    TagParser(std::string);
    void parseInput();
    void printMap();

private:
    std::string inputFile;

    void handleOpenTag(Tokenizer& tokenizer, Token& token);
    void handleCloseTag(Tokenizer& tokenizer, Token& token);

    std::vector<Token> openTags;
    std::map<std::string, std::vector<Token> > tokenMap;
};


#endif //LAB01_2_TAGPARSER_HPP
