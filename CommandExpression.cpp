//
// Created by roy on 17/12/18.
//
#include "CommandExpression.h"
#include "Command.h"

CommandExpression::CommandExpression(Command* cmd, vector<string> lexer,
        int &index) : index(index) {
    this->cmd = cmd;
    this->lexer = lexer;
}

double CommandExpression::calculate() {
    return this->cmd->execute(this->index, lexer);
}