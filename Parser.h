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
#include "VarManager.h"

using namespace std;

class Parser {
    VarManager* varManager;
    vector<string> lexStrings;
    map<string, Expression *> *commandsMap;
    int index;
public:
    Parser(vector<string> lexStrings,VarManager *varManager,map<string,Expression*> *commands);
    void parseLexer();
};


#endif //EX3_PARSER_H
