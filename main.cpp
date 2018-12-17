#include <vector>
#include <fstream>
#include <iostream>

#include "Expression.h"
#include "Plus.h"
#include "Multiply.h"
#include "Number.h"
#include "Divide.h"
#include "Minus.h"
#include "Negative.h"

using namespace std;

int main(int argc, char *argv[]) {

    UnaryExpression* e = new Negative(new Minus(new Divide(new Number(3),new
    Number(4)),
            new Number(5)));
    cout << e->calculate();

    return 0;
}