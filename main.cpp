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
#include "CommandExpression.h"
using namespace std;


int main(int argc, char *argv[]) {

    /*Lexer* lexer = new Lexer();
   vector<string> v = lexer->lexerFromFile("txt.txt");
   vector<string> v1 = lexer->elementsMerge(v);
   for (string s : v1){
       cout << s << endl;
   }*/

    ShuntingYard* sh= new ShuntingYard();
    Expression* e = sh->evaluateInfix("5-+3");
    cout << e->calculate();
    return 0;
}