#ifndef AVL_H
#define AVL_H

class AVLNode {
public:
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int value);
};

class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode* node);
    int getBalance(AVLNode* node);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* insert(AVLNode* node, int value);
    void preorder(AVLNode* node);
    void inorder(AVLNode* node);
    void postorder(AVLNode* node);
    void levelorder(AVLNode* node);
    void destroy(AVLNode* node);

public:
    AVLTree();
    ~AVLTree();

    void insert(int value);
    void preorder();
    void inorder();
    void postorder();
    void levelorder();
};

#endif
