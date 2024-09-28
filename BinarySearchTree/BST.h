#include "treeNode.h"
using namespace std;
template <typename T>
Node<T>* insert(Node<T>* root,T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	if (root == nullptr)
	{
		root = newNode;
		return root;
	}
	else if(root->data<data)
	{
		root->right= insert(root->right, data);
		return root;
	}
	else if (root->data > data)
	{

		root->left= insert(root->left, data);
		return root;
	}
}
template <typename T>
Node<T>* findMin(Node<T>* root)
{
	while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}
template <typename T>
Node<T>* findMax(Node<T>* root)
{
	while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}
template <typename T>
Node<T>* deleteNode(Node<T>* root,T key)
{
	if (root == nullptr)
	{
		return root;
	}
	else if(root->data<key)
	{
		root->right= deleteNode(root->right, key);
		return root;
	}
	else if (root->data > key)
	{

		root->left= deleteNode(root->left, key);
		return root;
	}
	else if(root->data==key)
	{
		if(root->left==nullptr && root->right==nullptr)
		{
			delete root;
			root=nullptr;
			return root;
		}
		else if (root->left == nullptr) {
            Node<T>* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            Node<T>* temp = root;
            root = root->left;
            delete temp;
        } else {
            Node<T>* temp = findMax(root->left); // or use findMin(root->right)
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
		}
	}
	return root;
}
template <typename T>
int height(Node<T>* root)
{
	int lh=0,rh=0;
	if(root==nullptr)
	{
		return 0;
	}
	lh=height(root->left)+1;
	rh=height(root->right)+1;
	return (lh>rh?lh:rh);
}
template <typename T>
Node<T>* levelTraversal(Node<T>* root)
{
	int h=height(root);
	for (int i = 0; i < h; i++)
	{
		printLevel(root,i);
	}

}
template <typename T>
void printLevel(Node<T>* root, int level)
{
	if(root==nullptr)
	{
		return;
	}
	if(level==0)
	{
		cout<<root->data<<" ";
		return;
	}
	if(level>0)
	{
		printLevel(root->left,level-1);
		printLevel(root->right,level-1);
	}
}