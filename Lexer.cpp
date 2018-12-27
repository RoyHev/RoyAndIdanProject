//
// Created by roy on 16/12/18.
//

#include <iostream>
#include <fstream>
#include "Lexer.h"
#include <algorithm>

#define TAB 9
#define SPACE 32
#define ENTER 10
#define PLUS_SIGN 43
#define MINUS_SIGN 45
#define MULT_SIGN 42
#define COMMA ','
#define DIVISION_SIGN 47
#define EXCLAIM '!'
#define LESS_THAN '<'
#define GREATER_THAN '>'
#define EQUAL '='
#define QUOTE 34
#define OPEN_BRACKET 40
#define CLOSE_BRACKET 41
#define OPEN_SWIRLY_B 123
#define CLOSE_SWIRLY_B 125
#define DOT 46
#define IP_DOTS 3
#define CAPITAL_A 'A'
#define CAPITAL_Z 'Z'
#define LOW_A_LETTER 'a'
#define LOW_Z_LETTER 'z'
#define OPEN_DATA_SERVER "openDataServer"
#define CONNECT_COMMAND "connect"
#define VAR_COMMAND "var"
#define PRINT_COMMAND "print"
#define SLEEP_COMMAND "sleep"
#define BIND_COMMAND "bind"
#define WHILE_COMMAND "while"
#define LESS_OPERATOR "<"
#define GREATER_OPERATOR ">"
#define LESS_EQUAL_OPERATOR "<="
#define GREATER_EQUAL_OPERATOR ">="
#define EQUAL_OPERATOR "="
#define IS_EQUAL_OPERATOR "=="
#define UNEQUAL_OPERATOR "!="
#define DOT_CHAR '.'
#define PLUS_OPERATOR "+"
#define MINUS_OPERATOR "-"
#define MULT_OPERATOR "*"
#define DIV_OPERATOR "/"
#define COMMA_STR ","

using namespace std;


vector<string> Lexer::lexerFromFile(const string &textFile) {
    vector<string> lexer;
    ifstream inputStream;
    inputStream.open(textFile);
    //couldn't open file.
    if (!(inputStream.is_open())) {
        throw "Cannot open file to lexer.";
    }
    //read all the lines in the file.
    for (string str; getline(inputStream, str);) {
        str += ENTER;
        string temp = "";
        //go over the line and put each word in a different place.
        for (int i = 0; i < str.length(); i++) {
            if ((str[i] >= CAPITAL_A && str[i] <= CAPITAL_Z) || (str[i] >= LOW_A_LETTER &&
                                                                 str[i] <= LOW_Z_LETTER) || isdigit(str[i]) ||
                (str[i] == DOT)) {
                temp += str[i];
                continue;
            } else {
                //whitespace found, new word.
                if (str[i] == ENTER || str[i] == TAB || str[i] == SPACE) {
                    if (!temp.empty()) {
                        lexer.push_back(temp);
                    }
                    temp = "";
                    continue;
                }
                //
                if (str[i] == PLUS_SIGN || str[i] == MINUS_SIGN || str[i]
                                                                   == MULT_SIGN || str[i] == DIVISION_SIGN ||
                    str[i] == COMMA ||
                    str[i] == OPEN_SWIRLY_B || str[i] == CLOSE_SWIRLY_B) {
                    if (!temp.empty()) {
                        lexer.push_back(temp);
                        temp = "";
                    }
                    string sign = "";
                    sign += str[i];
                    lexer.push_back(sign);
                    continue;
                }
                if (str[i] == GREATER_THAN || str[i] == LESS_THAN || str[i] ==
                                                                     EQUAL || str[i] == EXCLAIM) {
                    if (!temp.empty()) {
                        lexer.push_back(temp);
                        temp = "";
                    }
                    temp += str[i];
                    if (str[i + 1] == EQUAL) {
                        temp += str[i + 1];
                        i++;
                    }
                    lexer.push_back(temp);
                    temp = "";
                    continue;
                }
                if (str[i] == OPEN_BRACKET) {
                    char needed = CLOSE_BRACKET;
                    int counter = 1;
                    i++;
                    if (!temp.empty()) {
                        lexer.push_back(temp);
                        temp = "";
                    }
                    temp += OPEN_BRACKET;
                    while (counter != 0) {
                        if (str[i] == ENTER && counter != 0) {
                            throw "Invalid Syntax - Missing Parentheses";
                        }
                        temp += str[i];
                        if (str[i] == OPEN_BRACKET) {
                            counter++;
                        } else if (str[i] == CLOSE_BRACKET) {
                            counter--;
                            if (counter == 0) {
                                lexer.push_back(temp);
                                temp = "";
                                continue;
                            }
                        }
                        i++;
                    }
                }
                if (str[i] == QUOTE) {
                    if (!temp.empty()) {
                        lexer.push_back(temp);
                        temp = "";
                    }
                    temp += str[i];
                    i++;
                    while (str[i] != QUOTE) {
                        if (str[i] == ENTER) {
                            throw "Syntax Error - Missing Quotation Mark";
                        }
                        temp += str[i];
                        i++;
                    }
                    temp += QUOTE;
                    lexer.push_back(temp);
                    temp = "";
                    continue;
                }
            }
        }
    }
    return elementsMerge(lexer);
}

vector<string> Lexer::elementsMerge(vector<string> initialVector) {
    vector<string> mergedVector;
    string temp;
    //if gets 1 then '-' describes unary exp', if 0 then binary
    int flag = 0;
    for (int i = 0; i < initialVector.size(); i++) {
        string str = initialVector[i];
        temp = "";
        //if the string describes a command, an IP address or inequality sign then push string to mergedVector.
        if (str == OPEN_DATA_SERVER || str == CONNECT_COMMAND || str == VAR_COMMAND || str == BIND_COMMAND ||
            str == EQUAL_OPERATOR ||
            str == WHILE_COMMAND || str == PRINT_COMMAND || str == SLEEP_COMMAND || str == GREATER_OPERATOR ||
            str == GREATER_EQUAL_OPERATOR || str == LESS_OPERATOR ||
            str == LESS_EQUAL_OPERATOR || str == IS_EQUAL_OPERATOR || str == UNEQUAL_OPERATOR || isIP(str)) {
            if (str == EQUAL_OPERATOR && initialVector[i + 1] == BIND_COMMAND) {
                i++;
                str += initialVector[i];
            }
            mergedVector.push_back(str);
            flag = 1;
            continue;
        }
            //this condition merges a calculation string that starts with '-' operator
        else if (initialVector[i] == MINUS_OPERATOR && (flag == 1 || i == 0)) {
            while (initialVector[i] == PLUS_OPERATOR || initialVector[i] == MULT_OPERATOR ||
                   initialVector[i] == DIV_OPERATOR ||
                   initialVector[i] == MINUS_OPERATOR) {
                temp += initialVector[i];
                temp += initialVector[i + 1];
                if (initialVector[i + 1] == PLUS_OPERATOR || initialVector[i + 1] == MULT_OPERATOR ||
                    initialVector[i + 1] == DIV_OPERATOR ||
                    initialVector[i + 1] == MINUS_OPERATOR) {
                    temp += initialVector[i + 2];
                    i += 3;
                } else if (i + 2 < initialVector.size()) { i += 2; }
                else {
                    i+=2;
                    break;
                }
            }
            mergedVector.push_back(temp);
            flag = 0;
            temp = "";
            i--;
            continue;
            //this condition merges a calculation string that doesn't starts with '-' operator
        } else if ((initialVector[i] == PLUS_OPERATOR || initialVector[i] == MULT_OPERATOR ||
                    initialVector[i] == DIV_OPERATOR ||
                    initialVector[i] == MINUS_OPERATOR) && i != 0) {
            while (initialVector[i] == PLUS_OPERATOR || initialVector[i] == MULT_OPERATOR ||
                   initialVector[i] == DIV_OPERATOR ||
                   initialVector[i] == MINUS_OPERATOR) {
                temp = mergedVector.back();
                mergedVector.pop_back();
                temp += initialVector[i];
                temp += initialVector[i + 1];
                if (initialVector[i + 1] == MINUS_OPERATOR) {
                    temp += initialVector[i + 2];
                    i += 3;
                } else { i += 2; }
                mergedVector.push_back(temp);
            }
            i--;
            flag = 0;
        } else if (initialVector[i] == COMMA_STR) {***
            flag = 1;
            continue;
        } else {
            mergedVector.push_back(str);
            flag = 0;
        }
    }
    return mergedVector;
}

//checks if the given string describes IP address
bool Lexer::isIP(const string &s) const {
    int counter = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s.at(i) == DOT_CHAR) {
            counter++;
        }
    }
    return (counter == IP_DOTS);
}