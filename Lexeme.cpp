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


void Lexeme::addNameType(string str, NameType nameType) {
    nametype m_Pair(str, nameType);
    m_NameTypes.push_back(m_Pair);
}

void Lexeme::print() {
    cout << "====Output of syntax analyzer===" << endl;
    cout << endl;
    for (unsigned i = 0; i < m_NameTypes.size(); i++) {
        cout << m_NameTypes[i].first << "\t->\t " << getNameByEnum(m_NameTypes[i].second) << endl;
    }
    cout << "================================" << endl;
}

string Lexeme::getNameByEnum(NameType type) {
    switch (type) {
        case VARIABLE_TYPE:
            return "VARIABLE_TYPE";
        case VARIABLE:
            return "VARIABLE";
        case KEYWORD:
            return "KEYWORD";
        case UNKNOWN_VARIABLE:
            return "UNKNOWN VARIABLE";
        default:
            break;
    }
}

string Lexeme::checkSigh(SighType sighType){
    switch (sighType){
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
        default:
            break;
    }
}