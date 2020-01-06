//
// Created by Soumana Sylla on 2019-11-07.
//

#include "JSONTokenizer.hpp"
#include <iostream>

JSONTokenizer::JSONTokenizer(std::string name) : inputFileName{name} {
    inputStream.open(inputFileName, std::ios::in);
}

bool JSONTokenizer::charOfInterest(char c) {
    // is c the initial (or the sole) character of a token?
    if(c == '[') {
        return true;
    }
    else if(c == '{') {
        return true;
    }
    else if(c == '"') {
        return true;
    }
    else if(isdigit(c)) {
        return true;
    }
    else if(c == ':') {
        return true;
    }
    else if(c == ',') {
        return true;
    }
    else if(c == ']') {
        return true;
    }
    else if(c == '}') {
        return true;
    }
    return false;
}

JSONToken JSONTokenizer::getToken() {
    char c;

    if( ! inputStream.is_open()) {
        std::cout << "JSONTokenizer::getToken() called with a stream that is not open." << std::endl;
        std::cout << "Make sure that " << inputFileName << " exists and is readable. Terminating.";
        exit(2);
    }

    while( inputStream.get(c) && ! charOfInterest(c) ) {}

    JSONToken token;

    if( inputStream.eof() ) {
        token.endOfFile() = true;
        return token;
    }
    else if( c == '[' ) {
        token.isOpenBracket() = true;
        return token;
    }
    else if( c == '{' ) {
        token.isOpenBrace() = true;
        return token;
    }
    else if( c == '"' ) {
        std::string name;
        while(inputStream.get(c) && c != '"') {
            name += c;
        }
        token.makeAttributeName(name);
        return token;
    }
    else if( c == ':' ) {
        token.isColon() = true;
        return token;
    }
    else if( isdigit(c) )  {
        inputStream.putback(c);
        double doubleValue;
        inputStream >> doubleValue;
        token.makeAttributeNum(doubleValue);
        return token;
    }
    else if( c == ',' ) {
        token.isComma() = true;
        return token;
    }
    else if( c == '}' ) {
        token.isCloseBrace() = true;
        return token;
    }
    else if( c == ']' ) {
        token.isCloseBracket() = true;
        return token;
    }
    return token;
}
