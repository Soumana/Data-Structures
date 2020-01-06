#include "Token.hpp"
#include "InfixToPostfix.hpp"
#include "Number.hpp"
#include <fstream>
#include "Tokenizer.hpp"
#include "SymbolTable.hpp"
#include <vector>

int main(int argc, char *argv[]) {

    // This function demonstrates the use of the InfixToPostfix class 
    // and its member-functionm, convert. To that end, the tokens 
    // have been hard coded instead of using a tokenizer to 
    // identify them.

//    std::vector<Token *> tokens = std::vector<Token *>();

    // Suppose that the input contained the following expression.
    // a = XX + XXX  * XXXV + (XXX - XXXII) + II
    // a = 20 + 30 * 35 + (30 + 32) + 2

//    tokens.push_back(new Token('a'));     // variable a
//    tokens.push_back(new Token('='));     //
//    tokens.push_back(new Token("XX"));     // 20
//    tokens.push_back(new Token('+'));
//    tokens.push_back(new Token( "XXX"));  // 30
//    tokens.push_back(new Token('*'));
//    tokens.push_back(new Token( "XXXV"));  // 35
//    tokens.push_back(new Token('+'));
//    tokens.push_back(new Token('('));
//    tokens.push_back(new Token("XXXII"));  // 32
//    tokens.push_back(new Token('-'));
//    tokens.push_back(new Token( 'c'));   // 30
//    tokens.push_back(new Token(')'));
//    tokens.push_back(new Token('+'));
//    tokens.push_back(new Token("II"));    // 2
//    Token *token = new Token();
//    token->eol(true);
//    tokens.push_back(token);
//
//    int numTokens = tokens.size();
//    std::cout << "The postfix expression (before conversion) has " << numTokens << " tokens.\n";
//    for( auto token : tokens )
//        token->print();
//    std::cout << std::endl;
//
//    InfixToPostfix *itop = new InfixToPostfix();
//    std::vector<Token *> postfixTokens;
//    itop->convert( tokens, postfixTokens );
//    std::cout << "\nThe postfix expression has " << postfixTokens.size() << " tokens.\n";
//    for( auto postfixToken : postfixTokens)
//        postfixToken->print();
//    std::cout << std::endl;


    std::ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);

    inputStream.close();

    Tokenizer tokenizer(argv[1]);

    SymbolTable symbolTable;

    Token* token = tokenizer.getToken();
    while(!token->eof()) {
        if(!token->isAVariable()) {
            std::cout << token->getVariable() << " is an invalid variable. Terminating..." << std::endl;
            exit(2);
        }

        char variable = token->getVariable();

        token = tokenizer.getToken();   // expecting '='
        if(!token->isEqualSign()) {
            std::cout << token->getVariable() << " should be an '='. Terminating...." << std::endl;
        }

        std::vector<Token*> inFixVect;

        token = tokenizer.getToken();

        while(!token->eol()) {
            inFixVect.push_back(token);
            token = tokenizer.getToken();
        }

        inFixVect.push_back(token);

        // convert inFixVect to postFixVect
        InfixToPostfix infixToPostfix;
        std::vector<Token*> postFixVect;
        infixToPostfix.convert(inFixVect, postFixVect);

        std::vector<int> result;

        for(auto token : postFixVect) {
            if(token->isAVariable()) {
                if(symbolTable.find(token->getVariable()) == -1) {
                    std::cout << token->getVariable() << " does not exist. Terminating..." << std::endl;
                    exit(2);
                }
                else {
                    result.push_back(symbolTable.find(token->getVariable()));
                }
            }
            else if(token->isRomanNumber()) {
                Number number(token->romanNumber());
                if(number.intValue() > 3999) {
                    std::cout << number.initialRomanNumber() << " is too large of a number. Terminating..." << std::endl;
                    exit(2);
                }
                if(!number.isALegalRomanNumber()) {
                    std::cout << number.initialRomanNumber() << " is invalid. Terminating..." << std::endl;
                    exit(2);
                }
                result.push_back(number.intValue());
            }
            else {
                if(token->isAdditionOperator()) {
                    int rightValue = result.back();
                    result.pop_back();
                    int leftValue = result.back();
                    result.pop_back();
                    int value = leftValue + rightValue;
                    result.push_back(value);
                }
                else if(token->isSubtractionOperator()) {
                    int rightValue = result.back();
                    result.pop_back();
                    int leftValue = result.back();
                    result.pop_back();
                    int value = leftValue - rightValue;
                    result.push_back(value);
                }
                else if(token->isMultiplicationOperator()) {
                    int rightValue = result.back();
                    result.pop_back();
                    int leftValue = result.back();
                    result.pop_back();
                    int value = leftValue * rightValue;
                    result.push_back(value);
                }
                else if(token->isDivisionOperator()) {
                    int rightValue = result.back();
                    result.pop_back();
                    int leftValue = result.back();
                    result.pop_back();
                    int value = leftValue / rightValue;
                    result.push_back(value);
                }
                else if(token->isModuloOperator()) {
                    int rightValue = result.back();
                    result.pop_back();
                    int leftValue = result.back();
                    result.pop_back();
                    int value = leftValue % rightValue;
                    result.push_back(value);
                }
            }
        }

        Number number(result[0]);

        symbolTable.add(variable, number.intValue());

        std::cout << variable << " equals " << number.romanValue() << std::endl;

        token = tokenizer.getToken();
    }

    return 0;
}
