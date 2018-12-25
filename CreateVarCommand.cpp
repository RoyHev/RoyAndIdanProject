//
// Created by idantp on 12/19/18.
//
#include <string>
#include <list>
#include "CreateVarCommand.h"

#define UNDER_SCORE 95
#define LOW_A 97
#define CAP_A 65
#define LOW_Z 122
#define CAP_Z 90
#define NUM_OF_ARGS 1
#define OPEN_SERVER "openDataServer"
#define IF_CONDITION "if"
#define WHILE_LOOP "while"
#define CONNECT "connect"
#define VAR "var"
#define PRINT "print"
#define SLEEP "sleep"
#define BIND "bind"

CreateVarCommand::CreateVarCommand(VarManager* varManager) {
    this->varManager = varManager;
}

int CreateVarCommand::execute(int &index, vector<string> data) {
    string name = data.at(index + 1);

    if (!(checkIfValidConvention(name) && checkIfSavedWord(name))){
        throw runtime_error("Cannot Create A Var With That Name.");
    }
    double result = 0;
    this->varManager->addToSymbolTable(name,result);
    return NUM_OF_ARGS;
}

bool CreateVarCommand::checkIfValidConvention(string name) {
    char firstDigit = name.at(0);
    if (firstDigit != UNDER_SCORE){
        if (!((firstDigit >= CAP_A && firstDigit <=CAP_Z) || (firstDigit >=
        LOW_A && firstDigit <= LOW_Z))){
            return false;
        }
    }
    for (int i = 1; i < name.length(); i++ ){
        if (name.at(i) != UNDER_SCORE){
            if (!(!(isdigit(name.at(i) - '0')) || (name.at(i) >= CAP_A && name
            .at(i) <=CAP_Z) || (name.at(i) >= LOW_A&& name.at(i) <= LOW_Z))){
                return false;
            }
        }
    }
    return true;
}

bool CreateVarCommand::checkIfSavedWord(string name) {
    list<string> savedWords = {OPEN_SERVER,IF_CONDITION,WHILE_LOOP,SLEEP,
                               CONNECT, VAR, PRINT, BIND};
    for (string word: savedWords){
        if (name == word){
            return false;
        }
    }
    return true;
}
