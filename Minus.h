//
// Created by roy on 16/12/18.
//

#ifndef EX3_MINUS_H
#define EX3_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression {
public:
    Minus(Expression* left, Expression* right);
    virtual double calculate();

};


#endif //EX3_MINUS_H
