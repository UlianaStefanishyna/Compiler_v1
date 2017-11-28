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

enum NameType {
    VARIABLE_TYPE,
    VARIABLE,
    KEYWORD,
    UNKNOWN_VARIABLE
};
enum NumberType {
    INTEGER,
    FLOAT
};

enum SighType {
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
typedef pair<string, NameType> nametype;

class Lexeme {
    vector<string> m_VariableType;
    vector<string> m_Keywords;
    vector<nametype> m_NameTypes;
public:
    Lexeme();

    void addNameType(string str, NameType nameType);

    bool isVariableType(string str);

    bool isKeyword(string str);

    void print();

    string getNameByEnum(NameType type);
    string checkSigh(SighType sighType);
};

#endif //COMPILER_V3_SYNTAX_ANALYZER_H
