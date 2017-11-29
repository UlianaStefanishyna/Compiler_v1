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
#include "Token.h"

Token::Token() {
    m_Delim = {"/", "*", "-", "+", "=", "(", ")", ";", ":", "{", "}", "[", "]", " "};
}

void Token::addToken(string token) {
    tokens m_Pair(token, getTokenType(token));
    m_Tokens.push_back(m_Pair);
}

TokenType Token::getTokenType(string str) {
    if (isVariable(str))
        return NAME;
    if (isDigit(str))
        return NUMBER;
    if (isDelimiter(str))
        return DELIMITATION;
    else
        return UNKNOWN;

}

bool Token::isDelimiter(string str) {
    for (string temp : m_Delim) {
        if (temp == str)
            return true;
    }
    return false;
}

bool Token::isVariable(string str) {
    int index = 0;
    int ch = str[index];
    while (index < str.size()) {
        if ((ch >= 'a') && (ch <= 'z') || (ch >= 'A') && (ch <= 'Z') || (ch >= '0') && (ch <= '9') || (ch == '#') ||
            (ch == '$')  || (ch == '_')) {
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


const vector<tokens> &Token::getM_Tokens() const {
    return m_Tokens;
}


void Token::print() {
    cout << "====Output of lexical analyzer===" << endl;
    for (unsigned i = 0; i < m_Tokens.size(); i++) {
        cout << m_Tokens[i].first << "\t\t->\t\t " << getNameByEnum(m_Tokens[i].second) << endl;
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

const vector<string> &Token::getM_Delim() const {
    return m_Delim;
}
