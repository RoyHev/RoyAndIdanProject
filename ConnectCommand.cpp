//
// Created by idantp on 12/19/18.
//

#include "ConnectCommand.h"
#include "ShuntingYard.h"
#include <pthread.h>
#include <thread>
#include <iostream>

#define NUM_OF_ARGS 2

void *openNewClientSocket(void *args);

struct MyParameters {
    string ip;
    double portNum;
    int socketfd;
    OpenClientSocket &openClientSocket;
    MyParameters(OpenClientSocket &openClientSocket):openClientSocket(openClientSocket){

    }
};

ConnectCommand::ConnectCommand(OpenClientSocket &openClientSocket, VarManager *varManager) : openClientSocket
(openClientSocket) {
//    this->openClientSocket = openClientSocket;
    this->varManager = varManager;
}

int ConnectCommand::execute(int &index, vector<string> data) {
    ShuntingYard *shuntingYard = new ShuntingYard(varManager);
    string ip = data.at(index + 1);
    double port = shuntingYard->evaluateInfix(data.at(index + 2))->calculate();
    struct MyParameters *myParameters = new MyParameters(this->openClientSocket);
    myParameters->portNum = port;
    myParameters->ip = ip;
    myParameters-> socketfd = myParameters->openClientSocket.openSocket(myParameters->ip, myParameters->portNum);
    pthread_t pthreadID;
    pthread_create(&pthreadID, nullptr, openNewClientSocket, (void *) myParameters);
    return NUM_OF_ARGS;
}

void *openNewClientSocket(void *args) {
    struct MyParameters *parameters;
    parameters = (struct MyParameters *) args;
//    parameters->openClientSocket->openSocket(parameters->ip, parameters->portNum);
}
