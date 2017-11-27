
#include "Token.h"

Token::Token() {
    m_Token = "";
    m_TokenType = UNKNOWN;
    m_charDelim = {'/', '*', '-', '+', '=', '(', ')', ';', ':', '{', '}', '[', ']', ' '};
}

void Token::addToken(string token) {
    tokens m_Pair(token, getTokenType(token));
    m_Tokens.push_back(m_Pair);
}
void Token::addDelimiter(char delim){
    delimiters m_Pair(delim, DELIMITATION);
    m_Delimitations.push_back(m_Pair);
}
TokenType Token::getTokenType(string str) {
    if (isVariable(str))
        return NAME;
    if (isDigit(str))
        return NUMBER;
    else
        return UNKNOWN;

}

bool Token::isVariable(string str) {
    int index = 0;
    int ch = str[index];
    while (index < str.size()) {
        if ((ch >= 'a') && (ch <= 'z') || (ch >= 'A') && (ch <= 'Z') || (ch >= '0') && (ch <= '9') || (ch == '#') ||
            (ch == '$')) {
            if ((index == 0) && ((ch >= '0') && (ch <= '9') || (ch == '#') || (ch == '$')))
                return false;
            index++;
        }
        else
            return false;
    }
    return true;
}

bool Token::isDigit(string str) {
    int index = 0;
    int ch = str[index];
    while (index < str.size()) {
        if ((ch >= '0') && (ch <= '9') || (ch == '.')) {
            index++;
        }
        else
            return false;
    }
    return true;
}

const vector<char> &Token::getM_Delimitations() const {
    return m_charDelim;
}

void Token::setM_TokenType(TokenType m_TokenType) {
    Token::m_TokenType = m_TokenType;
}

void Token::setM_Tokens(const vector<tokens> &m_Tokens) {
    Token::m_Tokens = m_Tokens;
}
