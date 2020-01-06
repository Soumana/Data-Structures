//
// Created by Ali A. Kooshesh on 2019-08-26.
//

#include <iostream>
#include "Tokenizer.hpp"

Tokenizer::Tokenizer(std::string name): inputFileName{name} {
    // open the input file. We will make sure that it is open in getToken.
    inputStream.open(inputFileName, std::ios::in);
}

bool Tokenizer::isAnArithSymbol(char c) {
    return c == '+' || c == '-' || c == '/' || c == '%' || c == '*';
}

Token Tokenizer::getToken() {
    // The tokens of interest are:
    // 1. a number (a sequence of digits. Decimal points are not allowed)
    // 2. any of the binary arithmetic operators: +, -, /, %, and *.
    // 3. new-line character
    // 4. end of file.
    // Any character other than those specified above will cause this
    // function to print an error message and exit.

    char c;

    if( ! inputStream.is_open()) {
        std::cout << "Tokenizer::getToken() called with a stream that is not open." << std::endl;
        std::cout << "Make sure that " << inputFileName << " exists and is readable. Terminating.";
        exit(2);
    }

    while( inputStream.get(c) &&  c != '\n' && isspace(c) )
        ; // discard spaces, but not the new-line character.

    // The expression inputStream.get(c), in the condition of the above while loop
    // terminates if reading some character corrupts the stream. For example, reading
    // a character that is not compatible with the character set of the iostream.
    // Therefore, after the loop terminates, we want to make sure to continue
    // if the stream is not corrupt. If the stream is corrupt, the the value
    // of character c is not dependable.

    if( ! inputStream.good() ) {
        std::cout << "Tokenizer: Input stream seems corrupt. Terminating...\n";
        exit(1);
    }

    Token token;
    if( inputStream.eof() ) {
        token.endOfFile() = true;
        return token;
    }

    if( c == '\n') {
        token.endOfLine() = true;
        return token;
    }

    if( isAnArithSymbol(c) ) {
        token.arithSymbol() = c;
        return token;
    } else if( isdigit(c) ) {
        // So, we just read the first digit of a number. We put it
        // back and read the number as an integer.
        inputStream.putback(c);
        int n;
        inputStream >> n;
        token.numberValue(n);
        return token;
    } else {
        std::cout << "Bad character in input. The character is ->" << c << "<-\n";
        exit(1);
    }
}