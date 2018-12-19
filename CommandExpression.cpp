//
// Created by roy on 17/12/18.
//
#include "CommandExpression.h"
#include "Command.h"

CommandExpression::CommandExpression(Command* cmd, vector<string> &lexer,
        int &index) : lexer(lexer), index(index) {
    this->cmd = cmd;
}

//TODO - return this?
double CommandExpression::calculate() {
    return this->cmd->execute(this->index, this->lexer);
}
