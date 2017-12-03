#include "SemanticGrammar.h"

void SemanticGrammar::ruleIF(LexemeType _val) {
    if(_val == IF) {
        insert(_val);
    } else if(_val == OPENED_PARENTHNESS){
        insert(_val);
    }


}