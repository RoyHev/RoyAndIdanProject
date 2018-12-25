//
// Created by roy on 17/12/18.
//

#ifndef EX3_COMMANDEXPRESSION_H
#define EX3_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"
#include <vector>
#include <string>
#include "OpenDataServerCommand.h"
#include "Command.h"
#include "CreateVarCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "AssignCommand.h"
#include "ConnectCommand.h"

using namespace std;

class CommandExpression: public Expression{
    Command* cmd;
    vector<string> lexer;
    int &index;
public:
    CommandExpression(Command* cmd, vector<string> lexer, int &index);
    virtual double calculate();
};

#endif //EX3_COMMANDEXPRESSION_H
