//
// Created by idantp on 12/17/18.
//
#define SPACE 32
#define OPEN_BRACKET '('
#define CLOSE_BRACKET ')'

#include <bits/stdc++.h>

#include "ShuntingYard.h"
#include <bits/stdc++.h>

using namespace std;

int ShuntingYard::operationPriority(char operation) {
    if (operation == '*' || operation == '/') {
        return 1;
    } else if (operation == '+' || operation == '-') {
        return 2;
    } else return -1;
}

Expression *ShuntingYard::applyOperation(Expression *left, Expression *right, char operation) {
    switch (operation) {
        case '*':
            return new Multiply(left, right);
            break;
        case '/':
            return new Divide(left, right);
            break;
        case '+':
            return new Plus(left, right);
            break;
        case '-':
        default:
            return new Minus(left, right);
            break;
    }
}

Expression *ShuntingYard::evaluateInfix(string expression) {
    //contains all the operation
    stack<char> operations;
    stack<Expression *> values;
    for (int index = 0; index < expression.length(); index++) {
        if (expression.at(index) == SPACE) {
            continue;
        } else if (expression.at(index) == OPEN_BRACKET) {
            operations.push(expression.at(index));
        } else if (expression.at(index) == isdigit(expression.at(index))) {
            double temp = 0;
            //
            while (index < expression.length() && isdigit(expression.at(index))) {
                temp *= 10;
                temp += (expression.at(index) - '0');
                index++;
            }
            values.push(new Number(temp));
        } else if (expression.at(index) == CLOSE_BRACKET) {
            while (operations.top() != OPEN_BRACKET && !(operations.empty())) {
                Expression *val2 = values.top();
                values.pop();
                Expression *val = values.top();
                values.pop();
                char operation = operations.top();
                operations.pop();
                values.push(applyOperation(val, val2, operation));
            }
            operations.pop();
        } else {
            while (!operations.empty() &&
                   (operationPriority(expression.at(index)) >= operationPriority(operations.top()))) {
                Expression *val2 = values.top();
                values.pop();
                Expression *val = values.top();
                values.pop();
                char operation = operations.top();
                operations.pop();
                values.push(applyOperation(val, val2, operation));
            }
            operations.push(expression.at(index));
        }
    }
    while (!operations.empty()) {
        Expression *val2 = values.top();
        values.pop();
        Expression *val = values.top();
        values.pop();
        char operation = operations.top();
        operations.pop();
        values.push(applyOperation(val, val2, operation));
    }
    return values.top();
}

