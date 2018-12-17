//
// Created by roy on 17/12/18.
//

#include "Data.h"

using namespace std;

Data::Data() {

}

Command Data::getCommand(string commandName) {
    return commandsMap.find(commandName)->second;
}

bool Data::doesCommandExist(string commandName) {
    if (this->commandsMap.find(commandName) != commandsMap.end()) {
        return true;
    }
    return false;
}

void Data::addToSymbolTable(string name, double value) {
    symbolTable.insert(make_pair(name,value));
}

map<string, double> Data::getSymbolTable() {
    return symbolTable;
}

map<string, Command> Data::getCommandsMap() {
    return commandsMap;
}
