//
// Created by idantp on 12/24/18.
//

#ifndef EX3_RUNNER_H
#define EX3_RUNNER_H

#include <vector>
#include <fstream>
#include <iostream>

#include "Expression.h"
#include "Plus.h"
#include "Multiply.h"
#include "Number.h"
#include "Divide.h"
#include "Minus.h"
#include "ShuntingYard.h"
#include "Lexer.h"
#include "CommandExpression.h"
#include "VarManager.h"
#include "AssignCommand.h"
#include "PrintCommand.h"
#include "BindCommand.h"
#include "Parser.h"
#include "OpenClientSocket.h"
#include "ConnectCommand.h"

class Runner {
    VarManager* varManager;
    map<string, Expression*> commandsMap;
    vector<string> lexeredFile;
    int index;
    OpenClientSocket *openClientSocket;

public:
    explicit Runner(const char *fileName);
    ~Runner();
    void run();
private:
    map<string,Expression*> commandsGenerator(vector<string> lexStrings);
};


#endif //EX3_RUNNER_H
