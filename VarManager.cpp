//
// Created by idantp on 12/19/18.
//

#include "VarManager.h"

VarManager::VarManager() {
    initializePaths();
}

void VarManager::addToSymbolTable(string name, double value) {
    this->symbolTable.insert(make_pair(name, value));
}

void VarManager::addToBindedVars(string name, string path) {
    this->bindedVars.insert(make_pair(name, path));
}

double VarManager::getValueByName(string name) {
    if (this->symbolTable.find(name) != symbolTable.end()) {
        return this->symbolTable.find(name)->second;
    }
    throw runtime_error("Could not find in SymbolTable");
}

double VarManager::getValueByPath(string path) {
    if (this->paths.find(path) != paths.end()) {
        return this->paths.find(path)->second;
    }
    throw runtime_error("Could not find in Paths map");
}

string VarManager::getPathByName(string name) {
    if (this->bindedVars.find(name) != bindedVars.end()) {
        return this->bindedVars.find(name)->second;
    }
    throw runtime_error("Could not find in BindedVars map.");
}

void VarManager::setValueByName(string name, double value) {
    if (this->symbolTable.find(name) != symbolTable.end()) {
        this->symbolTable.find(name)->second = value;
    } else {
        throw runtime_error("Could not find in SymbolTable");
    }
}

void VarManager::setValueByPath(string path, double value) {
    if (this->bindedVars.find(path) != bindedVars.end()) {
        this->bindedVars.find(path)->second = value;
    } else {
        throw runtime_error("Could not find in BindedVars map.");
    }
}

//TODO ***
void VarManager::initializePaths() {

}


