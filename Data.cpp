//
// Created by roy on 17/12/18.
//

#include "Data.h"

using namespace std;

//TODO - why isn't it working.
Data::Data() {

}

map<string,double> Data::getSymbolMap() {
    return Data::symbolTable;
}

double Data::getValue(string name) {
    //could not find the variable name in symbol table.
    if (Data::symbolTable.find(name) == Data::symbolTable.end()){
        throw "No such Var created previously.";
    } else {
        return Data::symbolTable.find(name)->second;
    }
}

void Data::updateValue(string name, double value) {

}

void Data::addNewVar(string name, double value) {

}
