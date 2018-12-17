//
// Created by roy on 17/12/18.
//

#ifndef EX3_PARSER_H
#define EX3_PARSER_H

#include <string>
#include <vector>
#include "Data.h"
using namespace std;

class Parser {
Data mapsData;
public:
    Parser(Data mapsData);
    void parseFunc(vector<string> strings);
};


#endif //EX3_PARSER_H
