//
// Created by roy on 17/12/18.
//

#include "Data.h"

using namespace std;

Data::Data() {

}

map<string,double> Data::getSymbolMap() {
    return symbolTable;
}

double Data::getValue(string name) {
    //could not find the variable name in symbol table.
    if (symbolTable.find(name) == symbolTable.end()){
        throw "No such Var created previously.";
    } else {
        return symbolTable.find(name)->second;
    }
}

void Data::updateValue(string name, double value) {

}

void Data::addValue(string name, double value) {

}
