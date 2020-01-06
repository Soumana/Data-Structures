#include <iostream>
#include <vector>
#include <stack>
#include "Token.hpp"
#include "Tokenizer.hpp"

int topValue(std::stack<int> &stack) {
    if( stack.empty()) {
        std::cout << "main: Pop operation on an empty stack is not a good idea. Terminating...";
        exit(1);
    }
    int toReturn = stack.top();
    stack.pop();
    return toReturn;
}

int evaluateExpression(const std::vector<Token> &exprTokens ) {
    std::stack<int> evalStack;
    int top = 0;
    for(Token token : exprTokens) {
        // we push the number tokens on a stack until we fine a token
        // that represents an arithmetic operator. Once we see an
        // arithmetic operator, we pop the last two elements of the stack,
        // apply the operator to them, and push the result back onto the stack.
        // If the expression is well formed, once we see the new-line token,
        // the stack will have one single value and that is the result
        // of the expression.
        if (token.isNumber())
            evalStack.push(token.numberValue());
        else if( token.isArithSymbol()) {
            // All operators are binary operators.
            int rightExpr = topValue(evalStack);
            int leftExpr = topValue(evalStack);

            switch(token.arithSymbol()) {
                case '+':
                    evalStack.push(leftExpr + rightExpr);
                    break;
                case '-':
                    evalStack.push(leftExpr - rightExpr);
                    break;
                case '*':
                    evalStack.push(leftExpr * rightExpr);
                    break;
                case '/':
                    evalStack.push(leftExpr / rightExpr);
                    break;
                case '%':
                    evalStack.push(leftExpr % rightExpr);
                    break;
                default:
                    std::cout << "evaluate: Don't know what to do with this operator. ->" << token.arithSymbol() << "<-\n";
            }
        } else if(token.endOfLine())
            return topValue(evalStack);
        else {
            std::cout << "evaluate: Don't know what to do with the following token.\n";
            token.print();
            exit(2);
        }
    }
    std::cout << "evaluate: evaluating empty expression?";
    return 0;
}

int main(int argc, char *argv[]) {
    if( argc != 2 ) {
        std::cout << "usage:" << argv[0] << " nameOfInputFile\n";
        exit(2);
    }

    Tokenizer tokenizer(argv[1]);
    Token token;
    std::vector<Token> tokens;
    do {
        // store the tokens on each line in vector "tokens". Once we
        // find a new-line token, we evaluate the expression and
        // write its value out.
        token = tokenizer.getToken();
        token.print();
        if(token.endOfLine() && tokens.size() > 0) {
            tokens.push_back(token);
            std::cout <<  evaluateExpression(tokens) << std::endl;
            tokens.clear();
        } else if(token.endOfLine())
            continue;  // ignore empty lines
        else
            tokens.push_back(token);
    } while( ! token.endOfFile() );
    return 0;
}
