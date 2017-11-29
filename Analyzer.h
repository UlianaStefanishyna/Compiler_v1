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
#include "sstream"
#include "Token.h"
#include "Lexeme.h"

using namespace std;

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

Token lexicalAnalyzer(string filename) {
    ifstream inFile = openFile(filename);

    string str_cast;

    Token token;
    char ch;
    string str;
    while (inFile.get(ch)) {
        bool fDel = false;
        str_cast.push_back(ch);
        for (string temp : token.getM_Delim()) {
            if (temp == str_cast) {
                if (str != "")
                    token.addToken(str);
                if (str_cast != " ")
                    token.addToken(str_cast);
                str = "";
                str_cast = "";
                fDel = true;
                break;
            }
        }
        if (fDel)
            continue;
        str += str_cast;
        str_cast = "";
    }
    if (str != "")
        token.addToken(str);
    token.print();

    return token;
}

void syntaxAnalyzer(Token token) {
    Lexeme sa;
    for (unsigned i = 0; i < token.getM_Tokens().size(); i++) {
        string str = token.getM_Tokens()[i].first;
        if (sa.isVariableType(str))
            sa.addLexemeType(str, VARIABLE_TYPE);
        else if (sa.isKeyword(str))
            sa.addLexemeType(str, KEYWORD);
        else if (token.getM_Tokens()[i].second == UNKNOWN)
            sa.addLexemeType(str, _UNKNOWN);
        else if (token.getM_Tokens()[i].second == NAME)
            sa.addLexemeType(str, VARIABLE);
        else if(sa.isSign(str))
            sa.typeSigh(str);
        else if (token.getM_Tokens()[i].second == NUMBER) {
            if (sa.isFloat(str))
                sa.addLexemeType(str, FLOAT_NUMBER);
            else
                sa.addLexemeType(str, INTEGER_NUMBER);
        }
    }
    sa.print();
}

