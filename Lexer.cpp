//
// Created by roy on 16/12/18.
//

#include <iostream>
#include <fstream>
#include "Lexer.h"

#define TAB 9
#define SPACE 32
#define ENTER 10
#define MAX_FILE 2
#define FILE_IN_ARG 1

using namespace std;

/**
 * lexer from a given file.
 * @param textFile - file to read the commands from.
 * @return - vector with each word in it's own cell.
 */
vector<string> Lexer::lexerFromFile(const string &textFile) {
    vector<string> lexer;
    ifstream inputStream;
    inputStream.open(textFile);
    //couldn't open file.
    if (!(inputStream.is_open())){
        throw "Cannot open file to lexer.";
    }
    //read all the lines in the file.
    for (string str; getline(inputStream,str);){
        str+= ENTER;
        string temp = "";
        //go over the line and put each word in a different place.
        for(char& c : str) {
            //whitespace found, new word.
            if (c == ENTER || c == TAB || c == SPACE){
                if (!temp.empty()) {
                    lexer.push_back(temp);
                    temp = "";
                }
                continue;
            }
            temp += c;
        }
    }
    return lexer;
}

/**
 * Lexer a given command line.
 *
 * @param argc - number of arguments in argv.
 * @param argv - array of commands from command line.
 * @return - vector with words after they've been lexered.
 */
vector<string> Lexer::lexerFromCommand(int argc, char **argv) {
    vector<string> lexer;
    //start from the second place in the array as the first is the file's name.
    for (int i=1; i<argc; i++){
        lexer.push_back(argv[i]);
    }
    return lexer;
}

/**
 * Returns a vector with strings that has been lexered.
 *
 * @param argc - from command line.
 * @param argv - from command line.
 * @return - string vector.
 */
vector<string> Lexer::lexer(int argc, char **argv) {
    //2 arguments means read from a file.
    if (argc == MAX_FILE){
        return lexerFromFile(argv[FILE_IN_ARG]);
    } else {
        return lexerFromCommand(argc,argv);
    }
}
