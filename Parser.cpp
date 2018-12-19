//
// Created by roy on 17/12/18.
//

#include "Parser.h"
#include "OpenDataServer.h"
#include <vector>

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

map<string, CommandExpression *> Parser::commandsGenerator() {
    map<string, CommandExpression *> commandsExMap;
    commandsExMap.insert(make_pair(OPEN_SERVER,new OpenDataServerCommand()));
    commandsExMap.insert(make_pair(IF_CONDITION,IfCommand));
    commandsExMap.insert(make_pair(WHILE_LOOP,LoopCommand));
    commandsExMap.insert(make_pair(CONNECT,ConnectCommand));
    commandsExMap.insert(make_pair(VAR,CreateVarCommand));
    commandsExMap.insert(make_pair(PRINT,PrintCommand));
    commandsExMap.insert(make_pair(SLEEP,SleepCommand));
    commandsExMap.insert(make_pair(ASSIGN,AssignCommand));
    return commandsExMap;
}
