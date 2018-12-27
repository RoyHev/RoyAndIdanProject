//
// Created by idantp on 12/19/18.
//

#include <unistd.h>
#include "SleepCommand.h"

#define MILI_TO_MICRO_SEC 1000
#define NUM_OF_ARGS 1

SleepCommand::SleepCommand(VarManager *varManager) {
    this->varManager = varManager;
}

int SleepCommand::execute(int &index, vector<string> data) {
    ShuntingYard shuntingYard(varManager);
    Expression *exp = shuntingYard.evaluateInfix(data[index + 1]);
    double seconds = exp->calculate();
    delete (exp);
    seconds *= MILI_TO_MICRO_SEC;
    //can not sleep for negative value.
    if (seconds < 0) {
        throw runtime_error("Negative Number Given To Sleep Command");
    }
    usleep(static_cast<unsigned int>(seconds));
    return NUM_OF_ARGS;
}
