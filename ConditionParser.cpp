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

//will execute one iteration
int ConditionParser::execute(int index, vector<string> data) {
    int increments = 0;
    vector<string> scopeLexerVector;
    while (data.at(index) != BRACKET_OPENER) {
        increments++;
        index++;
    }
    increments++;
    index++;
    int bracketsRatio = 1;
    while (bracketsRatio != 0) {
        increments++;
        scopeLexerVector.push_back(data.at(index));
        if (data.at(index) == BRACKET_OPENER) {
            bracketsRatio++;
        } else if (data.at(index) == BRACKET_CLOSER) {
            bracketsRatio--;
            //don't push the last brackets
            if (bracketsRatio == 0) {
                continue;
            }
        }
        scopeLexerVector.push_back(data.at(index));
        index++;
    }
    Parser *parser = new Parser(scopeLexerVector, varManager);
    parser->parseLexer();
    return increments;
}

bool ConditionParser::conditionCheck(int i, vector<string> data) {
    Parser *scopeParser = new Parser(data, varManager);
    ShuntingYard *sh = new ShuntingYard(varManager);
    string strOperand1 = data.at(i + 1);
    double operand1 = sh->evaluateInfix(strOperand1)->calculate();
    string strOperand2 = data.at(i + 3);
    double operand2 = sh->evaluateInfix(strOperand2)->calculate();
    string operation = data.at(i + 2);
    if (operation == GREATER) {
        if (operand1 > operand2) {
            return true;
        } else {
            return false;
        }
    } else if (operation == GREATER_EQUAL) {
        if (operand1 >= operand2) {
            return true;
        } else {
            return false;
        }
    } else if (operation == LOWER) {
        if (operand1 < operand2) {
            return true;
        } else {
            return false;
        }
    } else if (operation == LOWER_EQUAL) {
        if (operand1 <= operand2) {
            return true;
        } else {
            return false;
        }
    } else if (operation == EQUALITY) {
        if (operand1 == operand2) {
            return true;
        } else {
            return false;
        }
    } else if (operation == INEQUALITY) {
        if (operand1 != operand2) {
            return true;
        } else {
            return false;
        }
    } else {
        throw runtime_error("Syntax Error - Invalid operator.");
    }

}

