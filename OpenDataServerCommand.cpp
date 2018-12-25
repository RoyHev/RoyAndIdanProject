//
// Created by idantp on 12/19/18.
//
#include "Command.h"
#include "OpenDataServerCommand.h"

#define NUM_OF_ARGS 2
#define SIZE_BUFFER 1024

OpenDataServerCommand::OpenDataServerCommand(VarManager *varManager) {
    this->varManager = varManager;
}

struct MyParameters {
    int portNumber;
    int hz;
    VarManager *varManager;
};

static void *openSocket(void *parameters) {
    struct MyParameters *myParameters = (struct MyParameters *) parameters;
    int sockfd, newsockfd, portno, clilen;
    char buffer[SIZE_BUFFER];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    portno = myParameters->portNumber;

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

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    while (true) {
        /* If connection is established then start communicating */
        bzero(buffer, SIZE_BUFFER);
        n = read(newsockfd, buffer, SIZE_BUFFER);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        printf("Here is the message: %s\n", buffer);
        //TODO DELET
        printf("XY: %lf\n", myParameters->varManager->getValueByName("xy"));
//        printf("CHECK %lf\n",myParameters->varManager->getPaths().find("/instrumentation/altimeter/pressure-alt-ft")
//        ->second);
        myParameters->varManager->updateXMLVars(buffer);
    }
}

int OpenDataServerCommand::execute(int &index, vector<string> data) {
    pthread_t threadID;
    struct MyParameters *parameters = new MyParameters();
    ShuntingYard *shuntingYard = new ShuntingYard(varManager);
    double portNum = shuntingYard->evaluateInfix(data[index + 1])->calculate();
    double hertz = shuntingYard->evaluateInfix(data[index + 2])->calculate();
    parameters->varManager = this->varManager;
    parameters->portNumber = portNum;
    parameters->hz = hertz;
    pthread_create(&threadID, nullptr, openSocket, parameters);
    return NUM_OF_ARGS;
}
