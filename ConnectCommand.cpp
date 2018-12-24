//
// Created by idantp on 12/19/18.
//

#include "ConnectCommand.h"

int ConnectCommand::execute(int index, vector<string> data) {
    return 0;
}

ConnectCommand::ConnectCommand(OpenClientSocket *openClientSocket) {
    this->openClientSocket = openClientSocket;
}