/**
 * @name Compiler C++ -> Assembly language
 *
 * @author Uliana Stefanishyna
 * @ingroup IO-52
 * @date 26.11.2017
 * @version 1.0
 *
 * */
#include <iostream>
#include <fstream>
#include "string"
#include "Token.h"
#include "syntax_analyzer.h"
using namespace std;

ifstream openFile(string filename);

Token lexical_analyzer(string filename){
    ifstream inFile = openFile(filename);

    Token token;
    char ch;
    string str;
    while (inFile.get(ch)) {
        bool fDel = false;
        for (char temp : token.getM_Delimitations()) {
            if (temp == ch) {
                if(ch != ' ')
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


    return token;
}

void syntaxAlnalyzer(Token token){
    syntax_analyzer sa;
    for(unsigned i = 0; i < token.getM_Tokens().size(); i++) {
        string str = token.getM_Tokens()[i].first;
        if(sa.isVariableType(str))
            sa.addNameType(str,VARIABLE_TYPE);
        else {
            if(sa.isKeyword(str)) sa.addNameType(str,KEYWORD);
            else if(token.getM_Tokens()[i].second == UNKNOWN) sa.addNameType(str, UNKNOWN_VARIABLE);
            else if(token.getM_Tokens()[i].second == NAME) sa.addNameType(str,VARIABLE);
        }
    }
    sa.print();
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