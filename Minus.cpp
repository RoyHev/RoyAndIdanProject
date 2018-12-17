//
// Created by roy on 16/12/18.
//

#include "Minus.h"

double Minus::calculate() {
    return this->getLeftExp()->calculate() - this->getRightExp()->calculate();
}

Minus::Minus(Expression *left, Expression *right) : BinaryExpression(left,
                                                                     right) {

}
