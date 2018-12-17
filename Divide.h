//
// Created by roy on 17/12/18.
//

#ifndef EX3_DIVIDE_H
#define EX3_DIVIDE_H


#include "BinaryExpression.h"

class Divide : public BinaryExpression {
public:
    Divide(Expression* left, Expression* right);
    virtual double calculate();

};


#endif //EX3_DIVIDE_H
