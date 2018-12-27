//
// Created by idantp on 12/19/18.
//

#include "BindCommand.h"

#define QUOTE '"'
#define NUM_OF_ARGS 1

BindCommand::BindCommand(VarManager *varManager) {
    this->varManager = varManager;
}
/*
 * implements bind= Command, connects between var to a path in the server
 */
int BindCommand::execute(int &index, vector<string> data) {
    string newVarName = data.at(index - 1);
    string bindTo = data.at(index + 1);
    bool isPath = true;
    // false if it's a variable otherwise, it's a path so true
    if (bindTo.at(0) != QUOTE) {
        isPath = false;
    }
    //bind to is a variable.
    if (isPath == false) {
        //the bindTo varible exists in the symbol table.
        if (varManager->doesExistInBindedVars(bindTo)) {
            double newValue = varManager->getValueByName(bindTo);
            varManager->setValueByName(newVarName, newValue);
            string newPath = varManager->getPathByName(bindTo);
            varManager->addToBindedVars(newVarName, newPath);
        } else {
            perror("Cannot bind to a Var that is not binded itself.");
        }
    } else {
        string newPath = "";
        //remove the quotes from the path.
        for (int j = 1; j < bindTo.size() - 1; j++) {
            newPath += bindTo.at(j);
        }
        //bind to is from the XML file.
        if (varManager->doesExistInPathsMap(newPath)) {
            double newValue = varManager->getValueByPath(newPath);
            varManager->setValueByName(newVarName, newValue);
        } else {
            //go over the binded vars to check if this path already exists.
            for (auto &it : varManager->getBindedVars()) {
                //two paths are the same then take the value and put it in
                // symbol table.
                if (it.second == newPath) {
                    double oldVarValue = varManager->getValueByName(it.first);
                    varManager->setValueByName(newVarName, oldVarValue);
                    break;
                }
            }
        }
        //add to the binded vars table.
        varManager->addToBindedVars(newVarName, newPath);
    }
    //return number of arguments.
    return NUM_OF_ARGS;
}
