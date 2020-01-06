//
// Created by Soumana Sylla on 2019-11-07.
//

#include "JSONParser.hpp"
#include <iostream>

JSONParser::JSONParser(JSONTokenizer &tokenizer) : tokenizer{tokenizer} {}

Pair JSONParser::parseAPair() {
    JSONToken token = tokenizer.getToken();
    if( ! token.isAttributeString()) {
        std::cout << "Error: JSONParser::JSONParser: Expected a string, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    JSONToken nextToken1 = tokenizer.getToken();
    JSONToken nextToken2 = tokenizer.getToken();

    if( ! nextToken1.isColon() ) {
        std::cout << "Error: JSONParser::JSONParser: Expected a colon, but found" << std::endl;
        nextToken1.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    if ( ! nextToken2.isAttributeString() && ! nextToken2.isAttributeNum() ) {
        std::cout << "Error: JSONParser::JSONParser: Expected a string or double but found" << std::endl;
        nextToken2.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }

    if(nextToken2.isAttributeString()) {
        return Pair(token.attributeString(), nextToken2.attributeString());
    }
    else {
        return Pair(token.attributeString(), nextToken2.attributeNum());
    }
}

EntityInstance JSONParser::parseJSONObject() {
    // parseJSONObject is responsible for parsing a JSON object. As such,
    // the first token is expected to be an open brace.
    JSONToken token = tokenizer.getToken();
    if( ! token.isOpenBrace() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an open brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    EntityInstance instance;
    do {
        Pair pair = parseAPair();
        instance.addAttribute(pair);
        token = tokenizer.getToken();
    } while( token.isComma() );  // after having read a pair, we expect a comma
    // So, we didn't find a comma. Then, it must be a close brace.
    if( ! token.isCloseBrace() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an close brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    return instance;
}

Entity JSONParser::parseJSONEntity() {
    JSONToken token = tokenizer.getToken();
    if( ! token.isOpenBracket() ) {
        std::cout << "Error: JSONParser::parseJSONEntity: Expected an open bracket, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }

    Entity entity;

    while( ! token.isCloseBracket() ) {
        EntityInstance instance = parseJSONObject();
        entity.addObject(instance);
        token = tokenizer.getToken();
        if( ! token.isComma() ) {
            break;
        }
    }

    if( ! token.isCloseBracket()) {
        std::cout << "Error: JSONParser::parseJSONEntity: Expected a closed bracket, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }

    return entity;
}
