//
// Created by roy on 17/12/18.
//

#ifndef EX3_DATA_H
#define EX3_DATA_H

#include <map>
#include "Command.h"

using namespace std;

class Data {
    static map<string, double> symbolTable;
public:
    Data();
    static map<string,double> getSymbolMap();
    static double getValue(string name);
    static void updateValue(string name, double value);
    static void addNewVar(string name, double value);

};

#endif //EX3_DATA_H