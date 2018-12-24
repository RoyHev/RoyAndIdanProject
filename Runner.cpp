//
// Created by idantp on 12/24/18.
//

#include "Runner.h"
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

Runner::Runner() {
}

map<string, Expression *> Runner::commandsGenerator(vector<string> lexStrings) {
    map<string, Expression *> commandsExMap;
    int index = 0;
    commandsExMap.insert(make_pair(BIND, new CommandExpression(new BindCommand(varManager), lexStrings, index)));

    commandsExMap.insert(
            make_pair(OPEN_SERVER,
                      new CommandExpression(new OpenDataServerCommand(varManager), lexStrings, index)));
    commandsExMap.insert(
            make_pair(IF_CONDITION, new CommandExpression(new IfCommand(varManager, <#initializer#>), lexStrings, index)));
    commandsExMap.insert(
            make_pair(WHILE_LOOP, new CommandExpression(new LoopCommand(varManager, <#initializer#>), lexStrings, index)));
    commandsExMap.insert(make_pair(CONNECT, new CommandExpression(new ConnectCommand(new OpenClientSocket(), varManager), lexStrings, index)));
    commandsExMap.insert(
            make_pair(VAR, new CommandExpression(new CreateVarCommand(varManager), lexStrings, index)));
    commandsExMap.insert(
            make_pair(PRINT, new CommandExpression(new PrintCommand(varManager), lexStrings, index)));
    commandsExMap.insert(
            make_pair(SLEEP, new CommandExpression(new SleepCommand(varManager), lexStrings, index)));
    commandsExMap.insert(
            make_pair(ASSIGN, new CommandExpression(new AssignCommand(varManager), lexStrings, index)));
    return commandsExMap;
}

void Runner::run(string fileName) {
    VarManager* varManager = new VarManager();
    Lexer *lexer = new Lexer();
    vector<string> lexeredFile = lexer->lexerFromFile(fileName);
    Parser* parser = new Parser(lexeredFile,varManager);


}