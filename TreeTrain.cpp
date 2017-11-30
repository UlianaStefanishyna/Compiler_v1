//
// Created by uliana on 30/11/17.
//

#include "TreeTrain.h"
#include "iostream"
using namespace std;

TreeTrain::TreeTrain() {
    root = nullptr;
    cout << "root initialized" << endl;
}

TreeTrain::~TreeTrain() {
    destroy_tree();
    cout << "tree deleted" << endl;
}

void TreeTrain::destroy_tree(NodeT *leaf) {
    if (leaf != nullptr) {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
        cout << "leaf deleted" << endl;
    }
}

void TreeTrain::destroy_tree() {
    destroy_tree(root);
    cout << "root deleted" << endl;

}

void TreeTrain::insert(int _val, NodeT *leaf) {
    if(_val < leaf->value){
        if(leaf->left != nullptr) {
            insert(_val, leaf->left);
            cout << "value " << _val << " added as left leaf" << endl;
        }
        else{
            leaf->left = new NodeT;
            leaf->left->value = _val;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
            cout << "leaf was empty; value " << _val << " added as left child" << endl;
        }

    } else if(_val >= leaf->value){
        if(leaf->right != nullptr) {
            insert(_val, leaf->right);
            cout << "value " << _val << " added as right leaf" << endl;
        }
        else{
            leaf->right = new NodeT;
            leaf->right->value = _val;
            leaf->right->left = nullptr;
            leaf->right->right = nullptr;
            cout << "leaf was empty; value " << _val << " added as right child" << endl;
        }
    }
}


void TreeTrain::insert(int _val){
    if(root != nullptr){
        insert(_val, root);
        cout << " value " << _val << " added as root child" << endl;
    }
    else{
        root = new NodeT;
        root->value = _val;
        root->right = nullptr;
        root->left = nullptr;
        cout << " value " << _val << " added as root. It was empty" << endl;
    }
}
