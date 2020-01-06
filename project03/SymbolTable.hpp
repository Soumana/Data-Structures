//
// Created by Soumana Sylla on 12/4/19.
//

#ifndef PROJECT1_SYMBOLTABLE_HPP
#define PROJECT1_SYMBOLTABLE_HPP

#include <map>

class SymbolTable {

public:
    void add(char c, int n);
    int find(char c);

private:
    std::map<char, int> expressionMap;

};

#endif //PROJECT1_SYMBOLTABLE_HPP
