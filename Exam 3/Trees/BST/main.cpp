#include <iostream>
#include "BST.h"

int main() {
    BinarySearchTree bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);

    std::cout << "Preorder traversal: ";
    bst.preorder();

    std::cout << "Inorder traversal: ";
    bst.inorder();

    std::cout << "Postorder traversal: ";
    bst.postorder();

    std::cout << "Levelorder traversal: ";
    bst.levelorder();

    return 0;
}
