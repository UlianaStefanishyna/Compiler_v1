//
// Created by uliana on 29/11/17.
//

#ifndef COMPILER_V3_NODEAST_H
#define COMPILER_V3_NODEAST_H

#include "Lexeme.h"
#include "Tree.h"

enum KeyWordType {
    IF,
    ELSE,
    FOR,
    WHILE,
    DO,
    NOT_A_KEYWORD
};

enum _IF {};

class AST : public Tree {
    int m_index;
    vector<string> m_errors;
    vector<string> operatorCompare;
public:
    const vector<string> &getM_errors() const;

    AST() : m_index(0) {
        operatorCompare = {"<", ">", "=="};
    }

    KeyWordType getKeyWordType(vector<lexemeType> &lexeme);

    int search(int i, vector<lexemeType> &lexeme);

    void ruleIF(vector<lexemeType> &lexeme);
    bool if_eval(string str);
};

#endif //COMPILER_V3_NODEAST_H

