//
// Created by roy on 17/12/18.
//

#ifndef EX3_COMMANDEXPRESSION_H
#define EX3_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"
#include <vector>
#include <string>

using namespace std;

class CommandExpression: public Expression{
    Command* &cmd;
    vector<string> &lexer;
    int &index;
public:
    CommandExpression(Command* &cmd, vector<string> &lexer, int &index);
    virtual double calculate();
};

#endif //EX3_COMMANDEXPRESSION_H
