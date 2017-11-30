//
// Created by uliana on 29/11/17.
//

#include "NodeAST.h"


AST::AST() {
    root = NULL;
}

AST::~AST() {
    destroy_tree();
}

void AST::destroy_tree(Node *leaf) {
    if (leaf != NULL) {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void AST::insert(int key, Node *leaf) {
    if (key < leaf->key_value) {
        if (leaf->left != NULL)
            insert(key, leaf->left);
        else {
            leaf->left = new Node;
            leaf->left->key_value = key;
            leaf->left->left = NULL;    //Sets the left child of the child Node to null
            leaf->left->right = NULL;   //Sets the right child of the child Node to null
        }
    } else if (key >= leaf->key_value) {
        if (leaf->right != NULL)
            insert(key, leaf->right);
        else {
            leaf->right = new Node;
            leaf->right->key_value = key;
            leaf->right->left = NULL;  //Sets the left child of the child Node to null
            leaf->right->right = NULL; //Sets the right child of the child Node to null
        }
    }
}

Node *AST::search(int key, Node *leaf) {
    if (leaf != NULL) {
        if (key == leaf->key_value)
            return leaf;
        if (key < leaf->key_value)
            return search(key, leaf->left);
        else
            return search(key, leaf->right);
    } else return NULL;
}

void AST::insert(int key)
{
    if(root!=NULL)
        insert(key, root);
    else
    {
        root=new Node;
        root->key_value=key;
        root->left=NULL;
        root->right=NULL;
    }
}
Node *AST::search(int key)
{
    return search(key, root);
}
void AST::destroy_tree()
{
    destroy_tree(root);
}