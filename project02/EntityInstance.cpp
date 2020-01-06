//
// Created by Soumana Sylla on 2019-11-07.
//

#include "EntityInstance.hpp"
#include "EntityInstance.hpp"
#include <iostream>

void EntityInstance::addAttribute(Pair &pair) {
    entityAttributes.push_back(pair);
}

int EntityInstance::numAttributes() {
    return entityAttributes.size();
}

std::vector<std::string> &EntityInstance::attributeNames() {
    for(auto pair : entityAttributes) {
        attributeKeys.push_back(pair.attributeName());
    }
    return attributeKeys;
}

void EntityInstance::printEntityInstance() {
    for(auto pair : entityAttributes) {
        pair.printPair(pair);
    }
    std::cout << std::endl;
}

std::vector<Pair> EntityInstance::getInstancePairs() {
    return entityAttributes;
}

std::string EntityInstance::getIDValue() {
    for(auto pair : entityAttributes) {
        if(pair.attributeName() == "id") {
            return pair.stringValue();
        }
    }
}

double EntityInstance::getGPA() {
    for(auto pair : entityAttributes) {
        if(pair.attributeName() == "gpa") {
            return pair.numberValue();
        }
    }
}
