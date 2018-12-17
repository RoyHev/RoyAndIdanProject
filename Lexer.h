//
// Created by roy on 16/12/18.
//

#ifndef EX3_LEXER_H
#define EX3_LEXER_H

#include <vector>
#include <string>

using namespace std;

class Lexer {

public:
    vector<string> lexerFromFile (const string &textFile);
    vector<string> lexerFromCommand(int argc, char*argv[]);
    vector<string> lexer(int argc, char* argv[]);
};


#endif //EX3_LEXER_H
