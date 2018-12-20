//
// Created by roy on 17/12/18.
//

#include "Parser.h"
#include <vector>
#include "CommandExpression.h"
#include "Command.h"
#include "OpenDataServer.h"
#include "LoopCommand.h"
#include "IfCommand.h"
#include "VarManager.h"

#define OPEN_SERVER "openDataServer"
#define IF_CONDITION "if"
#define WHILE_LOOP "while"
#define CONNECT "connect"
#define VAR "var"
#define PRINT "print"
#define SLEEP "sleep"
#define ASSIGN "="


using namespace std;

Parser::Parser(vector<string> lexStrings, VarManager *varManager) {
    this->lexStrings = lexStrings;
    this->index = 0;
    this->commandsMap = commandsGenerator();
    this->varManager = varManager;
}

map<string, Expression *> Parser::commandsGenerator() {
    map<string, Expression *> commandsExMap;
    commandsExMap.insert(
            make_pair(OPEN_SERVER, new CommandExpression(new OpenDataServerCommand(), this->lexStrings, index)));
    commandsExMap.insert(make_pair(IF_CONDITION, new CommandExpression(new IfCommand(), this->lexStrings, index)));
    commandsExMap.insert(make_pair(WHILE_LOOP, new CommandExpression(new LoopCommand(), this->lexStrings, index)));
    commandsExMap.insert(make_pair(CONNECT, new CommandExpression(new ConnectCommand(), this->lexStrings, index)));
    commandsExMap.insert(make_pair(VAR, new CommandExpression(new CreateVarCommand(), this->lexStrings, index)));
    commandsExMap.insert(make_pair(PRINT, new CommandExpression(new PrintCommand(varManager), this->lexStrings, index)));
    commandsExMap.insert(make_pair(SLEEP, new CommandExpression(new
    SleepCommand(varManager), this->lexStrings, index)));
    commandsExMap.insert(make_pair(ASSIGN, new CommandExpression(new AssignCommand(varManager), this->lexStrings, index)));
    return commandsExMap;
}

void Parser::parseLexer() {
    for (int i = 0; i < this->lexStrings.size(); i++) {
        string str = lexStrings.at(i);
        if (commandsMap.find(str) != commandsMap.end()) {
            Expression *command = commandsMap.find(str)->second;
            i += command->calculate();
        }
    }
}
