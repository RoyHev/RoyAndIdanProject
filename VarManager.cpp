//
// Created by idantp on 12/19/18.
//

#include "VarManager.h"

VarManager::VarManager() {
    initializePaths();
}

void VarManager::addToSymbolTable(string name, double value) {
    if (symbolTable.empty()){
        this->symbolTable.insert(make_pair(name,value));
        return;
    }
    if (symbolTable.find(name) != symbolTable.end()){
    return;//    throw runtime_error ("Variable already exists with that name
    // .");
    }
    this->symbolTable.insert(make_pair(name, value));
}

void VarManager::addToBindedVars(string name, string path) {
    if (bindedVars.find(name) != bindedVars.end()){
        throw runtime_error ("Variable already exists with that name.");
    }
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
    if (this->paths.find(path) != paths.end()) {
        this->paths.find(path)->second = value;
    } else {
        throw runtime_error("Could not find in paths map.");
    }
}

//TODO check if these are all the paths available or not.
void VarManager::initializePaths() {
    this->paths.insert(pair<string,double>("/instrumentation/airspeed-indicator/indicated-speed-kt",0));
    this->paths.insert(pair<string,double>("/instrumentation/altimeter/indicated-altitude-ft",0));
    this->paths.insert(pair<string,double>("/instrumentation/altimeter/pressure-alt-ft",0));
    this->paths.insert(pair<string,double>("/instrumentation/attitude-indicator/indicated-pitch-deg",0));
    this->paths.insert(pair<string,double>("/instrumentation/attitude-indicator/indicated-roll-deg",0));
    this->paths.insert(pair<string,double>("/instrumentation/attitude-indicator/internal-pitch-deg",0));
    this->paths.insert(pair<string,double>("/instrumentation/attitude-indicator/internal-roll-deg",0));
    this->paths.insert(pair<string,double>("/instrumentation/encoder/indicated-altitude-ft",0));
    this->paths.insert(pair<string,double>("/instrumentation/encoder/pressure-alt-ft",0));
    this->paths.insert(pair<string,double>("/instrumentation/gps/indicated-altitude-ft",0));
    this->paths.insert(pair<string,double>("/instrumentation/gps/indicated-ground-speed-kt",0));
    this->paths.insert(pair<string,double>("/instrumentation/gps/indicated-vertical-speed",0));
    this->paths.insert(pair<string,double>("/instrumentation/heading-indicator/indicated-heading-deg",0));
    this->paths.insert(pair<string,double>("/instrumentation/magnetic-compass/indicated-heading-deg",0));
    this->paths.insert(pair<string,double>("/instrumentation/slip-skid-ball/indicated-slip-skid",0));
    this->paths.insert(pair<string,double>("/instrumentation/turn-indicator/indicated-turn-rate",0));
    this->paths.insert(pair<string,double>("/instrumentation/vertical-speed-indicator/indicated-speed-fpm",0));
    this->paths.insert(pair<string,double>("/controls/flight/aileron",0));
    this->paths.insert(pair<string,double>("/controls/flight/elevator",0));
    this->paths.insert(pair<string,double>("/controls/flight/rudder",0));
    this->paths.insert(pair<string,double>("/controls/flight/flaps",0));
    this->paths.insert(pair<string,double>("/controls/engines/engine/throttle",0));
    this->paths.insert(pair<string,double>("/engines/engine/rpm",0));

}

void VarManager::setPathByName(string name, string path) {
    if (this->bindedVars.find(name) != bindedVars.end()) {
        this->bindedVars.insert(make_pair(name, path));
    } else {
        throw runtime_error("Could not find in BindedVars map.");
    }

}

bool VarManager::doesExistInSymbolTable(string name) {
    if (symbolTable.find(name) == symbolTable.end()){
        return false;
    }
    return true;
}

bool VarManager::doesExistInBindedVars(string name) {
    if (bindedVars.find(name) == bindedVars.end()){
        return false;
    }
    return true;
}


