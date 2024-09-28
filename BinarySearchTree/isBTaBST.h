#include "treeNode.h"
using namespace std;
template <typename T>
bool bstCheck(Node<T>* root)
{
    bool prev=1;
    if(root==nullptr)
    {
        return 1;
    }
    else
    {
        if(root->left!=nullptr){
            if(root->data==root->left->data)
            {
                return 0;
            }
            if(root->left->data<root->data)
            {
               prev = bstCheck(root->left);
            }
            else
            {
                return 0;
            }      
        }
        if(root->right!=nullptr) 
        {
            if(root->data==root->right->data)
            {
                return 0;
            }
            if(root->right->data > root->data)
            {
               prev= bstCheck(root->right);
            }
            else
            {
                return 0;
            }
        }
        
    }
    if(!prev)
        return 0;
    return 1;
}
