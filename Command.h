//
// Created by roy on 17/12/18.
//

#ifndef EX3_COMMAND_H
#define EX3_COMMAND_H

#include "Command.h"
#include <vector>
using namespace std;

class Command {
public:
    int execute(int index, vector<string> data) = 0;
};

#endif //EX3_COMMAND_H
