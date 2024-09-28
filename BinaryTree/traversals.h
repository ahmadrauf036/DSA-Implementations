#include "treeNode.h"

template <typename T>
void inorder(Node<T>* root)
{
	if (root!=nullptr)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
	

}
template <typename T>
void preorder(Node<T>* root)
{
	if (root != nullptr)
	{
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}


}
template <typename T>
void postorder(Node<T>* root)
{
	if (root != nullptr)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
}

