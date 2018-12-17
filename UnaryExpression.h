//
// Created by roy on 17/12/18.
//

#ifndef EX3_UNARYEXPRESSION_H
#define EX3_UNARYEXPRESSION_H


#include "Expression.h"

class UnaryExpression : public Expression {
    Expression* exp;
public:
    UnaryExpression(Expression* exp);
    virtual double calculate() = 0;
    Expression* getExp();

};


#endif //EX3_UNARYEXPRESSION_H
