#include <iostream>
#include "AVL.h"

int main() {
    AVLTree avl;

    avl.insert(30);
    avl.insert(20);
    avl.insert(40);
    avl.insert(10);
    avl.insert(25);

    std::cout << "Preorder traversal: ";
    avl.preorder();

    std::cout << "Inorder traversal: ";
    avl.inorder();

    std::cout << "Postorder traversal: ";
    avl.postorder();

    std::cout << "Levelorder traversal: ";
    avl.levelorder();

    return 0;
}
