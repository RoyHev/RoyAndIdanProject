//
// Created by roy on 16/12/18.
//

#ifndef EX3_LEXER_H
#define EX3_LEXER_H

#include <vector>
#include <string>

using namespace std;

class Lexer {

    bool isIP(const string &s) const;
public:
    vector<string> lexerFromFile (const string &textFile);
    vector<string> elementsMerge (vector<string> initialVector);
};


#endif //EX3_LEXER_H
