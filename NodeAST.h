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

class AST : public Tree {
    int m_index;
public:
    AST() : m_index(0) {}

    KeyWordType getKeyWordType(LexemeType lexemetype, string str);

};

#endif //COMPILER_V3_NODEAST_H

