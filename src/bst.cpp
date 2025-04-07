#include "bst.h"
#include <iostream>
void BST::insert(Contact c) { insert(root, c); }
void BST::insert(BSTNode*& node, Contact c) {
    if (!node) node = new BSTNode(c);
    else if (c.getName() < node->data.getName()) insert(node->left, c);
    else insert(node->right, c);
}
void BST::inorder() { inorder(root); }
void BST::inorder(BSTNode* node) {
    if (!node) return;
    inorder(node->left);
    std::cout << node->data.getName() << " | " << node->data.getPhone() << " | " << node->data.getEmail() << "\n";
    inorder(node->right);
}
Contact* BST::search(const std::string& name) { return search(root, name); }
Contact* BST::search(BSTNode* node, const std::string& name) {
    if (!node) return nullptr;
    if (node->data.getName() == name) return &node->data;
    else if (name < node->data.getName()) return search(node->left, name);
    else return search(node->right, name);
}
void BST::clear() { clear(root); root = nullptr; }
void BST::clear(BSTNode* node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}
