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
#include "TreeTrain.h"

int main() {

    string filename = "test";
    //syntaxAnalyzer(lexicalAnalyzer(filename));

    TreeTrain train;
    train.insert(5);
    train.insert(2);
    train.insert(8);
    train.insert(9);
    train.destroy_tree();

    return 0;
}

