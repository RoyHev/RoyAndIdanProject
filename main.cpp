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
#include "PrintCommand.h"

using namespace std;


int main(int argc, char *argv[]) {
    vector<string> v;
    v.push_back("nothing");
    v.push_back("idan - idan");
    VarManager *varManager = new VarManager();
    varManager->addToSymbolTable("xyz", 10.425);
    varManager->addToSymbolTable("idan", 0.426);
    PrintCommand *printCommand = new PrintCommand(varManager);
//    ShuntingYard *shuntingYard = new ShuntingYard(varManager);
    int x = printCommand->execute(0,v);
//    Expression *e = shuntingYard->evaluateInfix("idan - xyz");
//    cout << e->calculate() << endl;

    return 0;
}