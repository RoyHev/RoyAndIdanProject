//
// Created by idantp on 12/19/18.
//

#ifndef EX3_BINDCOMMAND_H
#define EX3_BINDCOMMAND_H

#include "Command.h"
#include "VarManager.h"

class BindCommand : public Command{
    VarManager* varManager;
public:
    BindCommand(VarManager* varManager);
    virtual int execute(int &index, vector<string> data);
};


#endif //EX3_BINDCOMMAND_H
