//
// Created by idantp on 12/19/18.
//

#ifndef EX3_PRINTCOMMAND_H
#define EX3_PRINTCOMMAND_H


#include "Command.h"
#include "VarManager.h"

class PrintCommand : public Command {
    VarManager *varManager;
public:
    PrintCommand(VarManager *varManager);

    virtual int execute(int index, vector<string> data);

};


#endif //EX3_PRINTCOMMAND_H
