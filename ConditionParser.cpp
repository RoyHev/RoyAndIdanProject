//
// Created by idantp on 12/20/18.
//

#include "ConditionParser.h"
#include "Parser.h"

ConditionParser::ConditionParser(VarManager *varManager) {
    this->varManager = varManager;
    Parser* parser=new Parser();

}
int ConditionParser::execute(int index, vector<string> data) {
 //   ShuntingYard *sh = new
   // double operand1 = data.at(index + 1);
   // double operand2 =
}

