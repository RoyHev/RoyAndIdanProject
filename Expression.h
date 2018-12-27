//
// Created by roy on 16/12/18.
//

#ifndef EX3_EXPRESSION_H
#define EX3_EXPRESSION_H

class Expression {
public:
    virtual double calculate() = 0;
    virtual ~Expression() = default;
};

#endif //EX3_EXPRESSION_H
