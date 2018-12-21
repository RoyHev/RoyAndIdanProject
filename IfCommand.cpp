//
// Created by roy on 19/12/18.
//

#include "IfCommand.h"

int IfCommand::execute(int index, vector<string> data) {
    int i = index;
    int counter = 0;
    ConditionParser *conditionParser = new ConditionParser(varManager);
    if (conditionParser->conditionCheck(i, data)) {
        counter = conditionParser->execute(index, data);
    } else {
        counter = conditionParser->indexIncrement(i, data);
    }
    return counter;
}

IfCommand::IfCommand(VarManager *varManager) : ConditionParser(varManager) {
    this->varManager = varManager;

}
