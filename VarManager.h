//
// Created by idantp on 12/19/18.
//

#ifndef EX3_VARMANAGER_H
#define EX3_VARMANAGER_H

#include <map>
#include <string>
#include <vector>

using namespace std;

class VarManager {
    map<string, double> symbolTable;
    map<string, string> bindedVars;
    vector<string> pathsFromXML;
    map<string, double> paths;
    vector<int> openSocketfds;
    bool end = false;
    //reference counter for this class
    int counter = 0;
    mutable pthread_mutex_t mutex;
public:
    //reference counter.
    int incCount() {
        pthread_mutex_lock(&mutex);
        int temp = ++counter;
        pthread_mutex_unlock(&mutex);
        return temp;
    }

    int decCount() {
        pthread_mutex_lock(&mutex);
        int temp = --counter;
        pthread_mutex_unlock(&mutex);
        return temp;
    }

    int getCount() {
        pthread_mutex_lock(&mutex);
        int temp = counter;
        pthread_mutex_unlock(&mutex);
        return temp;
    }

    bool shouldContinue() const {
        return !end;
    }

    bool signalFinished() {
        end = true;
    }

    VarManager();

    void updateXMLVars(const char *buffer, int size);

    void addToSymbolTable(string name, double value);

    void addToBindedVars(string name, string path);

    double getValueByName(string name);

    string getPathByName(string name);

    double getValueByPath(string path);

    void setValueByName(string name, double value);

    void setValueByPath(string path, double value);

    void setPathByName(string name, string path);

    bool doesExistInSymbolTable(string name);

    bool doesExistInPathsMap(string path);

    bool doesExistInBindedVars(string name);

    const map<string, string> &getBindedVars() const;

    const map<string, double> &getPaths() const;

    void addSockfd(int sockfd) {
        this->openSocketfds.emplace_back(sockfd);
    }

    vector<int> getSockfd() {
        return this->openSocketfds;
    }

    ~VarManager() {
        pthread_mutex_destroy(&mutex);
    }

private:
    void initializeXMLVector();

    void initializePaths();
};


#endif //EX3_VARMANAGER_H
