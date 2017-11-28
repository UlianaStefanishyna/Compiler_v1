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
typedef pair<string, NameType> nametype;

class syntax_analyzer {
    vector<string> m_VariableType;
    vector<string> m_Keywords;
    vector<nametype> m_NameTypes;
public:
    syntax_analyzer();

    void addNameType(string str, NameType nameType);

    bool isVariableType(string str);

    bool isKeyword(string str);

    void print();

    string getNameByEnum(NameType type);
};
#endif //COMPILER_V3_SYNTAX_ANALYZER_H
