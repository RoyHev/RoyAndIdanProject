//
// Created by idantp on 12/17/18.
//

#ifndef EX3_SHUNTINGYARD_H
#define EX3_SHUNTINGYARD_H

#include "Expression.h"
#include "Plus.h"
#include "Multiply.h"
#include "Number.h"
#include "Divide.h"
#include "Minus.h"
#include "Negative.h"
#include "Var.h"
#include <string>
#include "VarManager.h"

using namespace std;

class ShuntingYard {
    VarManager *varManager;
private:
    int operationPriority(char operation);

    Expression *applyOperation(Expression *left, Expression *right, char
    operation);

public:
    ShuntingYard(VarManager *varManager);

    Expression *evaluateInfix(string expression);
};

#endif //EX3_SHUNTINGYARD_H
