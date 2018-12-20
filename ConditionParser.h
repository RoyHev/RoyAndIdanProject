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
    vector<Command*> commandsVector;
public:
    virtual int execute(int index, vector<string> data) = 0;

};
#endif //EX3_CONDITIONPARSER_H
