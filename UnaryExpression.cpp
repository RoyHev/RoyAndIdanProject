//
// Created by roy on 17/12/18.
//

#include "UnaryExpression.h"

Expression *UnaryExpression::getExp() {
    return this->exp;
}

UnaryExpression::UnaryExpression(Expression *exp) {
    this->exp = exp;
}
