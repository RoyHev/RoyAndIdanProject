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
