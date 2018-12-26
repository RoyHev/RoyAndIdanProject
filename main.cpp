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
#include "Runner.h"
using namespace std;


int main(int argc, char *argv[]) {
    Runner* runner = new Runner("text.txt");
    runner->run();
    return 0;
}