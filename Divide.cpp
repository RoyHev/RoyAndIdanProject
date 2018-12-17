//
// Created by roy on 17/12/18.
//

#include "Divide.h"

double Divide::calculate() {
    if (this->getRightExp()->calculate() == 0){
        throw "Cannot divide by zero;";
    }
    return this->getLeftExp()->calculate() / this->getRightExp()->calculate();
}

Divide::Divide(Expression *left, Expression *right) : BinaryExpression(left,
                                                                       right) {

}
