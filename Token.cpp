
#include <iostream>
#include "Token.h"

Token::Token() {
    m_charDelim = {'/', '*', '-', '+', '=', '(', ')', ';', ':', '{', '}', '[', ']', ' '};
}

void Token::addToken(string token) {
    tokens m_Pair(token, getTokenType(token));
    m_Tokens.push_back(m_Pair);
}

void Token::addDelimiter(char delim) {
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
            ch = str[index];
        } else
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
            ch = str[index];
        } else
            return false;
    }
    return true;
}

const vector<char> &Token::getM_Delimitations() const {
    return m_charDelim;
}

const vector<tokens> &Token::getM_Tokens() const {
    return m_Tokens;
}


void Token::print() {
    cout << "====Output of lexical analyzer===" << endl;
    for (unsigned i = 0; i < m_Tokens.size(); i++) {
        cout << m_Tokens[i].first << "\t->\t " << getNameByEnum(m_Tokens[i].second) << endl;
    }
    cout << endl;
    for (unsigned i = 0; i < m_Delimitations.size(); i++) {
        cout << m_Delimitations[i].first << "\t->\t" << getNameByEnum(m_Delimitations[i].second) << endl;
    }
    cout << "=================================" << endl;
}

string Token::getNameByEnum(TokenType type) {
    switch (type) {
        case NAME:
            return "NAME";
        case NUMBER:
            return "NUMBER";
        case DELIMITATION:
            return "DELIMITATION";
        case UNKNOWN:
            return "UNKNOWN";
        default:
            break;
    }
}

void Token::setM_Tokens(const vector<tokens> &m_Tokens) {
    Token::m_Tokens = m_Tokens;
}
