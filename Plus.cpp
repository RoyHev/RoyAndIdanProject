//
// Created by roy on 17/12/18.
//

#include "Plus.h"

Plus::Plus(Expression *left, Expression *right) : BinaryExpression(left,
                                                                   right) {

}

double Plus::calculate() {
    return this->getRightExp()->calculate() + this->getLeftExp()->calculate();
}
