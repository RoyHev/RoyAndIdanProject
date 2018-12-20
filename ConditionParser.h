//
// Created by roy on 19/12/18.
//

#ifndef EX3_CONDITIONPARSER_H
#define EX3_CONDITIONPARSER_H

#include "Parser.h"
#include "Command.h"
#include "CommandExpression.h"
#include <vector>
#include <string>
#include "Command.h"
#include "VarManager.h"
#include "Expression.h"
#include "BindCommand.h"
#include <strings.h>
#include "OpenDataServer.h"


class ConditionParser : public Command {
    VarManager *varManager;
    Parser *parser;

public:
    ConditionParser(VarManager *varManager);

    virtual int execute(int index, vector<string> data);

};

#endif //EX3_CONDITIONPARSER_H
