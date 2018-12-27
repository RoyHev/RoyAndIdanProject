//
// Created by idantp on 12/19/18.
//

#ifndef EX3_ASSIGNCOMMAND_H
#define EX3_ASSIGNCOMMAND_H


#include "Command.h"
#include "VarManager.h"
#include "OpenClientSocket.h"

class AssignCommand : public Command {
    VarManager *varManager;
    OpenClientSocket &openClientSocket;
public:
    AssignCommand(VarManager *varManager, OpenClientSocket *openClientSocket);

    virtual int execute(int &index, vector<string> data);
};


#endif //EX3_ASSIGNCOMMAND_H
