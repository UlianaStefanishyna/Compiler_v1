//
// Created by uliana on 27/11/17.
//

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
typedef pair<char, TokenType> delimiters;

class Token {
    string m_Token;
    TokenType m_TokenType;
    vector<tokens> m_Tokens;
    vector<delimiters> m_Delimitations;
    vector<char> m_charDelim;

public:
    Token();

    void setM_TokenType(TokenType m_TokenType);

    void setM_Tokens(const vector<tokens> &m_Tokens);

    const vector<char> &getM_Delimitations() const;

    void addToken(string token);

    void addDelimiter(char delim);

    TokenType getTokenType(string str);

    bool isVariable(string str);

    bool isDigit(string str);
};


#endif //COMPILER_V3_TOKEN_H
