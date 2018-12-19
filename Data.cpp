////
//// Created by roy on 17/12/18.
////
//
//#include "Data.h"
//
//using namespace std;
//
////TODO - why isn't it working.
//Data::Data() {
//
//}
//
//const map<string, double> &Data::getSymbolTable() {
//    return symbolTable;
//}
//
//
//double Data::getValue(string name) {
//    //could not find the variable name in symbol table.
//    if (getSymbolTable().find(name) == getSymbolTable().end()){
//        throw "No such Var created previously.";
//    } else {
//        return getSymbolTable().find(name)->second;
//    }
//}
//
//void Data::updateValue(string name, double value) {
//
//}
//
//void Data::addNewVar(string name, double value) {
//
//}
