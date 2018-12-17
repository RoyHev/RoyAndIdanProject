//
// Created by roy on 17/12/18.
//

#ifndef EX3_MULTIPLY_H
#define EX3_MULTIPLY_H


#include "BinaryExpression.h"

class Multiply : public BinaryExpression{
public:
    Multiply(Expression* left, Expression* right);
    virtual double calculate();

};


#endif //EX3_MULTIPLY_H
