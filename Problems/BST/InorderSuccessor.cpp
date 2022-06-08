
/**
 * @file InorderSuccessor.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-08
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a BST. Find the inorder successor of a given target node.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class node
{
    public: 
            int key;
            node* left;
            node* right;

            node(int d)
            {
                key = d;
                left = null; 
                right = null;
            }
};

node* insert(int x, node*root)
{
    if(root==NULL)
    {
        return new node(x);
    }

    if(key <= root->key)
    {
        root->left = insert(x, root->left);
    }
    else
    {
        root->right = insert(x, root->right);
    }

    return root;
}

void printInOrder(node*root)
{
    if(root==NULL)
    {
        return ;
    }

    printInOrder(root->left);
    cout<<root->key<<" ";
    printInOrder(root->right);
}

node * inorderSucc(node*root, node*target)
{
    //IF right subtree exist
    if(target->right!=NULL)
    {
        node*temp = target->right;
        while(temp->left!=NULL)
        {
            temp = temp->left
        }

        return temp;
    }

    // Otherwise
    node*temp = root;
    node*succ = NULL;

    while(temp!=NULL)
    {
        if(temp->key>target->key)
        {
            succ = temp;
            temp = temp->left;
        }
        else if(temp->key>target->key)
        {
            temp = temp->right;
        }
        else
        {
            break;
        }
    }

    return temp;
}

int main()
{
    node* root = NULL;
    int arr[] = {8,3,10,6,1,14,4,7,13}

    for(auto d : arr)
    {
        root = insert(d,root);
    }

    node*t1 = root->left->right->right;
    node*t2 = root->right;

    cout<<inorderSucc(root,t1)->key<<endl;
    cout<<inorderSucc(root,t2)->key<<endl;

    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 8,3,10,1,6,14,4,7,13
 *
 * OUTPUT
 * 8
 * 13
 * 
 */