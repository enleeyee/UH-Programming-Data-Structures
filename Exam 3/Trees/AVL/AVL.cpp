#include "AVL.h"
#include <iostream>
#include <algorithm>

AVLNode::AVLNode(int value)
    : data(value), left(nullptr), right(nullptr), height(1) {}

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() {
    destroy(root);
}

void AVLTree::destroy(AVLNode* node) {
    if (node) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

int AVLTree::height(AVLNode* node) {
    return node ? node->height : 0;
}

int AVLTree::getBalance(AVLNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* z = x->right;

    x->right = y;
    y->left = z;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode* AVLTree::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* z = y->left;

    y->left = x;
    x->right = z;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLNode* AVLTree::insert(AVLNode* node, int value) {
    if (!node) return new AVLNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else
        return node;

    node->height = 1 + std::max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // Left Left
    if (balance > 1 && value < node->left->data)
        return rotateRight(node);

    // Right Right
    if (balance < -1 && value > node->right->data)
        return rotateLeft(node);

    // Left Right
    if (balance > 1 && value > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left
    if (balance < -1 && value < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVLTree::insert(int value) {
    root = insert(root, value);
}

void AVLTree::preorder(AVLNode* node) {
    if (!node) 
        return;
    
    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void AVLTree::preorder() {
    preorder(root);
    std::cout << std::endl;
}

void AVLTree::inorder(AVLNode* node) {
    if (!node) 
        return;
    
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

void AVLTree::inorder() {
    inorder(root);
    std::cout << std::endl;
}

void AVLTree::postorder(AVLNode* node) {
    if (!node) 
        return;
    
    postorder(node->left);
    postorder(node->right);
    std::cout << node->data << " ";
}

void AVLTree::postorder() {
    postorder(root);
    std::cout << std::endl;
}

void AVLTree::levelorder(AVLNode* node) {
    if (!node) 
        return;

    std::queue<AVLNode*> q;
    q.push(root);

    while(!q.empty()) {
        AVLNode* n = q.front();
        q.pop();
        std::cout << n->data << " ";

        if(n->left)
            q.push(n->left);
        if(n->right)
            q.push(n->right);
    }
}

void AVLTree::levelorder() {
    levelorder(root);
    std::cout << std::endl;
}
