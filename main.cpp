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

using namespace std;


int main(int argc, char *argv[]) {
    VarManager *varManager = new VarManager();
    varManager->addToSymbolTable("xyz",10.425);
    varManager->addToSymbolTable("idan", 0.426);
    ShuntingYard* shuntingYard = new ShuntingYard(varManager);
    Expression *e = shuntingYard->evaluateInfix("idan - xyz");
    cout << e->calculate() << endl;

    return 0;
}