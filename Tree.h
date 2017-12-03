//
// Created by uliana on 30/11/17.
//

#ifndef COMPILER_V3_TREETRAIN_H
#define COMPILER_V3_TREETRAIN_H

#include <vector>
#include "string"
#include "Lexeme.h"

using namespace std;


typedef pair<char, LexemeType> myType;

struct NodeT {
    LexemeType myEnum;
    NodeT *left;
    NodeT *right;
};

class Tree {
    NodeT *root;

    void destroy_tree(NodeT *leaf);

    void insert(LexemeType _val, NodeT *leaf);

public:
    Tree();

    ~Tree();

    void destroy_tree();

    void insert(LexemeType _val);
};

#endif //COMPILER_V3_TREETRAIN_H
