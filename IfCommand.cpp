//
// Created by roy on 19/12/18.
//

#include "IfCommand.h"


/*
 * the function gets a vector of data which contains at least one condition,
 * and an index that points to the first condition string. the first element is "if",
 * the next 3 strings are 2 operands and 1 condition operator.
 * the function parses the loop as long as the condition is true.
 * the function returns an index to the last element that describes the condition's scope ("}").
 */
int IfCommand::execute(int index, vector<string> data) {
    int i = index;
    int counter = 0;
    ConditionParser *conditionParser = new ConditionParser(varManager);
    if (conditionParser->conditionCheck(i, data)) {
        counter = conditionParser->execute(index, data);
    } else {
        counter = conditionParser->indexIncrement(i, data);
    }
    return counter-index;
}

IfCommand::IfCommand(VarManager *varManager) : ConditionParser(varManager) {
    this->varManager = varManager;

}
