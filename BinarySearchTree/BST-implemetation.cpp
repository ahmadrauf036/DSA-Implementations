
#include "BST.h"
#include "BinaryTree/traversals.h"


int main()
{
	

// Test insert
    Node<int>* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    cout << "height: "<<height(root)<<endl;

    cout << "Insert test completed.\n";
	preorder(root);cout<<endl;
	inorder(root);cout<<endl;
	postorder(root);cout<<endl;


// Test findMin
    root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    cout << "height: "<<height(root)<<endl;

    Node<int>* minNode = findMin(root);
    std::cout << "Minimum value: " << minNode->data << std::endl; // Expected: 20


// Test findMax
	root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    cout << "height: "<<height(root)<<endl;

    Node<int>* maxNode = findMax(root);
    cout << "Maximum value: " << maxNode->data << std::endl; // Expected: 80


// Test deleteNode
    root = nullptr;
    root = insert(root, 50);
	insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    cout << "height: "<<height(root)<<endl;

    deleteNode(root, 20);
	cout<<"Test 1:"<<endl;
	preorder(root);cout<<endl;
	inorder(root);cout<<endl;
	postorder(root);cout<<endl;
    cout << "height: "<<height(root)<<endl;

    deleteNode(root, 30);
	cout<<"Test 2:"<<endl;
	preorder(root);cout<<endl;
	inorder(root);cout<<endl;
	postorder(root);cout<<endl;

    cout << "height: "<<height(root)<<endl;

    deleteNode(root, 50);
	cout<<"Test 3:"<<endl;
	preorder(root);cout<<endl;
	inorder(root);cout<<endl;
	postorder(root);cout<<endl;
    cout << "height: "<<height(root)<<endl;


	root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    root = deleteNode(root, 20);
    cout << "height: "<<height(root)<<endl;

	cout<<"Test 4:"<<endl;
	preorder(root);cout<<endl;
	inorder(root);cout<<endl;
	postorder(root);cout<<endl;
    root = deleteNode(root, 30);
	
	cout<<"Test 5:"<<endl;
    root = deleteNode(root, 50);
    // Expected tree after deletion of 50:
    //        60
    //       /  \
    //      40   70
    //             \
    //             80
	preorder(root);cout<<endl;
	inorder(root);cout<<endl;
	postorder(root);cout<<endl;
	
	cout<<"Test 6:"<<endl;
    root = deleteNode(root, 70);
	preorder(root);cout<<endl;
	inorder(root);cout<<endl;
	postorder(root);cout<<endl;

	cout<<"Test 7:"<<endl;
    root = deleteNode(root, 60);
	preorder(root);cout<<endl;
	inorder(root);cout<<endl;
	postorder(root);cout<<endl;
   
	cout<<"Test 8:"<<endl;
    root = deleteNode(root, 40);
	preorder(root);cout<<endl;
	inorder(root);cout<<endl;
	postorder(root);cout<<endl;

	cout<<"Test 9:"<<endl;
    root = deleteNode(root, 80);
	preorder(root);cout<<endl;
	inorder(root);cout<<endl;
	postorder(root);cout<<endl;
    if (root == nullptr) {
        std::cout << "Tree is empty after deleting all nodes.\n";
    } else {
        std::cout << "Error: Tree is not empty after deleting all nodes.\n";
    }
    root = nullptr;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 20);
    root = insert(root, 7);
    root = insert(root, 25);
    root = insert(root, 17);
    root = insert(root, 18);
    root = insert(root, 16);
    cout<<height(root)<<endl;
    levelTraversal(root);

	return 0;
}