//
// Created by idantp on 12/19/18.
//

#include "Command.h"

#ifndef EX3_OPENDATASERVER_H
#define EX3_OPENDATASERVER_H

#endif //EX3_OPENDATASERVER_H

class OpenDataServerCommand: public Command{
public:
    OpenDataServerCommand();
    virtual int execute(int index, vector<string> data);
};