//
// Created by roy on 17/12/18.
//

#include "Multiply.h"

double Multiply::calculate() {
    return this->getRightExp()->calculate() * this->getLeftExp()->calculate();
}

Multiply::Multiply(Expression *left, Expression *right) : BinaryExpression
                    (left,right) {
}
