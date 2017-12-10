//
// Created by uliana on 29/11/17.
//

#include "NodeAST.h"


KeyWordType AST::getKeyWordType(vector<lexemeType> &lexeme) {
    if (lexeme[m_index].second != KEYWORD)
        return NOT_A_KEYWORD;
    else {
        if (lexeme[m_index].first == "if")
            return IF;
        else if (lexeme[m_index].first == "else")
            return ELSE;
        else if (lexeme[m_index].first == "for")
            return FOR;
        else if (lexeme[m_index].first == "while")
            return WHILE;
        else if (lexeme[m_index].first == "do")
            return DO;
    }
}

const vector<string> &AST::getM_errors() const {
    return m_errors;
}

void AST::ruleIF(vector<lexemeType> &lexeme) {
    if (getKeyWordType(lexeme) == IF) {
        m_index++;
        if (lexeme[m_index].second != OPENED_PARENTHNESS)
            m_errors.push_back("Missed opened parentheses for if-statement");
        else {
            string str = "";
            m_index++;
            for (int j = m_index; j < search(m_index, lexeme); j++) {
                str += lexeme[j].first;
                if_eval(str);
            }

        }
    }
}

int AST::search(int i, vector<lexemeType> &lexeme) {
    for (int j = i; j < lexeme.size(); j++) {
        if (lexeme[i].first == ")")
            return i;
        else
            m_errors.push_back("Missed closed parentheses for if-statement");
    }
    return -1;

}

bool AST::if_eval(string str){
    for(int i = 0; i < str.size(); i++){}

}