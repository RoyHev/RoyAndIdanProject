//
// Created by idantp on 12/19/18.
//

#include "PrintCommand.h"
#include <map>
#include <iostream>
#include "ShuntingYard.h"

#define QUOTE 34
#define NUM_OF_ARG 1

PrintCommand::PrintCommand(VarManager *varManager) {
    this->varManager = varManager;
}

int PrintCommand::execute(int &index, vector<string> data) {
    //stores the output
    string str = data.at(index+1);
    //if its a string print it without the quotes
    if (str.at(0) == QUOTE) {
        string temp = "";
        for (int i = 1; i < str.length() - 1; i++) {
            temp += str.at(i);
        }
        cout << temp << endl;
    }
        //convert the string to an Expression and print it if its a legal Expression
    else {
        ShuntingYard *sh = new ShuntingYard(varManager);
        cout << sh->evaluateInfix(str)->calculate() << endl;
    }
    return NUM_OF_ARG;
}
