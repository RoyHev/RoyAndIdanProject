//
// Created by roy on 16/12/18.
//

#ifndef EX3_BINARYEXPRESSION_H
#define EX3_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {
    Expression *leftExp;
    Expression *rightExp;
public:
    BinaryExpression(Expression *left, Expression *right);

    virtual double calculate() = 0;

    ~BinaryExpression() {
        delete this->rightExp;
        delete this->leftExp;
    }

    Expression *getLeftExp() { return this->leftExp; }

    Expression *getRightExp() { return this->rightExp; }
};


#endif //EX3_BINARYEXPRESSION_H
