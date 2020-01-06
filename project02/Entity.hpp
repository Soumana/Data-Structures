//
// Created by Soumana Sylla on 2019-11-07.
//

#ifndef PROJECT02_ENTITY_HPP
#define PROJECT02_ENTITY_HPP

#include "EntityInstance.hpp"

class Entity {
public:
    Entity();

    void addObject(EntityInstance &);
    void printInstance();    // prints all instances of this Entity.
    void createMatrix(Entity e1, Entity e2);
    int getGpaBand(double gpa);
    void print();
    void generateMatrixFile();
    int testGpaIndex(Entity e1, Entity e2);

private:
    std::vector<EntityInstance> instances;
    int outputMatrix[8][8];
};

#endif //PROJECT02_ENTITY_HPP
