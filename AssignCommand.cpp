//
// Created by idantp on 12/19/18.
//

#include "AssignCommand.h"
#include "ShuntingYard.h"
#define NUM_OF_ARG 1


AssignCommand::AssignCommand(VarManager *varManager) {
    this->varManager = varManager;
}

int AssignCommand::execute(int index, vector<string> data) {
    //TODO to update in the server
    ShuntingYard *sh = new ShuntingYard(varManager);
    string resultStr = data.at(index + 1);
    double result = sh->evaluateInfix(resultStr)->calculate();
    string varName = data.at(index - 1);
    //update symbolTable map.
    this->varManager->setValueByName(varName, result);
    //update paths map
//    string pathName = varManager->getPathByName(varName);
//    this->varManager->setValueByPath(pathName, result);
    //TODO is it true?
    return NUM_OF_ARG;
}
