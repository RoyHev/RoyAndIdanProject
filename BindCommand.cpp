//
// Created by idantp on 12/19/18.
//

#include "BindCommand.h"

#define QUOTE '"'
#define NUM_OF_ARGS 1

BindCommand::BindCommand(VarManager* varManager) {
    this->varManager = varManager;
}

int BindCommand::execute(int index, vector<string> data) {
    string variableName = data.at(index - 1);
    string bindTo = data.at(index + 1);
    bool isPath = true;
    if (bindTo.at(0) != QUOTE){
        isPath = false;
    }
    if (isPath == false){
        string pathOfVarToBindTo = varManager->getPathByName(bindTo);

    } else {


    }
    return NUM_OF_ARGS;
}
