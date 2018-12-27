//
// Created by roy on 19/12/18.
//

#include "LoopCommand.h"

int LoopCommand::execute(int &index, vector<string> data) {
    //gets the number of elements in the current scope
    int elementsInScope = 0;
    //an index to the first element in the current scope
    int initialIndex = index;
    ConditionParser conditionParser(varManager, commandsMap);
    //parsing the while scope
    while (conditionParser.conditionCheck(index, data)) {
        conditionParser.execute(index, data);
    }
    elementsInScope = conditionParser.indexIncrement(index, data);
    //return the index to the last element in the current scope
    return elementsInScope - initialIndex;
}

LoopCommand::LoopCommand(VarManager *varManager, map<string, Expression *> *commandsMap) : ConditionParser(varManager,
                                                                                                           commandsMap) {
    this->varManager = varManager;
    this->commandsMap = commandsMap;

}
