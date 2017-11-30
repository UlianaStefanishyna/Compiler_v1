//
// Created by uliana on 30/11/17.
//

#ifndef COMPILER_V3_TREETRAIN_H
#define COMPILER_V3_TREETRAIN_H

#include <vector>
#include "string"
using namespace std;

enum type{
    COLUMN_,
    VALUE1,
    VALUE2,
    PLUS_
};

typedef pair<string, type> myType;

struct NodeT{
    type myEnum;
    //myType value;
    //int value;
    NodeT *left;
    NodeT *right;
};
class TreeTrain {
    //vector<myType> myVec;
    NodeT *root;
    void destroy_tree(NodeT *leaf);
    void insert(type _val, NodeT *leaf);
public:
    TreeTrain();
    ~TreeTrain();
    void destroy_tree();
    void insert(type _val);
};


#endif //COMPILER_V3_TREETRAIN_H
