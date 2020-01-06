#include <iostream>
#include "JSONTokenizer.hpp"
#include "JSONParser.hpp"

int main(int argc, char *argv[]) {

    if( argc != 3 ) {  // we expect the name of the file as an argument to the program.
        std::cout << "usage: " << argv[0] << " nameOfAnInputFile" << std::endl;
        exit(1);
    }

    std::ifstream inputStream1;
    inputStream1.open(argv[1], std::ios::in);    // open for reading

    std::ifstream inputStream2;
    inputStream2.open(argv[2], std::ios::in);    // open for reading

    if( ! inputStream1.is_open()) {
        std::cout << "Unable top open " << argv[1] << ". Terminating...";
        exit(2);
    }

    if( ! inputStream2.is_open()) {
        std::cout << "Unable top open " << argv[2] << ". Terminating...";
        exit(2);
    }
    inputStream1.close();
    inputStream2.close();


    JSONTokenizer jsonTokenizer1(argv[1]); // The Tokenizer opens and reads from the input file.
    JSONTokenizer jsonTokenizer2(argv[2]); // The Tokenizer opens and reads from the input file.

    JSONParser *parser1 = new JSONParser(jsonTokenizer1);
    Entity entity1 = parser1->parseJSONEntity();

    JSONParser *parser2 = new JSONParser(jsonTokenizer2);
    Entity entity2 = parser2->parseJSONEntity();

    Entity e;

    e.createMatrix(entity1, entity2);

    e.generateMatrixFile();

    return 0;
}
