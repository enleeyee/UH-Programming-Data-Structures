#ifndef BST_H
#define BST_H

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value);
};

class BinarySearchTree {
private:
    Node* root;

    void insert(Node*& node, int value);
    void preorder(Node* node);
    void inorder(Node* node);
    void postorder(Node* node);
    void levelorder(Node* node);
    void destroy(Node* node);

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int value);
    void preorder();
    void inorder();
    void postorder();
    void levelorder();
};

#endif
