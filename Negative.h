//
// Created by roy on 17/12/18.
//

#ifndef EX3_NEGATIVE_H
#define EX3_NEGATIVE_H


#include "UnaryExpression.h"

class Negative : public UnaryExpression {
public:
    Negative(Expression* exp);
    virtual double calculate();

};


#endif //EX3_NEGATIVE_H
