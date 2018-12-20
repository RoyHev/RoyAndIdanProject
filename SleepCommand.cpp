//
// Created by idantp on 12/19/18.
//

#include <unistd.h>
#include "SleepCommand.h"

#define MILI_TO_MICRO_SEC 1000
#define NUM_OF_ARGS 1

SleepCommand::SleepCommand(VarManager* varManager) {
    this->varManager = varManager;
}

int SleepCommand::execute(int index, vector<string> data) {
    ShuntingYard* shuntingYard = new ShuntingYard(varManager);
    double seconds = shuntingYard->evaluateInfix(data[index + 1])->calculate();
    seconds*=MILI_TO_MICRO_SEC;
    if (seconds < 0){
        throw runtime_error("Negative Number Given To Sleep Command");
    }
    usleep(seconds);
    return NUM_OF_ARGS;
}
