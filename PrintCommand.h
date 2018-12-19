//
// Created by idantp on 12/19/18.
//

#ifndef EX3_PRINTCOMMAND_H
#define EX3_PRINTCOMMAND_H


#include "Command.h"

class PrintCommand: public Command{
public:
    PrintCommand() = default;
    virtual int execute(int index, vector<string> data);

};


#endif //EX3_PRINTCOMMAND_H
