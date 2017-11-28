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
#include "syntax_analyzer.h"

syntax_analyzer::syntax_analyzer() {
    m_VariableType = {"int", "double", "void", "float", "long", "short", "bool", "char"};
    m_Keywords = {"if", "else", "for", "while", "do"};
}

bool syntax_analyzer::isVariableType(string str) {
    for (string temp : m_VariableType) {
        if (str == temp)
            return true;
    }
    return false;
}

bool syntax_analyzer::isKeyword(string str) {
    for (string temp : m_Keywords) {
        if (str == temp)
            return true;
    }
    return false;
}


void syntax_analyzer::addNameType(string str, NameType nameType) {
    nametype m_Pair(str, nameType);
    m_NameTypes.push_back(m_Pair);
}

void syntax_analyzer::print() {
    cout << "====Output of syntax analyzer===" << endl;
    cout << endl;
    for (unsigned i = 0; i < m_NameTypes.size(); i++) {
        cout << m_NameTypes[i].first << "\t->\t " << getNameByEnum(m_NameTypes[i].second) << endl;
    }
    cout << "================================" << endl;
}

string syntax_analyzer::getNameByEnum(NameType type) {
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