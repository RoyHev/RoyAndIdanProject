//
// Created by idantp on 12/19/18.
//

#ifndef EX3_OPENDATASERVERCOMMAND_H
#define EX3_OPENDATASERVERCOMMAND_H

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

#include <sys/socket.h>

class OpenDataServerCommand : public Command {
public:
    OpenDataServerCommand();

    virtual int execute(int index, vector<string> data);
};


#endif //EX3_OPENDATASERVERCOMMAND_H
