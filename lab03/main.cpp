#include <iostream>
#include "BinSearchTree.cpp"
#include <fstream>

int main(int argc, char *argv[]) {
    BinSearchTree *tree = new BinSearchTree();

    std::string str;
    std::ifstream myFile(argv[1]);

    while(std::getline(myFile, str)) {
        tree->insert(stoi(str));
    }

    return 0;
}