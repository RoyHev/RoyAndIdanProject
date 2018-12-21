//
// Created by roy on 19/12/18.
//

#include "IfCommand.h"

int IfCommand::execute(int index, vector<string> data) {
    return 0;
}

IfCommand::IfCommand(VarManager *varManager) : ConditionParser(varManager) {
    this->varManager = varManager;

}
