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
#include "Lexeme.h"

Lexeme::Lexeme() {
    m_VariableType = {"int", "double", "void", "float", "long", "short", "bool", "char"};
    m_Keywords = {"if", "else", "for", "while", "do"};
    m_Delim = {"/", "*", "-", "+", "=", "(", ")", ";", ":", "{", "}", "[", "]", " "};
}

bool Lexeme::isVariableType(string str) {
    for (string temp : m_VariableType) {
        if (str == temp)
            return true;
    }
    return false;
}

bool Lexeme::isKeyword(string str) {
    for (string temp : m_Keywords) {
        if (str == temp)
            return true;
    }
    return false;
}

bool Lexeme::isSign(string str) {
    for (string temp : m_Delim)
        if (temp == str)
            return true;
    return false;
}
bool Lexeme::isFloat(string str){
    for(char i = 0; i < str.size(); i++)
        if(str[i] == '.')
            return true;
    return false;
}

void Lexeme::addLexemeType(string str, LexemeType nameType) {
    lexemeType m_Pair(str, nameType);
    m_NameTypes.push_back(m_Pair);
}

void Lexeme::print() {
    cout << "====Output of syntax analyzer===" << endl;
    cout << endl;
    for (unsigned i = 0; i < m_NameTypes.size(); i++) {
        cout << m_NameTypes[i].first << "\t->\t " << getTypeByEnum(m_NameTypes[i].second) << endl;
    }
    cout << "================================" << endl;
}

void Lexeme::typeSigh(string str) {
    char ch = str[0];
    switch (ch) {
        case '[':
            addLexemeType(str, OPENED_BRACKET);
            return;
        case ']':
            addLexemeType(str, CLOSED_BRACKET);
            return;
        case '+':
            addLexemeType(str, PLUS);
            return;
        case '-':
            addLexemeType(str, MINUS);
            return;
        case '*':
            addLexemeType(str, ASTERIX);
            return;
        case '/':
            addLexemeType(str, DIV);
            return;
        case '(':
            addLexemeType(str, OPENED_PARENTHNESS);
            return;
        case ')':
            addLexemeType(str, CLOSED_PARENTHNESS);
            return;
        case '=':
            addLexemeType(str, EQUAL);
            return;
        case ':':
            addLexemeType(str, SEMICOLUMN);
            return;
        case ';':
            addLexemeType(str, COLUMN);
            return;
        case '{':
            addLexemeType(str, OPENED_BODY);
            return;
        case '}':
            addLexemeType(str, CLOSED_BODY);
            return;
        default:
            break;
    }
    if (str == "++")
        addLexemeType(str, INCREMENT);
    else if (str == "--")
        addLexemeType(str, DECREMENT);
    else if (str == "+=")
        addLexemeType(str, PLUS_EQUAL);
    else if (str == "*=")
        addLexemeType(str, ASTERIX_EQUAL);
    else if (str == "/=")
        addLexemeType(str, DIV_EQUAL);
    else if (str == "-=")
        addLexemeType(str, MINUS_EQUAL);
}

string Lexeme::getTypeByEnum(LexemeType type) {
    switch (type) {
        case VARIABLE_TYPE:
            return "VARIABLE_TYPE";
        case VARIABLE:
            return "VARIABLE";
        case KEYWORD:
            return "KEYWORD";
        case _UNKNOWN:
            return "UNKNOWN";
        case OPENED_BRACKET:
            return "OPENED_BRACKET";
        case CLOSED_BRACKET:
            return "CLOSED_BRACKET";
        case PLUS:
            return "PLUS";
        case MINUS:
            return "MINUS";
        case ASTERIX:
            return "ASTERIX";
        case DIV:
            return "DIV";
        case OPENED_PARENTHNESS:
            return "OPENED_PARENTHNESS";
        case CLOSED_PARENTHNESS:
            return "CLOSED_PARENTHNESS";
        case EQUAL:
            return "EQUAL";
        case INCREMENT:
            return "INCREMENT";
        case DECREMENT:
            return "DECREMENT";
        case SEMICOLUMN:
            return "SEMICOLUMN";
        case COLUMN:
            return "COLUMN";
        case PLUS_EQUAL:
            return "PLUS_EQUAL";
        case ASTERIX_EQUAL:
            return "ASTERIX_EQUAL";
        case DIV_EQUAL:
            return "DIV_EQUAL";
        case MINUS_EQUAL:
            return "MINUS_EQUAL";
        case OPENED_BODY:
            return "OPENED_BODY";
        case CLOSED_BODY:
            return "CLOSED_BODY ";
        case INTEGER_NUMBER:
            return "INTEGER_NUMBER";
        case FLOAT_NUMBER:
            return "FLOAT_NUMBER";
        default:
            break;
    }
}

const vector<lexemeType> &Lexeme::getM_NameTypes() const {
    return m_NameTypes;
}
