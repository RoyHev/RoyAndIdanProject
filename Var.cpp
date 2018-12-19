//
// Created by roy on 19/12/18.
//

#include "Var.h"

Var::Var(string varName) {
    this->varName = varName;

}

string Var::getName() const {
    return this->varName;
}

//TODO - return it from the symbol table.
double Var::calculate() {
    return 0;
}
