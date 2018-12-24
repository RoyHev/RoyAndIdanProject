//
// Created by idantp on 12/19/18.
//

#ifndef EX3_CONNECTCOMMAND_H
#define EX3_CONNECTCOMMAND_H


#include "Command.h"
#include "OpenClientSocket.h"

class ConnectCommand: public Command{
    OpenClientSocket *openClientSocket;
public:
    ConnectCommand(OpenClientSocket* openClientSocket);
    virtual int execute(int index, vector<string> data);

};

#endif //EX3_CONNECTCOMMAND_H
