/**
 * @name Compiler C++ -> Assembly language
 *
 * @author Uliana Stefanishyna
 * @ingroup IO-52
 * @date 26.11.2017
 * @version 1.0
 *
 * */
#include "Analyzer.h"
#include "NodeAST.h"

int main() {

    string filename = "test";
    //lexicalAnalyzer(filename);
    syntaxAnalyzer(lexicalAnalyzer(filename));

    ASTNode astNode;
    return 0;
}

