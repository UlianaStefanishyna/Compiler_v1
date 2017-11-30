//
// Created by uliana on 29/11/17.
//

#ifndef COMPILER_V3_NODEAST_H
#define COMPILER_V3_NODEAST_H

#include <stddef.h>
#include "Lexeme.h"

struct Node {
    int key_value;
    Node *left;
    Node *right;
};

class AST {
public:
    AST();

    ~AST();

    void insert(int key);

    Node *search(int key);

    void destroy_tree();

private:
    void destroy_tree(Node *leaf);

    void insert(int key, Node *leaf);

    Node *search(int key, Node *leaf);

    Node *root;
};

#endif //COMPILER_V3_NODEAST_H
