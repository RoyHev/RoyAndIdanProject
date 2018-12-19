//
// Created by idantp on 12/19/18.
//

#ifndef EX3_CREATEVARCOMMAND_H
#define EX3_CREATEVARCOMMAND_H


#include "Command.h"

class CreateVarCommand: public Command{
public:
    CreateVarCommand();
    virtual int execute(int index, vector<string> data);

};

#endif //EX3_CREATEVARCOMMAND_H
