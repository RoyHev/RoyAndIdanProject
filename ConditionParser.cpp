//
// Created by idantp on 12/20/18.
//

#include <strings.h>
#include "ConditionParser.h"
#include "BindCommand.h"

ConditionParser::ConditionParser(VarManager *varManager) {
    this->varManager = varManager;
    this->parser = new Parser();
}
