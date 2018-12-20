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
#define BRACKET_CLOSER "}"
#define BRACKET_OPENER "{"


ConditionParser::ConditionParser(VarManager *varManager) {
    this->varManager = varManager;
}

int ConditionParser::indexIncrement(int i, vector<string> data) {
    int increments = 0;
    while (data.at(i) != BRACKET_OPENER) {
        increments++;
        i++;
    }
    increments++;
    i++;
    int bracketsRatio = 1;
    while (bracketsRatio != 0) {
        if (data.at(i) == BRACKET_OPENER) {
            bracketsRatio++;
        } else if (data.at(i) == BRACKET_CLOSER) {
            bracketsRatio--;
        }
        increments++;
        i++;
    }
    return increments;
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
    int indexCopy = index;
    if (operation == GREATER) {
        if (operand1 > operand2) {
            if(isLoop){

            }
        }
        else {
            return indexIncrement(indexCopy,data);
        }
    } else if (operation == GREATER_EQUAL) {
        if (operand1 >= operand2) {
            if(isLoop){

            }
        }
        else {
            return indexIncrement(indexCopy,data);
        }
    } else if (operation == LOWER) {
        if (operand1 < operand2) {
            if(isLoop){

            }
        }
        else {
            return indexIncrement(indexCopy,data);
        }
    } else if (operation == LOWER_EQUAL) {
        if (operand1 <= operand2) {
            if(isLoop){

            }
        }
        else {
            return indexIncrement(indexCopy,data);
        }
    } else if (operation == EQUALITY) {
        if (operand1 == operand2) {
            if(isLoop){

            }
        }
        else {
            return indexIncrement(indexCopy,data);
        }
    } else if (operation == INEQUALITY) {
        if (operand1 != operand2) {
            if(isLoop){

            }
        }
        else {
            return indexIncrement(indexCopy,data);
        }
    }
}

