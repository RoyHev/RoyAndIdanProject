//
// Created by idantp on 12/19/18.
//

#ifndef EX3_VARMANAGER_H
#define EX3_VARMANAGER_H

#include <map>
#include <string>
#include <vector>

using namespace std;

class VarManager {
    map<string, double> symbolTable;
    map<string, string> bindedVars;
    vector<string> pathsFromXML;
    // TODO - from xml
    map<string, double> paths;
public:
    VarManager();

    void updateXMLVars(char buffer[]);

    void addToSymbolTable(string name, double value);

    void addToBindedVars(string name, string path);

    double getValueByName(string name);

    string getPathByName(string name);

    double getValueByPath(string path);

    void setValueByName(string name, double value);

    void setValueByPath(string path, double value);

    void setPathByName(string name, string path);

    bool doesExistInSymbolTable(string name);

    bool doesExistInBindedVars(string name);

private:
    void initializeXMLVector();

    void initializePaths();
};


#endif //EX3_VARMANAGER_H
