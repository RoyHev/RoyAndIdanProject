//
// Created by roy on 19/12/18.
//

#ifndef EX3_CONDITIONPARSER_H
#define EX3_CONDITIONPARSER_H
#include "Command.h"
#include "CommandExpression.h"

#include <vector>
#include <string>

class ConditionParser: public Command{
    VarManager *varManager;
    map<string, Expression *> commandsMap;
public:
    ConditionParser(VarManager *varManager);
    virtual int execute(int index, vector<string> data);

};
#endif //EX3_CONDITIONPARSER_H
