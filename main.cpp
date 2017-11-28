/**
 * @name Compiler C++ -> Assembly language
 *
 * @author Uliana Stefanishyna
 * @ingroup IO-52
 * @date 26.11.2017
 * @version 1.0
 *
 * */
#include "analyzer.h"

int main() {

    string filename = "test";

    syntaxAlnalyzer(lexical_analyzer(filename));

    return 0;
}

