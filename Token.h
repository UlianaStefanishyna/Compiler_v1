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
    vector<tokens> m_Tokens;
public:
    void setM_Tokens(const vector<tokens> &m_Tokens);

private:
    vector<delimiters> m_Delimitations;
    vector<char> m_charDelim;

public:
    Token();

    const vector<char> &getM_Delimitations() const;
    const vector<tokens> &getM_Tokens() const;

    void addToken(string token);

    void addDelimiter(char delim);

    TokenType getTokenType(string str);

    bool isVariable(string str);

    bool isDigit(string str);

    string getNameByEnum(TokenType type);
    void print();
};


#endif //COMPILER_V3_TOKEN_H
