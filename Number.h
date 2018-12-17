//
// Created by roy on 17/12/18.
//

#ifndef EX3_NUMBER_H
#define EX3_NUMBER_H


#include "Expression.h"

class Number : public Expression {
    double num;
public:
    Number(double num);
    virtual double calculate();

};


#endif //EX3_NUMBER_H
