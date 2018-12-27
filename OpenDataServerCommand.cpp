//
// Created by idantp on 12/19/18.
//
#include <iostream>
#include "Command.h"
#include "OpenDataServerCommand.h"

#define NUM_OF_ARGS 2

OpenDataServerCommand::OpenDataServerCommand(VarManager *varManager) {
    this->varManager = varManager;
}

struct MyParameters {
    int portNumber;
    int hz;
    int sockfd;
    VarManager *varManager;
};

void *OpenDataServerCommand::openSocket(void *parameters) {
    struct MyParameters *myParameters = (struct MyParameters *) parameters;
    myParameters->varManager->incCount();
    char c = '\0';
    int n;
    string buffer = "";
    int size = 0;
    /* First call to socket() function */

    while (myParameters->varManager->shouldContinue()) {
        /* If connection is established then start communicating */
        n = read(myParameters->sockfd, &c, 1);
        while (c != '\n') {
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }
            size++;
            buffer += c;
            n = read(myParameters->sockfd, &c, 1);
        }
        size++;
        buffer += '\n';

        myParameters->varManager->updateXMLVars(buffer.c_str(), size);
        buffer = "";
    }

    close(myParameters->sockfd);
    if (myParameters->varManager->decCount() == 0)  {
        delete myParameters->varManager;
    }
    delete myParameters;
}

int OpenDataServerCommand::execute(int &index, vector<string> data) {
    pthread_t threadID;
    struct MyParameters* parameters = new MyParameters();
    ShuntingYard shuntingYard(varManager);
    Expression *exp = shuntingYard.evaluateInfix(data[index + 1]);
    double portNum = exp->calculate();
    delete exp;
    exp = shuntingYard.evaluateInfix(data[index + 2]);
    double hertz = exp->calculate();
    delete (exp);
    parameters->varManager = this->varManager;
    parameters->portNumber = portNum;
    parameters->hz = hertz;
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    portno = parameters->portNumber;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
    parameters->sockfd = newsockfd;
    this->varManager->addSockfd(newsockfd);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    pthread_create(&threadID, nullptr, openSocket, parameters);
    return NUM_OF_ARGS;
}
