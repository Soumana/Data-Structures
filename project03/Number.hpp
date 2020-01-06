//
// Created by Soumana Sylla on 11/19/19.
//

#ifndef PROJECT1_NUMBER_HPP
#define PROJECT1_NUMBER_HPP

#include <string>

class Number {
public:
    Number( int n );
    Number( std::string s );

    // is the Roman number that is stored in "strNumber" a legal Roman number?
    bool isALegalRomanNumber();


    bool isNumber();

    // Return the int value of this Roman number.  If the instance was
    // created by having used a decimal number, just return it.
    // Otherwise, convert "strNumber" to its decimal counterpart and
    // return it.  Note that you may already have converted it when the
    // user called "isALegalRomanNumber".
    int intValue();

    // convert "intNumber" to its Roman counterpart and return it as a string.
    std::string romanValue();

    std::string initialRomanNumber();

private:
    std::string strNumber;
    int intNumber;

    bool _isNumber;
};

#endif //PROJECT1_NUMBER_HPP
