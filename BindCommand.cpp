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
    //bindTo is a variable name and not a path.
    if (isPath == false){
        string pathOfVarToBindTo = varManager->getPathByName(bindTo);
        double valueOfBindTo = varManager->getValueByName(bindTo);
        //variable already exists in binded and need to set a new bind.
        if (varManager->doesExistInBindedVars(variableName)){
            varManager->setPathByName(variableName,pathOfVarToBindTo);
        } else {
            varManager->addToBindedVars(variableName,pathOfVarToBindTo);
        }
        //set the value of the bindTo variable's to also be variableNames val.
        varManager->setValueByName(variableName,valueOfBindTo);
        //bindTo specifies a path and not a variable that exists in the DataB.
    } else {
        if (varManager->doesExistInBindedVars(variableName)){
            varManager->setPathByName(variableName,bindTo);
        } else {
            varManager->addToBindedVars(variableName,bindTo);
        }
    }
    return NUM_OF_ARGS;
}
