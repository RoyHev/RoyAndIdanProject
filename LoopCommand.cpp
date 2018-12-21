//
// Created by roy on 19/12/18.
//

#include "LoopCommand.h"



int LoopCommand::execute(int index, vector<string> data) {
    return 0;
}

LoopCommand::LoopCommand(VarManager *varManager) : ConditionParser(varManager) {
    this->varManager = varManager;

}
