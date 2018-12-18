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
#define MAX_FILE 2
#define FILE_IN_ARG 1
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
//            char c = str[i];
            if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' &&
                                                     str[i] <= 'z' )|| isdigit(str[i]) || (str[i] == DOT)) {
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
    return lexer;
}

vector<string> Lexer::elementsMerge(vector<string> initialVector) {
    vector<string> mergedVector;
    string temp;
    int flag = 0;
    for (int i = 0; i < initialVector.size(); i++) {
        string str = initialVector[i];
        temp = "";
        //TODO in map
        if (str == "openDataServer" || str == "connect" || str == "var" || str == "bind" || str == "=" ||
            str == "while" || str == "print" || str == "sleep" || str == ">" || str == ">=" || str == "<" ||
            str == "<=" || str == "==" ) {
            mergedVector.push_back(str);
            flag = 1;
            continue;
        }
            //TODO MAGIC
        else if (initialVector[i] == "-" && (flag == 1 || i == 0)) {
            while (initialVector[i] == "+" || initialVector[i] == "*" || initialVector[i] == "/" ||
                   initialVector[i] == "-") {
                temp += initialVector[i];
                temp += initialVector[i + 1];
                if (initialVector[i+1] == "+" || initialVector[i+1] == "*" || initialVector[i+1] == "/" ||
                    initialVector[i+1] == "-") {
                    temp += initialVector[i + 2];
                    i += 3;
                } else { i += 2; }
            }
            mergedVector.push_back(temp);
            flag = 0;
            temp = "";
            i--;
            continue;

        } else if ((initialVector[i] == "+" || initialVector[i] == "*" || initialVector[i] == "/" ||
                    initialVector[i] == "-") && i != 0) {
            while (initialVector[i] == "+" || initialVector[i] == "*" || initialVector[i] == "/" ||
                   initialVector[i] == "-") {
                temp = mergedVector.back();
                mergedVector.pop_back();
                temp += initialVector[i];
                temp += initialVector[i + 1];
                if (initialVector[i + 1] == "-") {
                    temp += initialVector[i + 2];
                    i += 3;
                } else { i += 2; }
                mergedVector.push_back(temp);
            }
            i--;
            flag = 0;
        } else {
            mergedVector.push_back(str);
            flag = 0;
        }
    }
    return mergedVector;
}
