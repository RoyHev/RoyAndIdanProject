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
int IfCommand::execute(int &index, vector<string> data) {
    int elementsInScope = 0;
    int initialIndex = index;
    ConditionParser conditionParser(varManager, commandsMap);
    //parsing the if scope - if condition is true
    if (conditionParser.conditionCheck(index, data)) {
        conditionParser.execute(index, data);
    }
    elementsInScope = conditionParser.indexIncrement(index, data);
    //return the index to the last element in the current scope
    return elementsInScope - initialIndex;
}

IfCommand::IfCommand(VarManager *varManager, map<string, Expression *> *commandsMap) : ConditionParser(varManager,
                                                                                                       commandsMap) {
    this->varManager = varManager;
    this->commandsMap = commandsMap;
}
