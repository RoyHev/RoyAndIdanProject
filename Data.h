//
// Created by roy on 17/12/18.
//

#ifndef EX3_DATA_H
#define EX3_DATA_H

#include <map>
#include "Command.h"

using namespace std;

class Data {
    map<string, Command> commandsMap;
    map<string, double> symbolTable;
public:
    Data();
    map<string, Command> getCommandsMap;
    map<string, double> getSymbolTable;

    void addToSymbolTable(string name, double value);

};

#endif //EX3_DATA_H