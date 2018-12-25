//
// Created by idantp on 12/24/18.
//

#include "OpenClientSocket.h"


struct MyParameters {
    string ip;
    int portNum;
    VarManager *varManager;
};


OpenClientSocket::OpenClientSocket() {
    this->sockfd = 0;

}

void OpenClientSocket::openSocket(string ip, double portNumber) {
    int portno;
    char buffer[1024];
    struct sockaddr_in serv_addr;
    struct hostent *server;
    portno = portNumber;
    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(ip.c_str());

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
}

void OpenClientSocket::writeToSimulator(const char *buffer) {
    int n;

    /* Send message to the server */
    n = ::write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}

int OpenClientSocket::getSockfd() const {
    return sockfd;
}
