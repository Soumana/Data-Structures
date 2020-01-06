//
// Created by Soumana Sylla on 2019-11-07.
//

#ifndef PROJECT02_ENTITYINSTANCE_HPP
#define PROJECT02_ENTITYINSTANCE_HPP

#include "Pair.hpp"
#include <vector>

class EntityInstance {
public:
    void addAttribute(Pair &);
    int numAttributes();
    std::vector<std::string> &attributeNames();
    void printEntityInstance();
    std::vector<Pair> getInstancePairs();
    std::string getIDValue();
    double getGPA();

private:
    std::vector<Pair> entityAttributes;
    std::vector<std::string> attributeKeys;
};

#endif //PROJECT02_ENTITYINSTANCE_HPP
