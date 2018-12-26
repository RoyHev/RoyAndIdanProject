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
#include <pthread.h>
#include <thread>
#include <sys/socket.h>

#include "ShuntingYard.h"
#include "VarManager.h"

class OpenDataServerCommand : public Command {
    char buffer[1024];
    VarManager* varManager;
public:
    OpenDataServerCommand(VarManager* varManager);

    static void *openSocket(void *parameters);

    virtual int execute(int &index, vector<string> data);
};


#endif //EX3_OPENDATASERVERCOMMAND_H
