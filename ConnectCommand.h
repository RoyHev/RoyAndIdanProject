//
// Created by idantp on 12/19/18.
//

#ifndef EX3_CONNECTCOMMAND_H
#define EX3_CONNECTCOMMAND_H


#include "Command.h"

class ConnectCommand: public Command{
public:
    ConnectCommand();
    virtual int execute(int index, vector<string> data);

};

#endif //EX3_CONNECTCOMMAND_H
