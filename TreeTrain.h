//
// Created by uliana on 30/11/17.
//

#ifndef COMPILER_V3_TREETRAIN_H
#define COMPILER_V3_TREETRAIN_H

#include "string"
using namespace std;

enum{
    VALUE,
    OPENED,
    CLOSED,
    PLUS_
};

struct NodeT{
    int value;
    NodeT *left;
    NodeT *right;
};
class TreeTrain {
    NodeT *root;
    void destroy_tree(NodeT *leaf);
    void insert(int _val, NodeT *leaf);
public:
    TreeTrain();
    ~TreeTrain();
    void destroy_tree();
    void insert(int _val);
};


#endif //COMPILER_V3_TREETRAIN_H
