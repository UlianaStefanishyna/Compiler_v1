//
// Created by uliana on 30/11/17.
//

#include "Tree.h"
#include "iostream"

using namespace std;

Tree::Tree() {
    root = nullptr;
    cout << "root initialized" << endl;
}

Tree::~Tree() {
    destroy_tree();
    cout << "tree deleted" << endl;
}

void Tree::destroy_tree(NodeT *leaf) {
    if (leaf != nullptr) {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void Tree::destroy_tree() {
    destroy_tree(root);
    cout << "root deleted" << endl;

}

void Tree::insert(LexemeType _val, NodeT *leaf) {
    if (_val == PLUS) {
        if (leaf->left != nullptr) {
            insert(_val, leaf->left);
            cout << _val << " -  left leaf" << endl;
        } else {
            leaf->left = new NodeT;
            leaf->left->str = _val;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
            cout << _val << " - left child  ()" << endl;
        }
    } else if (_val == CLOSED_PARENTHNESS) {
        if (leaf->right != nullptr) {
            insert(_val, leaf->right);
        } else {
            leaf->right = new NodeT;
            //leaf->right->str = _val.first;
            leaf->right->left = nullptr;
            leaf->right->right = nullptr;
            cout << _val << " - right child ()  " << leaf->right << endl;
        }
    } else if (_val == OPENED_PARENTHNESS) {
        if (leaf->left != nullptr) {
            insert(_val, leaf->left);
        } else {
            leaf->left = new NodeT;
            leaf->left->myEnum = _UNKNOWN;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
            cout << _val << " -  left child ()  " << leaf->left << endl;
        }
    } else {
        if (leaf->myEnum == _UNKNOWN) {
            leaf->myEnum = _val;
        }
    }
}

void Tree::insert(LexemeType _val) {
    if (root != nullptr) {
        insert(_val, root);
    } else {
        root = new NodeT;
        root->myEnum = _val;
        root->right = nullptr;
        root->left = nullptr;
        cout << " -  root. () &" << root << endl;
    }
}

