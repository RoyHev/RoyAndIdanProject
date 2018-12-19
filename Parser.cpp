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

#define OPEN_SERVER "openDataServer"
#define IF_CONDITION "if"
#define WHILE_LOOP "while"
#define CONNECT "connect"
#define VAR "var"
#define PRINT "print"
#define SLEEP "sleep"
#define ASSIGN "="

using namespace std;

Parser::Parser(vector<string> lexStrings) {
    this->lexStrings = lexStrings;
    this->index = 0;

}

map<string, Expression *> Parser::commandsGenerator() {
    map<string, Expression *> commandsExMap;
    commandsExMap.insert(make_pair(OPEN_SERVER,new CommandExpression(new OpenDataServerCommand(),this->lexStrings,index)));
    commandsExMap.insert(make_pair(IF_CONDITION,new CommandExpression(new IfCommand(),this->lexStrings,index)));
    commandsExMap.insert(make_pair(WHILE_LOOP,new CommandExpression(new LoopCommand(),this->lexStrings,index)));
    commandsExMap.insert(make_pair(CONNECT,new CommandExpression(new ConnectCommand(),this->lexStrings,index)));
    commandsExMap.insert(make_pair(VAR,new CommandExpression(new CreateVarCommand(),this->lexStrings,index)));
    commandsExMap.insert(make_pair(PRINT,new CommandExpression(new PrintCommand(),this->lexStrings,index)));
    commandsExMap.insert(make_pair(SLEEP,new CommandExpression(new SleepCommand(),this->lexStrings,index)));
    commandsExMap.insert(make_pair(ASSIGN,new CommandExpression(new AssignCommand(),this->lexStrings,index)));
    return commandsExMap;
}
