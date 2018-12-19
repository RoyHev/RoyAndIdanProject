//
// Created by idantp on 12/19/18.
//

#include "PrintCommand.h"
#include <map>
#include <iostream>
#include "ShuntingYard.h"

#define QUOTE 34

PrintCommand::PrintCommand() {

}

int PrintCommand::execute(int index, vector<string> data) {
    index++;
    map<string, double> symbolTable;
    //stores the output
    string str = data.at(index);
    //if the given string is a Var Expression
    if (symbolTable.find(str) != symbolTable.end()) {
        cout << symbolTable.find(str)->second<<endl;
    }
        //if its a string
    else if (str.at(0) == QUOTE) {
        string temp = "";
        for (int i = 1; i < str.length() - 1; i++) {
            temp += str.at(i);
        }
        cout << temp<<endl;
    }
        //convert the string to an Expression and print it if its a legal Expression
    else {
        ShuntingYard *sh;
        //TODO - what happens if an assumed var does not exist?
        cout << sh->evaluateInfix(str)->calculate();
    }
}
