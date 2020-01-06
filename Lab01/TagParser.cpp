//
// Created by Soumana Sylla on 8/27/19.
//

#include "iostream"
#include "TagParser.hpp"

TagParser::TagParser(std::string name) : inputFile{name} {}

void TagParser::parseInput() {
    Tokenizer tokenizer(inputFile);

    Token token = tokenizer.getToken();

    while (!token.endOfFile()) {
        if(token.isOpenTag()) {
            handleOpenTag(tokenizer, token);
        }
        else if(token.isCloseTag()) {
            handleCloseTag(tokenizer, token);
        }
        else if(token.isCloseAngleBracket()) {
            token.print();
            std::cout << " ignoring random close angle-bracket." << std::endl;
        }
        else if(token.isOpenAngleBracket()) {
            token.print();
            std::cout << " ignoring random open angle-bracket." << std::endl;
        }
        else {
            token.print();
            std::cout << " unknown token." << std::endl;
        }

        token = tokenizer.getToken();
    }

    printMap();
}

void TagParser::handleOpenTag(Tokenizer &tokenizer, Token &token) {
    Token token2 = tokenizer.getToken();

    if(token2.isCloseAngleBracket()) {
        openTags.push_back(token);
    }
    else if(token2.isCloseStandAloneTag()) {
        if(tokenMap.count(token.tagName()) > 0) {
            tokenMap[token.tagName()].push_back(token);
            tokenMap[token.tagName()].push_back(token2);
        }
        else {
            tokenMap[token.tagName()] = std::vector<Token>();
            tokenMap[token.tagName()].push_back(token);
            tokenMap[token.tagName()].push_back(token2);
        }
    }
    else {
        token.print();
        std::cout << "is missing a '>' or '/>'. Will discard it." << std::endl;
        tokenizer.unGetToken();
    }
}

void TagParser::handleCloseTag(Tokenizer &tokenizer, Token &token) {
    Token token2 = tokenizer.getToken();

    bool inThere = false;

    if (token2.isCloseAngleBracket()) {
        if (token.tagName() == openTags.back().tagName()) {
            if(tokenMap.count(token.tagName()) > 0) {
                tokenMap[token.tagName()].push_back(openTags.back());
                tokenMap[token.tagName()].push_back(token);
                openTags.pop_back();
            }
            else {
                tokenMap[token.tagName()] = std::vector<Token>();
                tokenMap[token.tagName()].push_back(openTags.back());
                tokenMap[token.tagName()].push_back(token);
                openTags.pop_back();
            }
        }
        else {
            for (int i = openTags.size() - 1; i >= 0; i--) {
                if (openTags[i].tagName() == token.tagName()) {
                    inThere = true;
                    openTags.erase(openTags.begin() + i);
                    break;
                }
            }
            if (!inThere) {
                token.print();
                std::cout << " (with close angle bracket ";
                token2.print();
                std::cout << ") doesn't have a matching open tag. Will discard it.";
                std::cout << std::endl;
            }
            else {
                token.print();
                std::cout << " closes while the following tags remain open" << std::endl;
                for (int i = openTags.size() - 1; i >= 0; i--) {
                    std::cout << "\t";
                    openTags[i].print();
                    std::cout << std::endl;
                }
            }
        }

    }
    else {
        token.print();
        std::cout << " doesn't close properly. Will discard it." << std::endl;
        tokenizer.unGetToken();
    }
}

void TagParser::printMap() {
    std::cout << std::endl;
    std::cout << "The following is a list of well-formed HTML tags.";
    std::cout << std::endl;
    std::cout << std::endl;

    for(auto iter = tokenMap.begin(); iter != tokenMap.end(); ++iter ) {
        int count = 0;
        int lines = 0;

        std::cout << iter->first; std::cout << " appeared in the following ";
        std::vector<Token> locations = iter->second;
        if(locations.size() == 2) {
            std::cout << "location.";
            std::cout << std::endl;
        }
        else {
            std::cout << locations.size() / 2; std::cout << " locations.";
            std::cout << std::endl;
        }
        for(auto iter2 = locations.begin(); iter2 != locations.end(); ++iter2 ) {
            iter2->print();
            count++;
            if(count == 1) {
                std::cout << "-- ";
                count = -1;
            }
            lines++;
            if(lines == 2) {
                std::cout << std::endl;
                lines = 0;
            }
        }

        std::cout << std::endl;
    }
}