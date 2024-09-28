#include "isBTaBST.h"
#include "createNode.h"
#include "traversals.h"
int main()
{
    // Test Case 1: Empty Tree
    Node<int>* root1 = nullptr;
    cout << "Test Case 1: " << (bstCheck(root1) ? "Passed" : "Failed") << endl;

    // Test Case 2: Single Node
    Node<int>* root2 = createNode(10);
    cout << "Test Case 2: " << (bstCheck(root2) ? "Passed" : "Failed") << endl;
    delete root2;

    // Test Case 3: Valid BST
    Node<int>* root3 = createNode(10);
    root3->left = createNode(5);
    root3->right = createNode(15);
    root3->left->left = createNode(3);
    root3->left->right = createNode(7);
    root3->right->left = createNode(12);
    root3->right->right = createNode(18);
    cout << "Test Case 3: " << (bstCheck(root3) ? "Passed" : "Failed") << endl;
    delete root3->left->left;
    delete root3->left->right;
    delete root3->left;
    delete root3->right->left;
    delete root3->right->right;
    delete root3->right;
    delete root3;

    // Test Case 4: Invalid BST (Incorrect Left Child)
    Node<int>* root4 = createNode(10);
    root4->left = createNode(15);
    root4->right = createNode(5);
    cout << "Test Case 4: " << (bstCheck(root4) ? "Passed" : "Failed") << endl;
    delete root4->left;
    delete root4->right;
    delete root4;

    // Test Case 5: Invalid BST (Incorrect Right Child)
    Node<int>* root5 = createNode(10);
    root5->left = createNode(5);
    root5->right = createNode(15);
    root5->left->left = createNode(3);
    root5->left->right = createNode(7);
    root5->right->left = createNode(12);
    root5->right->right = createNode(8);
    cout << "Test Case 5: " << (bstCheck(root5) ? "Passed" : "Failed") << endl;
    delete root5->left->left;
    delete root5->left->right;
    delete root5->left;
    delete root5->right->left;
    delete root5->right->right;
    delete root5->right;
    delete root5;

    // Test Case 6: Duplicate Values
    Node<int>* root6 = createNode(10);
    root6->left = createNode(5);
    root6->right = createNode(15);
    root6->left->left = createNode(3);
    root6->left->right = createNode(5);
    root6->right->left = createNode(12);
    root6->right->right = createNode(18);
    cout << "Test Case 6: " << (bstCheck(root6) ? "Passed" : "Failed") << endl;
    delete root6->left->left;
    delete root6->left->right;
    delete root6->left;
    delete root6->right->left;
    delete root6->right->right;
    delete root6->right;
    delete root6;

    // Test Case 7: Larger Tree
    Node<int>* root7 = createNode(20);
    root7->left = createNode(10);
    root7->right = createNode(30);
    root7->left->left = createNode(5);
    root7->left->right = createNode(15);
    root7->left->left->left = createNode(3);
    root7->left->left->right = createNode(7);
    root7->left->right->right = createNode(17);
    root7->right->left = createNode(25);
    root7->right->right = createNode(35);
    root7->right->right->right = createNode(40);
    cout << "Test Case 7: " << (bstCheck(root7) ? "Passed" : "Failed") << endl;
    delete root7->left->left->left;
    delete root7->left->left->right;
    delete root7->left->left;
    delete root7->left->right->right;
    delete root7->left->right;
    delete root7->left;
    delete root7->right->left;
    delete root7->right->right->right;
    delete root7->right->right;
    delete root7->right;
    delete root7;

    // Test Case 8: Non-BST due to Deep Node
    Node<int>* root8 = createNode(20);
    root8->left = createNode(10);
    root8->right = createNode(30);
    root8->left->left = createNode(5);
    root8->left->right = createNode(25);
    root8->left->left->left = createNode(3);
    root8->left->left->right = createNode(7);
    root8->left->right->right = createNode(17);
    root8->right->left = createNode(25);
    root8->right->right = createNode(35);
    root8->right->right->right = createNode(40);
    cout << "Test Case 8: " << (bstCheck(root8) ? "Passed" : "Failed") << endl;
    delete root8->left->left->left;
    delete root8->left->left->right;
    delete root8->left->left;
    delete root8->left->right->right;
    delete root8->left->right;
    delete root8->left;
    delete root8->right->left;
    delete root8->right->right->right;
    delete root8->right->right;
    delete root8->right;
    delete root8;
    
return 0;
}
