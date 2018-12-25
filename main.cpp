#include <vector>
#include <fstream>
#include <iostream>

#include "Expression.h"
#include "Plus.h"
#include "Multiply.h"
#include "Number.h"
#include "Divide.h"
#include "Minus.h"
#include "Negative.h"
#include "ShuntingYard.h"
#include "Lexer.h"
#include "CommandExpression.h"
#include "VarManager.h"
#include "AssignCommand.h"
#include "PrintCommand.h"
#include "BindCommand.h"
#include "Parser.h"
#include "Runner.h"
using namespace std;


int main(int argc, char *argv[]) {
    //TODO - singltone?
    Runner* runner = new Runner("text.txt");
    runner->run();
    //cout << s->evaluateInfix("1.1934444")->calculate();

//    varManager->addToBindedVars("xy", "/instrumentation/altimeter/pressure-alt-ft");
//    varManager->addToSymbolTable("xy",0);
//    v.push_back("openDataServer");
//    v.push_back("400+5*1000");
//    v.push_back("10");
//    OpenDataServerCommand *serverCommand = new OpenDataServerCommand(varManager);
//    serverCommand->execute(0,v);
//    while(true){
//
//    }
//    Lexer *lexer = new Lexer();
//    vector<string> v = lexer->lexerFromFile("text.txt");
//    Parser* parser = new Parser(v,varManager);
//    parser->parseLexer();

//        vector<string> v;
//    v.push_back("nothing");
//    v.push_back("idan - idan");
//    v.push_back("x");
//    v.push_back("=bind");
//    string s = "";
//    s += '"';
//    s+= "/something/something/something/darkside";
//    s += '"';
//    cout << s << endl;
//    v.push_back(s);
//    v.push_back("=");
//    v.push_back("50");
//    v.push_back("xyz");
//    v.push_back("=");
//    v.push_back("90.4 - idan");
//    VarManager *varManager = new VarManager();
//    varManager->addToSymbolTable("xyz", 2000);
//    varManager->addToSymbolTable("idan", 3000);
//    AssignCommand *assignCommand = new AssignCommand(varManager);
//    assignCommand->execute(1,v);
//    BindCommand* printCommand = new BindCommand(varManager);
//    printCommand->execute(1,v);

//    cout << varManager->getValueByName("xyz");
//    ShuntingYard *shuntingYard = new ShuntingYard(varManager);

//    int x = printCommand->execute(0,v);
//    Expression *e = shuntingYard->evaluateInfix("idan - xyz");
//    cout << e->calculate() << endl;
    return 0;
}