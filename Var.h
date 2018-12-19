//
// Created by roy on 19/12/18.
//

#ifndef EX3_VAR_H
#define EX3_VAR_H

#include "Expression.h"
#include <string>

using namespace std;

class Var : public Expression {
private:
    string varName;
public:
    Var (string varName);
    string getName() const;
    virtual double calculate();
};


#endif //EX3_VAR_H
