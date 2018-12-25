//
// Created by idantp on 12/19/18.
//

#ifndef EX3_CREATEVARCOMMAND_H
#define EX3_CREATEVARCOMMAND_H


#include "Command.h"
#include "VarManager.h"

class CreateVarCommand: public Command{
    VarManager* varManager;
public:
    CreateVarCommand(VarManager* varManager);
    virtual int execute(int &index, vector<string> data);
private:
    bool checkIfValidConvention(string name);
    bool checkIfSavedWord(string name);
};

#endif //EX3_CREATEVARCOMMAND_H
