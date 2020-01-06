//
// Created by Soumana Sylla on 2019-11-07.
//

#ifndef PROJECT02_JSONTOKENIZER_HPP
#define PROJECT02_JSONTOKENIZER_HPP

#include <string>
#include <fstream>
#include "JSONToken.hpp"

class JSONTokenizer {

public:
    JSONTokenizer(std::string);
    JSONToken getToken();

private:
    std::string inputFileName;
    std::ifstream inputStream;
    bool charOfInterest(char c);
};

#endif //PROJECT02_JSONTOKENIZER_HPP
