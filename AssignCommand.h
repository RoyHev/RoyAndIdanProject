//
// Created by idantp on 12/19/18.
//

#ifndef EX3_ASSIGNCOMMAND_H
#define EX3_ASSIGNCOMMAND_H


#include "Command.h"
#include "VarManager.h"

class AssignCommand: public Command{
    VarManager *varManager;
public:
    AssignCommand(VarManager *varManager);
    virtual int execute(int index, vector<string> data);

};


#endif //EX3_ASSIGNCOMMAND_H
