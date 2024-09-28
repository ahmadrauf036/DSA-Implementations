#include <iostream>
#include "avlTree.h"
using namespace std;

int main() {
    AVLTree tree;

   /* tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);*/

    cout << "Inorder traversal: ";
    tree.inorder();

    cout << "Preorder traversal: ";
    tree.preorder();

    cout << "Postorder traversal: ";
    tree.postorder();

    cout << "Height of tree: " << tree.calculateHeight() << endl;

    cout << "Diameter of tree: " << tree.calculateDiameter() << endl;

    cout << "Minimum value: " << tree.findMin() << endl;

    cout << "Maximum value: " << tree.findMax() << endl;

    int searchKey = 30;
    cout << "Successor of " << searchKey << ": " << tree.successor(searchKey) << endl;

    cout << "Predecessor of " << searchKey << ": " << tree.predecessor(searchKey) << endl;

    return 0;
}



#include <iostream>
using namespace std;


