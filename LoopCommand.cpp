//
// Created by roy on 19/12/18.
//

#include "LoopCommand.h"


int LoopCommand::execute(int index, vector<string> data) {
    int i = index;
    int counter = 0;
    int temp;
    ConditionParser *conditionParser = new ConditionParser(varManager);
    while (conditionParser->conditionCheck(i, data)) {
        temp = conditionParser->execute(index, data);
    }
    counter = conditionParser->indexIncrement(i, data);
    return counter;
}

LoopCommand::LoopCommand(VarManager *varManager) : ConditionParser(varManager) {
    this->varManager = varManager;

}
