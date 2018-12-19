//
// Created by idantp on 12/19/18.
//

#ifndef EX3_VARMANAGER_H
#define EX3_VARMANAGER_H

#include <map>
#include <string>

using namespace std;

class VarManager {
    map<string, double> symbolTable;
    map<string, string> bindedVars;
    // TODO - from xml
    map<string, double> paths;
public:
    VarManager();

    void addToSymbolTable(string name, double value);

    void addToBindedVars(string name, string path);

    double getValueByName(string name);

    string getPathByName(string name);

    double getValueByPath(string path);

    void setValueByName(string name, double value);

    void setValueByPath(string path, double value);

private:
    void initializePaths();
};


#endif //EX3_VARMANAGER_H
