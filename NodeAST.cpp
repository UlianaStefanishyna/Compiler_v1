//
// Created by uliana on 29/11/17.
//

#include "NodeAST.h"


KeyWordType AST::getKeyWordType(LexemeType lexemetype, string str) {
    if (lexemetype != KEYWORD)
        return NOT_A_KEYWORD;
    else {
        if (str == "if")
            return IF;
        else if (str == "else")
            return ELSE;
        else if (str == "for")
            return FOR;
        else if (str == "while")
            return WHILE;
        else if (str == "do")
            return DO;
    }
}

void ruleIF(){

}