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


ConditionParser::ConditionParser(VarManager *varManager, map<string, Expression *> *commandsMap) {
    this->varManager = varManager;
    this->commandsMap = commandsMap;
}

/*
 * the function gets a vector of data which contains at least one condition or loop
 * and an index that points to the first condition string. the function returns the index to the
 * condition's corresponding BRACKET_CLOSER ("}").
 */
int ConditionParser::indexIncrement(int i, vector<string> data) {
    while (data.at(i) != BRACKET_OPENER) {
        i++;
    }
    i++;
    int bracketsRatio = 1;
    while (bracketsRatio != 0) {
        if (data.at(i) == BRACKET_OPENER) {
            bracketsRatio++;
        } else if (data.at(i) == BRACKET_CLOSER) {
            bracketsRatio--;
            //don't skip the index of BRACKET_CLOSER
            if (bracketsRatio == 0) {
                continue;
            }
        }
        i++;
    }
    return i;
}

/*
 * the function gets a vector of data which contains at least one loop,
 * and an index that points to the first condition string.
 * the function creates a new vector<string> that describes the condition's scope only,
 * and parses it.
 * the function returns an index to the last element that describes the condition's scope.
 */
int ConditionParser::execute(int &index, vector<string> data) {
    //save index by value
    int indexKeeper = index;
    int i = index;
    //counts the elements amount is the current scope.
    int elementsCounter = 0;
    vector<string> scopeLexerVector;
    //increment the index
    while (data.at(i) != BRACKET_OPENER) {
        i++;
    }
    i++;
    //an index to the  first element in the current scope
    int firstScopeString = i;
    int bracketsRatio = 1;
    while (bracketsRatio != 0) {
        if (data.at(i) == BRACKET_OPENER) {
            bracketsRatio++;
        } else if (data.at(i) == BRACKET_CLOSER) {
            bracketsRatio--;
            //don't push the last brackets
            if (bracketsRatio == 0) {
                continue;
            }
        }
        scopeLexerVector.push_back(data.at(i));
        i++;
        elementsCounter++;
    }
    //set index to the first element in the current scope
    index = firstScopeString;
    //an index to the  last element in the current scope
    int lastScopeString = index + elementsCounter - 1;
    string temp = "";
    //parsing the current scope
    while (index < lastScopeString) {
        temp = data[index];
        if (commandsMap->find(temp) == commandsMap->end()) {
            index++;
            continue;
        }
        Expression *conditionCommand = this->commandsMap->find(temp)->second;
        index += conditionCommand->calculate();
        index++;
    }
    index = indexKeeper;
    return lastScopeString;
}

/*
 * the function gets a vector of data which contains one condition or loop
 * and an index that points to the first condition string.
 * the function checks the condition (or the loop condition) and returns true if the
 * condition is correct and false if the condition is not.
 * if inside the condition there is not a condition operator, the function throws an error.
 */
bool ConditionParser::conditionCheck(int i, vector<string> data) {
//    Parser *scopeParser = new Parser(data, varManager, commandsMap);
    string strOperand1 = data.at(i + 1);
    ShuntingYard sh(varManager);
    Expression *exp = sh.evaluateInfix(strOperand1);
    double operand1 = exp->calculate();
    delete exp;
    string strOperand2 = data.at(i + 3);
    exp = sh.evaluateInfix(strOperand2);
    double operand2 = exp->calculate();
    string operation = data.at(i + 2);
    delete (exp);
    //find the condition operator and return true or false accordingly.
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
    }//for any string that does not descreibes a condition operator - throw an error.
    else {
        throw runtime_error("Syntax Error - Invalid operator.");
    }

}

