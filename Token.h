//
// Created by uliana on 27/11/17.
//
/**
 * @name Compiler C++ -> Assembly language
 *
 * @author Uliana Stefanishyna
 * @ingroup IO-52
 * @date 26.11.2017
 * @version 1.0
 *
 * */
#ifndef COMPILER_V3_TOKEN_H
#define COMPILER_V3_TOKEN_H

#include <vector>
#include "string"

using namespace std;

enum TokenType {
    NAME,       // var
    NUMBER,         // [0..9]{x}
    DELIMITATION,
    UNKNOWN
};
typedef pair<string, TokenType> tokens;

class Token {
    vector<tokens> m_Tokens;
    vector<string> m_Delim;


public:
    Token();



    const vector<string> &getM_Delim() const;

    const vector<tokens> &getM_Tokens() const;

    TokenType getTokenType(string str);

    string getNameByEnum(TokenType type);

    void addToken(string token);

    bool isVariable(string str);

    bool isDigit(string str);

    bool isDelimiter(string str);

    void print();
};


#endif //COMPILER_V3_TOKEN_H
