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
    train.insert(COLUMN_);
    train.insert(PLUS_);
    train.insert(VALUE1);
    train.insert(VALUE2);
    train.destroy_tree();

    return 0;
}

