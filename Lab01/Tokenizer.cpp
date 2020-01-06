//
// Created by Soumana Sylla on 8/27/19.
//

#include <iostream>
#include "Tokenizer.hpp"

Tokenizer::Tokenizer(std::string name): lineNumber{1},
                                        charPosition{1},
                                        lastToken{0,0},
                                        hasUngottenToken{false},
                                        inputFileName{name} {
    inputStream.open(inputFileName, std::ios::in);  // open the input file. We will make sure that it is open in getToken.
}

bool Tokenizer::charOfInterest(char c) {
    // is c the initial (or the sole) character of a token?
    if(c == '<') {
        return true;
    }
    else if(c == '>') {
        return true;
    }
    else if(c == '/' && inputStream.peek() == '>') {
        return true;
    }
    return false;
}

Token Tokenizer::getToken() {
    char c;

    if(hasUngottenToken) {
        hasUngottenToken = false;
        return lastToken;
    }

    if( ! inputStream.is_open()) {
        std::cout << "Tokenizer::getToken() called with a stream that is not open." << std::endl;
        std::cout << "Make sure that " << inputFileName << " exists and is readable. Terminating.";
        exit(2);
    }

    while( inputStream.get(c) && ! charOfInterest(c) ) {
        // keep track of the line number and the character position
        charPosition++;
        if(c == '\n') {
            lineNumber++;
        }
    }

    Token token(lineNumber, charPosition);

    if( inputStream.eof() ) {
        token.endOfFile() = true;
        lastToken = token;
        return token;
    }
    else if( c == '<' && isalpha(inputStream.peek()) ) { // A possible open tag.
        charPosition++;
        std::string name;

        while(inputStream.get(c) && isalnum(c) ) {
            name += c;
            charPosition++;
        }

        inputStream.putback(c);

        token.makeOpenTag(name);
        lastToken = token;
        return token;
    }
    else if( c == '>' ) {
        charPosition++;
        token.isCloseAngleBracket() = true;
        lastToken = token;
        return token;
    }
    else if( c == '<' && inputStream.peek() == '/' ) {
        charPosition++;
        std::string name;
        inputStream.get(c);
        charPosition++;

        if( isalpha(inputStream.peek()) ) {
            while (inputStream.get(c) && isalnum(c)) {
                charPosition++;
                name += c;
            }
        }

        inputStream.putback(c);
        token.makeCloseTag(name);
        lastToken = token;
        return token;
    }
    else if( c == '/' && inputStream.peek() == '>' ) {
        charPosition++;
        inputStream.get(c);
        charPosition++;

        token.isCloseStandAloneTag() = true;
        lastToken = token;
        return token;
    }
    else if( c == '<') {
        charPosition++;
        token.isOpenAngleBracket() = true;
        lastToken = token;
        return token;
    }

    return token;
}

void Tokenizer::unGetToken() {
    hasUngottenToken = true;
}
