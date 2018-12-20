//
// Created by idantp on 12/20/18.
//

#include <strings.h>
#include "ConditionParser.h"
#include "BindCommand.h"

ConditionParser::ConditionParser(VarManager *varManager) {
    this->varManager = varManager;
}

int ConditionParser::execute(int index, vector<string> data) {
    Parser *scopeParser = new Parser(data, varManager);
    ShuntingYard *sh = new ShuntingYard(varManager);
    string strOperand1 = data.at(index + 1);
    double operand1 = sh->evaluateInfix(strOperand1)->calculate();
    string strOperand2 = data.at(index + 3);
    double operand2 = sh->evaluateInfix(strOperand2)->calculate();
    string operation = data.at(index + 2);

}
