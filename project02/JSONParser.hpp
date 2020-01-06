//
// Created by Soumana Sylla on 2019-11-07.
//

#ifndef PROJECT02_JSONPARSER_HPP
#define PROJECT02_JSONPARSER_HPP

#include "JSONTokenizer.hpp"
#include "Pair.hpp"
#include "EntityInstance.hpp"
#include "Entity.hpp"

class JSONParser {
public:
    JSONParser(JSONTokenizer &tokenizer);
    Pair parseAPair();
    EntityInstance parseJSONObject();
    Entity parseJSONEntity();

private:
    JSONTokenizer &tokenizer;
};

#endif //PROJECT02_JSONPARSER_HPP
