//
// Created by roy on 17/12/18.
//

#ifndef EX3_PARSER_H
#define EX3_PARSER_H

#include <string>
#include <vector>
#include <map>

#include "Command.h"
#include "CommandExpression.h"
#include "Data.h"

using namespace std;

class Parser {
    vector<string> lexStrings;
    map<string, Expression *> commandsMap;
    int index;
public:
    Parser(vector<string> lexStrings);
    void parseLexer();

private:
    map<string,Expression*> commandsGenerator();
};


#endif //EX3_PARSER_H
