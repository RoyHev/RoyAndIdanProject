//
// Created by idantp on 12/19/18.
//

#ifndef EX3_OPENDATASERVERCOMMAND_H
#define EX3_OPENDATASERVERCOMMAND_H

class OpenDataServerCommand : public Command {
public:
    OpenDataServerCommand();

    virtual int execute(int index, vector<string> data);
};


#endif //EX3_OPENDATASERVERCOMMAND_H
