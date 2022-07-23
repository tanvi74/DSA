
/**
 * @file isBST.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-08
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a binary tree, check if it is BST or not.
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

bool isPresent(Node * root,int key)
{
    if(root == NULL)
    {
        return false;
    }
    
    if(root->key == key)
    {
        return true;
    }
    
    if(key < root->key)
    {
        isPresent(root->left, key);
    }
    else
    {
        isPresent(root->right, key);
    }
}

int main()
{
    node* root = NULL;
    int arr[] = {8,3,10,6,1,14,4,7,13}

    for(auto d : arr)
    {
        root = insert(d,root);
    }

    printInOrder(root);

    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 8,3,10,1,6,14,4,7,13
 *
 * OUTPUT
 * 1,3,4,6,7,8,10,13,14
 * 
 */