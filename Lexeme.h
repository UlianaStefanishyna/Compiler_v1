/**
 * @name Compiler C++ -> Assembly language
 *
 * @author Uliana Stefanishyna
 * @ingroup IO-52
 * @date 26.11.2017
 * @version 1.0
 *
 * */
#ifndef COMPILER_V3_SYNTAX_ANALYZER_H
#define COMPILER_V3_SYNTAX_ANALYZER_H

#include <vector>
#include "string"

using namespace std;

enum LexemeType {
    VARIABLE_TYPE,
    VARIABLE,
    KEYWORD,
    _UNKNOWN,
    INTEGER_NUMBER,
    FLOAT_NUMBER,
    OPENED_BRACKET,     // [
    CLOSED_BRACKET,     // ]
    PLUS,
    MINUS,
    ASTERIX,
    DIV,
    OPENED_PARENTHNESS, // (
    CLOSED_PARENTHNESS, // )
    EQUAL,
    INCREMENT,
    DECREMENT,
    SEMICOLUMN,
    COLUMN,
    PLUS_EQUAL,
    ASTERIX_EQUAL,
    DIV_EQUAL,
    MINUS_EQUAL,
    OPENED_BODY,        // {
    CLOSED_BODY         // }
};
typedef pair<string, LexemeType> lexemeType;

class Lexeme {
    vector<string> m_VariableType;
    vector<string> m_Keywords;
    vector<string> m_Delim;
    vector<lexemeType> m_NameTypes;
public:
    Lexeme();

    void addLexemeType(string str, LexemeType nameType);

    bool isVariableType(string str);

    bool isKeyword(string str);

    bool isSign(string str);

    void print();

    string getTypeByEnum(LexemeType type);

    void typeSigh(string str);
};

#endif //COMPILER_V3_SYNTAX_ANALYZER_H
