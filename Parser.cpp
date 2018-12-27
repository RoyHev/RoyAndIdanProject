//
// Created by roy on 17/12/18.
//

#include "Parser.h"
#include <vector>
#include "CommandExpression.h"
#include "Command.h"
#include "OpenDataServerCommand.h"
#include "LoopCommand.h"
#include "ConditionParser.h"
#include "IfCommand.h"
#include "VarManager.h"
#include "BindCommand.h"

#define OPEN_SERVER "openDataServer"
#define IF_CONDITION "if"
#define WHILE_LOOP "while"
#define CONNECT "connect"
#define VAR "var"
#define PRINT "print"
#define SLEEP "sleep"
#define ASSIGN "="
#define BIND "=bind"


using namespace std;

Parser::Parser(vector<string> &lexStrings, VarManager *varManager,
               map<string, Expression *> *commands, int &index) :
        index(index), lexStrings(lexStrings) {
    this->lexStrings = lexStrings;
    this->varManager = varManager;
    this->commandsMap = commands;
}

void Parser::parseLexer() {
    this->index = 0;
    string temp;
    //go over the lexer and execute only if it is a command.
    while (index < this->lexStrings.size()) {
        temp = this->lexStrings[index];
        //not a command, increase the index and continue to next iteration.
        if (this->commandsMap->find(temp) == commandsMap->end()) {
            index++;
            continue;
        }
        //otherwise, it is a command, index is moved as many as the command args
        Expression *command = this->commandsMap->find(temp)->second;
        index += command->calculate();
        index++;
    }
}
