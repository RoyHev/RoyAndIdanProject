//
// Created by roy on 19/12/18.
//

#ifndef EX3_IFCOMMAND_H
#define EX3_IFCOMMAND_H

#include "ConditionParser.h"

class IfCommand : public ConditionParser {
    VarManager *varManager;
    map<string,Expression*> *commandsMap;
public:
    IfCommand(VarManager *varManager, map<string,Expression*> *commandsMap);

    virtual int execute(int &index, vector<string> data);
};


#endif //EX3_IFCOMMAND_H
