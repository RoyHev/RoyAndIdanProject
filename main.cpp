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
#include "ShuntingYard.h"
#include "Lexer.h"

using namespace std;

int main(int argc, char *argv[]) {
    Lexer* lexer = new Lexer();
    vector<string> v = lexer->lexerFromFile("txt.txt");
    vector<string> v1 = lexer->elementsMerge(v);
    for (string s : v1){
        cout << s << endl;
    }

//    ShuntingYard* x = new ShuntingYard;
//    Expression *e = x->evaluateInfix("40 - 8 * 2");
//    double l = e->calculate();
//    cout << l << endl;

//    UnaryExpression* e = new Negative(new Minus(new Divide(new Number(3),new
//    Number(4)),
//            new Number(5)));
//    cout << e->calculate();

    return 0;
}