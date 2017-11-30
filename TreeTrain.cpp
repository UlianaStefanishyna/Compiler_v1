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

void TreeTrain::insert(type _val, NodeT *leaf) {
    if(_val == PLUS_){
        if(leaf->left != nullptr) {
            insert(_val, leaf->left);
            cout << "value " << _val << " added as left leaf" << endl;
        }
        else{
            leaf->left = new NodeT;
            leaf->left->myEnum = _val;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
            cout << "leaf was empty; PLUS " << _val << " added as left child" << endl;
        }

    } else if(_val == VALUE1){
        if(leaf->right != nullptr) {
            insert(_val, leaf->right);
            cout << "value " << _val << " added as right leaf" << endl;
        }
        else{
            leaf->right = new NodeT;
            leaf->right->myEnum = _val;
            leaf->right->left = nullptr;
            leaf->right->right = nullptr;
            cout << "leaf was empty; VALUE1 " << _val << " added as right child" << endl;
        }
    } else if(_val == VALUE2){
        if(leaf->left != nullptr) {
            insert(_val, leaf->left);
            cout << "value " << _val << " added as right leaf" << endl;
        }
        else{
            leaf->left = new NodeT;
            leaf->left->myEnum = _val;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
            cout << "leaf was empty; VALUE2 " << _val << " added as left child" << endl;
        }
    }

}


void TreeTrain::insert(type _val){
    if(root != nullptr){
        insert(_val, root);
    }
    else if(_val == COLUMN_){
        root = new NodeT;
        cout << "root " << root << endl;
        root->myEnum = _val;
        root->right = nullptr;
        root->left = nullptr;
        cout << "COLUMN " << _val << " added as root. It was empty" << endl;
    }
}
