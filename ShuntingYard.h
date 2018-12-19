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

using namespace std;

class ShuntingYard {
private:
    int operationPriority(char operation);
    Expression *applyOperation(Expression *left, Expression *right, char operation);
    bool isItAnOperator(const char& op);

public:
    ShuntingYard() = default;
    Expression *evaluateInfix(string expression);
};

#endif //EX3_SHUNTINGYARD_H
