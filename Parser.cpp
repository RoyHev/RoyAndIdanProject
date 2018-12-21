//
// Created by roy on 17/12/18.
//

#include "Parser.h"
#include <vector>
#include "CommandExpression.h"
#include "Command.h"
#include "OpenDataServer.h"
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

Parser::Parser(vector<string> lexStrings, VarManager *varManager) {
    this->lexStrings = lexStrings;
    this->index = 0;
    this->varManager = varManager;
    this->commandsMap = commandsGenerator();
}

map<string, Expression *> Parser::commandsGenerator() {
    map<string, Expression *> commandsExMap;
    commandsExMap.insert(make_pair(BIND, new CommandExpression(new
                                                                       BindCommand(varManager), lexStrings, index)));

    commandsExMap.insert(make_pair(OPEN_SERVER, new CommandExpression(new
                                                                              OpenDataServerCommand(), this->lexStrings,
                                                                      index)));

    commandsExMap.insert(make_pair(IF_CONDITION, new CommandExpression(new
                                                                               IfCommand(varManager), this->lexStrings,
                                                                       index)));
    commandsExMap.insert(make_pair(WHILE_LOOP, new CommandExpression(new
                                                                             LoopCommand(varManager), this->lexStrings,
                                                                     index)));
    commandsExMap.insert(make_pair(CONNECT, new CommandExpression(new
                                                                          ConnectCommand(), this->lexStrings, index)));
    commandsExMap.insert(make_pair(VAR, new CommandExpression(new
                                                                      CreateVarCommand(varManager), this->lexStrings,
                                                              index)));
    commandsExMap.insert(make_pair(PRINT, new CommandExpression(new
                                                                        PrintCommand(varManager), this->lexStrings,
                                                                index)));
    commandsExMap.insert(make_pair(SLEEP, new CommandExpression(new
                                                                        SleepCommand(varManager), this->lexStrings,
                                                                index)));
    commandsExMap.insert(make_pair(ASSIGN, new CommandExpression(new
                                                                         AssignCommand(varManager), this->lexStrings,
                                                                 index)));
    return commandsExMap;
}

void Parser::parseLexer() {
    this->index = 0;
    string temp;
    //go over the lexer and execute only if it is a command.
    while (index < this->lexStrings.size()) {
        temp = this->lexStrings[index];
        //not a command, increase the index and continue to next iteration.
        if (this->commandsMap.find(temp) == commandsMap.end()) {
            index++;
            continue;
        }
        Expression *command;
        //otherwise, it is a command, index is moved as many as the command args
        if (temp == BIND) {
            command = new CommandExpression(new BindCommand(varManager), lexStrings, index);
        } else if (temp == OPEN_SERVER) {
            command = new CommandExpression(new OpenDataServerCommand(), this->lexStrings, index);
        }else if(temp == IF_CONDITION){
            command = new CommandExpression(new IfCommand(varManager), this->lexStrings, index);
        } else if (temp == WHILE_LOOP){
            command = new CommandExpression(new LoopCommand(varManager), this->lexStrings, index);
        } else if (temp == CONNECT){
            command = new CommandExpression(new ConnectCommand(), this->lexStrings, index);
        } else if (temp == VAR){
            command = new CommandExpression(new CreateVarCommand(varManager), this->lexStrings, index);
        } else if (temp == PRINT){
            command = new CommandExpression(new PrintCommand(varManager), this->lexStrings, index);
        } else if (temp == SLEEP){
            command = new CommandExpression(new SleepCommand(varManager), this->lexStrings, index);
        } else if (temp == ASSIGN){
            command = new CommandExpression(new AssignCommand(varManager), this->lexStrings, index);
        }

        //Expression* command = this->commandsMap.find(temp)->second;
//        Expression *command = new CommandExpression(new CreateVarCommand(varManager), this->lexStrings, index);
        index += command->calculate();
        index++;
    }
}
