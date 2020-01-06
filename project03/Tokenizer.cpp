//
// Created by Soumana Sylla on 12/3/19.
//

#include "Tokenizer.hpp"

Tokenizer::Tokenizer(std::string name): inputFileName{name} {
    inputStream.open(inputFileName, std::ios::in);  // open the input file. We will make sure that it is open in getToken.
}

Token* Tokenizer::getToken() {
    char c;

    if( ! inputStream.is_open()) {
        std::cout << "Tokenizer::getToken() called with a stream that is not open." << std::endl;
        std::cout << "Make sure that " << inputFileName << " exists and is readable. Terminating.";
        exit(2);
    }

    while( inputStream.get(c) && c == ' ' ) {}

    if( inputStream.eof() ) {
        Token* token = new Token();
        token->eof(true);
        return token;
    }
    else if( isalpha(c) && islower(c) ) {
        Token* token = new Token(c);
        return token;
    }
    else if( c == '=' ) {
        Token* token = new Token(c);
        return token;
    }
    else if( c == '-' ) {
        Token* token = new Token(c);
        return token;
    }
    else if( c == '+' ) {
        Token* token = new Token(c);
        return token;
    }
    else if( c == '*') {
        Token* token = new Token(c);
        return token;
    }
    else if( c == '%') {
        Token* token = new Token(c);
        return token;
    }
    else if( c == '/') {
        Token* token = new Token(c);
        return token;
    }
    else if( c == '(') {
        Token* token = new Token(c);
        return token;
    }
    else if( c == ')') {
        Token* token = new Token(c);
        return token;
    }
    else if( c == '\n') {
        Token* token = new Token();
        token->eol(true);
        return token;
    }
    else if( c == 'I' || c == 'V' || c == 'X' || c == 'L' || c == 'C' || c == 'D' || c == 'M') {
        std::string name;
        inputStream.putback(c);
        while(inputStream.get(c) && (c == 'I' || c == 'V' || c == 'X' || c == 'L' || c == 'C' || c == 'D' || c == 'M')) {
            name += c;
        }
        inputStream.putback(c);
        Token* token = new Token(name);
        return token;
    }

    std::cout << "\nInvalid character " << c << " Terminating..." <<  std::endl;
    exit(2);
}




