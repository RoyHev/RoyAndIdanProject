//
// Created by roy on 17/12/18.
//

#ifndef EX3_COMMAND_H
#define EX3_COMMAND_H

#include "Command.h"
#include <vector>
#include <string>

using namespace std;

class Command {
public:
    virtual int execute(int index, vector<string> data) = 0;
};

class ConditionParser: public Command{
    //TODO should this member be protected?
protected:
     vector<Command*> commandsVector;
public:
    virtual int execute(int index, vector<string> data) = 0;

};
//TODO what to do with the member ?? how to pass it to the constructor.
class IfCommand : public ConditionParser{
public:
//    IfCommand() = default;
    virtual int execute(int index, vector<string> data);

};

class LoopCommand: public ConditionParser{
public:
    //LoopCommand() = default;
    virtual int execute(int index, vector<string> data);
};

class OpenDataServerCommand: public Command{
public:
    OpenDataServerCommand() = default;
    virtual int execute(int index, vector<string> data);
};

class CreateVarCommand: public Command{
public:
    CreateVarCommand() = default;
    virtual int execute(int index, vector<string> data);

};

class ConnectCommand: public Command{
public:
    ConnectCommand() = default;
    virtual int execute(int index, vector<string> data);

};

class AssignCommand: public Command{
public:
    AssignCommand() = default;
    virtual int execute(int index, vector<string> data);

};

class PrintCommand: public Command{
public:
    PrintCommand() = default;
    virtual int execute(int index, vector<string> data);

};

class SleepCommand: public Command{
public:
    SleepCommand() = default;
    virtual int execute(int index, vector<string> data);

};

#endif //EX3_COMMAND_H
