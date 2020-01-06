//
// Created by Soumana Sylla on 12/4/19.
//

#include "SymbolTable.hpp"

void SymbolTable::add(char c, int n) {
    expressionMap[c] = n;
}

int SymbolTable::find(char c) {
    if(expressionMap.count(c) == 1) {
        return expressionMap.at(c);
    }
    return -1;
}