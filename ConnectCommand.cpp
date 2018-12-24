//
// Created by idantp on 12/19/18.
//

#include "ConnectCommand.h"
#include "ShuntingYard.h"
#include <pthread.h>
#include <thread>

#define NUM_OF_ARGS 2

struct MyParameters {
    string ip;
    int portNum;
    OpenClientSocket* openClientSocket;
};

ConnectCommand::ConnectCommand(OpenClientSocket *openClientSocket, VarManager* varManager) {
    this->openClientSocket = openClientSocket;
    this->varManager = varManager;
}

int ConnectCommand::execute(int index, vector<string> data) {
    ShuntingYard* shuntingYard = new ShuntingYard(varManager);
    string ip = data.at(index+1);
    double portNum = shuntingYard->evaluateInfix(data.at(index+2))->calculate();
    MyParameters *myParameters = new MyParameters();
    myParameters->portNum = (int)portNum;
    myParameters->ip = ip;
    pthread_t pthreadID;
    pthread_create(&pthreadID, nullptr, openNewClientSocket, (void*) myParameters);

    return NUM_OF_ARGS;
}

void *ConnectCommand::openNewClientSocket(void *args) {
    struct MyParameters *parameters;
    parameters = (struct MyParameters*) args;
    parameters->openClientSocket->openSocket(parameters->ip, parameters->portNum);
}
