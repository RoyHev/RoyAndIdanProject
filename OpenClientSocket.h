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
    int sockfd = 0;
public:
    OpenClientSocket() = default;

    int openSocket(string ip, double portNumber);

    void writeToSimulator(const char *buffer) const;

};


#endif //EX3_OPENCLIENTSOCKET_H
