//
// Created by roy on 17/12/18.
//

#include "Negative.h"

Negative::Negative(Expression *exp) : UnaryExpression(exp) {

}

double Negative::calculate() {
    return (-1)*this->getExp()->calculate();
}
