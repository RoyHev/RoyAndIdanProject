//
// Created by roy on 17/12/18.
//
#include "CommandExpression.h"
#include "Command.h"

CommandExpression::CommandExpression(Command &cmd, vector<string> &lexer,
        int &index) :cmd(cmd), lexer(lexer), index(index) {
}

double CommandExpression::calculate() {
    this->cmd.execute(this->index, this->lexer);
}
