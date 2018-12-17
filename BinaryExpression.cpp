//
// Created by roy on 16/12/18.
//

#include "BinaryExpression.h"

/**
 * Constructor.
 * @param left - left expression.
 * @param right - right expression.
 */
BinaryExpression::BinaryExpression(Expression* left, Expression* right) {
    this->leftExp = left;
    this->rightExp = right;
}
