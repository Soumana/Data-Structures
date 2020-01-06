//
// Created by Soumana Sylla on 2019-11-07.
//

#include "Entity.hpp"
#include <iostream>
#include <fstream>

Entity::Entity() {
    for(auto subArray : outputMatrix) {
        for(int i = 0; i < 8; i++) {
            subArray[i] = 0;
        }
    }
};

void Entity::addObject(EntityInstance &EntityInstance) {
    instances.push_back(EntityInstance);
}

void Entity::printInstance() {
    for(auto entityInstance : instances) {
        entityInstance.printEntityInstance();
    }
}

int Entity::getGpaBand(double gpa) {
    if(gpa > 3.67 && gpa <= 4.0) {
        return 0;
    }
    else if(gpa > 3.3 && gpa <= 3.67) {
        return 1;
    }
    else if(gpa > 3.0 && gpa <= 3.3) {
        return 2;
    }
    else if(gpa > 2.67 && gpa <= 3.0) {
        return 3;
    }
    else if(gpa > 2.3 && gpa <= 2.67) {
        return 4;
    }
    else if(gpa > 2.0 && gpa <= 2.3) {
        return 5;
    }
    else if(gpa > 1.67 && gpa <= 2.0) {
        return 6;
    }
    else {
        return 7;
    }
}

void Entity::createMatrix(Entity e1, Entity e2) {
    for(auto entityInstance1 : e1.instances) {

        std::string idValue1 = entityInstance1.getIDValue();
        double prevGPA = entityInstance1.getGPA();

        for(auto entityInstance2 : e2.instances) {

            std::string idValue2 = entityInstance2.getIDValue();

            if(idValue1 == idValue2) {
                double curGPA = entityInstance2.getGPA();

                int row = getGpaBand(prevGPA);
                int col = getGpaBand(curGPA);

                outputMatrix[row][col]++;
                break;
            }
        }
    }
}

void Entity::print() {
    for(auto subArray : outputMatrix) {
        for(int i = 0; i < 8; i++) {
            std::cout << subArray[i] << "   ";
        }
        std::cout << std::endl;
    }
}

void Entity::generateMatrixFile() {
    std::ofstream outputFile("cs315project2.json");

    outputFile << "[" << std::endl;

    int count = 0;

    for(auto subArray : outputMatrix) {
        std::string gpaBan;
        gpaBan += "[";
        for(int i = 0; i < 8; i++) {
            gpaBan += std::to_string(subArray[i]);

            if(i < 7) {
                gpaBan += ", ";
            }
        }
        gpaBan += "]";
        count++;

        if(count <= 7) {
            gpaBan += ",";
        }
        std::cout << std::endl;

        outputFile << "\t" << gpaBan << std::endl;
    }
    outputFile << "]";
}

int Entity::testGpaIndex(Entity e1, Entity e2) {
    int count = 0;

    for(auto entityInstance1 : e1.instances) {
        std::string idValue1 = entityInstance1.getIDValue();
        double prevGPA = entityInstance1.getGPA();

        for(auto entityInstance2 : e2.instances) {
            std::string idValue2 = entityInstance2.getIDValue();

            if(idValue1 == idValue2) {
                if(prevGPA > 3.3 && prevGPA <= 3.67) {
                    double curGPA = entityInstance2.getGPA();
                    if(curGPA > 3.67 && curGPA <= 4.0) {
                        count++;
                    }

                }
            }
        }
    }
    return count;
}








