//
// Created by idantp on 12/19/18.
//

#ifndef EX3_SLEEPCOMMAND_H
#define EX3_SLEEPCOMMAND_H


#include "Command.h"
#include "ShuntingYard.h"
#include "VarManager.h"

class SleepCommand: public Command{
    VarManager* varManager;
public:

    SleepCommand(VarManager* varManager);
    virtual int execute(int index, vector<string> data);

};


#endif //EX3_SLEEPCOMMAND_H
