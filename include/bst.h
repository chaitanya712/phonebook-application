#ifndef BST_H
#define BST_H
#include "contact.h"
struct BSTNode {
    Contact data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(Contact c) : data(c), left(nullptr), right(nullptr) {}
};
class BST {
public:
    void insert(Contact);
    void inorder();
    Contact* search(const std::string& name);
    void clear();
private:
    BSTNode* root = nullptr;
    void insert(BSTNode*&, Contact);
    void inorder(BSTNode*);
    Contact* search(BSTNode*, const std::string&);
    void clear(BSTNode*);
};
#endif