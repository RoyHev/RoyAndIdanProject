//
// Created by idantp on 12/24/18.
//

#ifndef EX3_OPENCLIENTSOCKET_H
#define EX3_OPENCLIENTSOCKET_H

#include "VarManager.h"
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

using namespace std;

class OpenClientSocket {
    struct sockaddr_in server;
    int sockfd;
public:
    OpenClientSocket();

    void *openSocket(void *param);
private:
    void writeToSimulator(char *buffer);
};


#endif //EX3_OPENCLIENTSOCKET_H
