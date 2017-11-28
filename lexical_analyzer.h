//
// Created by uliana on 28/11/17.
//
#include <iostream>
#include <fstream>
#include "string"
#include "Token.h"
using namespace std;

ifstream openFile(string filename);

void lexical_analyzer(string filename){
    ifstream inFile = openFile(filename);

    Token token;
    char ch;
    string str;
    while (inFile.get(ch)) {
        bool fDel = false;
        for (char temp : token.getM_Delimitations()) {
            if (temp == ch) {
                token.addDelimiter(ch);
                if(str != "")
                    token.addToken(str);
                str = "";
                fDel = true;
                break;
            }
        }
        if(fDel)
            continue;
        str += ch;
    }
    token.print();
}

ifstream openFile(string filename) {
    ifstream inFile;
    inFile.open(filename);
    string x = "";

    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    return inFile;
}