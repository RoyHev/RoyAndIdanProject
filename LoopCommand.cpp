//
// Created by roy on 19/12/18.
//

#include "LoopCommand.h"

int LoopCommand::execute(int index, vector<string> data) {
    int i = index;
    int counter = 0;
    int temp;
    ConditionParser *conditionParser = new ConditionParser(varManager, commandsMap);
    while (conditionParser->conditionCheck(i, data)) {
        counter = conditionParser->execute(index, data);
    }
    counter = conditionParser->indexIncrement(i, data);
    return counter - index;
}

LoopCommand::LoopCommand(VarManager *varManager, map<string,Expression*> *commandsMap) : ConditionParser(varManager,
        commandsMap) {
    this->varManager = varManager;
    this->commandsMap = commandsMap;

}
