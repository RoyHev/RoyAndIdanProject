//
// Created by roy on 19/12/18.
//

#ifndef EX3_IFCOMMAND_H
#define EX3_IFCOMMAND_H


#include "ConditionParser.h"

class IfCommand : public ConditionParser{
public:
//    IfCommand() = default;
    virtual int execute(int index, vector<string> data);

    IfCommand();

};


#endif //EX3_IFCOMMAND_H
