#include "treeNode.h"

template <typename T>
Node<T>* createNode(T data)
{
    Node<T>* newNode=new Node<T>;
    newNode->data=data;
    newNode->left=nullptr;
    newNode->right=nullptr;
    return newNode;
}