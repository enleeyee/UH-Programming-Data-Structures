#include "BST.h"
#include <iostream>
#include <queue>

Node::Node(int value) : data(value), left(nullptr), right(nullptr) {}

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    destroy(root);
}

void BinarySearchTree::destroy(Node* node) {
    if (node) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

void BinarySearchTree::insert(Node*& node, int value) {
    if (!node) {
        node = new Node(value);
    } else if (value < node->data) {
        insert(node->left, value);
    } else if (value > node->data) {
        insert(node->right, value);
    }
}

void BinarySearchTree::insert(int value) {
    insert(root, value);
}

void BinarySearchTree::preorder(Node* node) {
    if (!node) 
        return;
    
    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void BinarySearchTree::preorder() {
    preorder(root);
    std::cout << std::endl;
}

void BinarySearchTree::inorder(Node* node) {
    if (!node) 
        return;
    
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

void BinarySearchTree::inorder() {
    inorder(root);
    std::cout << std::endl;
}

void BinarySearchTree::postorder(Node* node) {
    if (!node) 
        return;
    
    postorder(node->left);
    postorder(node->right);
    std::cout << node->data << " ";
}

void BinarySearchTree::postorder() {
    postorder(root);
    std::cout << std::endl;
}

void BinarySearchTree::levelorder(Node* node) {
    if (!node) 
        return;

    std::queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* n = q.front();
        q.pop();
        std::cout << n->data << " ";

        if(n->left)
            q.push(n->left);
        if(n->right)
            q.push(n->right);
    }
}

void BinarySearchTree::levelorder() {
    levelorder(root);
    std::cout << std::endl;
}
