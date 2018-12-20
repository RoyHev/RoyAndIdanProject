//
// Created by idantp on 12/20/18.
//

#include <strings.h>
#include "ConditionParser.h"
#include "BindCommand.h"

#define GREATER ">"
#define LOWER "<"
#define GREATER_EQUAL ">="
#define LOWER_EQUAL "<="
#define EQUALITY "=="
#define INEQUALITY "!="
#define WHILE_LOOP "while"
#define IF_CONDITION "if"

ConditionParser::ConditionParser(VarManager *varManager) {
    this->varManager = varManager;
}

int ConditionParser::execute(int index, vector<string> data) {
    bool isLoop = false;
    //Must get "while" or "if"
    string conditionStr = data.at(index);
    if (conditionStr == WHILE_LOOP) {
        isLoop = true;
    }
    Parser *scopeParser = new Parser(data, varManager);
    ShuntingYard *sh = new ShuntingYard(varManager);
    string strOperand1 = data.at(index + 1);
    double operand1 = sh->evaluateInfix(strOperand1)->calculate();
    string strOperand2 = data.at(index + 3);
    double operand2 = sh->evaluateInfix(strOperand2)->calculate();
    string operation = data.at(index + 2);

    if (operation == GREATER) {
        if (operand1 > operand2) {}
        else {

        }
    } else if (operation == GREATER_EQUAL) {
        if (operand1 >= operand2) {}
        else {}
    } else if (operation == LOWER) {
        if (operand1 < operand2) {}
        else {}
    } else if (operation == LOWER_EQUAL) {
        if (operand1 <= operand2) {}
        else {}
    } else if (operation == EQUALITY) {
        if (operand1 == operand2) {}
        else {}
    } else if (operation == INEQUALITY) {
        if (operand1 != operand2) {}
        else {}
    }
}
