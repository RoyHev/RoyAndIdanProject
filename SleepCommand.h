//
// Created by idantp on 12/19/18.
//

#ifndef EX3_SLEEPCOMMAND_H
#define EX3_SLEEPCOMMAND_H


#include "Command.h"

class SleepCommand: public Command{
public:
    SleepCommand();
    virtual int execute(int index, vector<string> data);

};


#endif //EX3_SLEEPCOMMAND_H
