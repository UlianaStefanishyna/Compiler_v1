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
#include "Tree.h"

int main() {

    string filename = "test";
    syntaxAnalyzer(lexicalAnalyzer(filename));


    return 0;
}

