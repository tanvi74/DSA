
/**
 * @file ClosestInBST.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-06
 * 
 * @copyright Copyright (c) 2022
 * 
 * Function to find the integer closest to the given target value in the BST
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

int findClosestInBST(int key, node*root)
{
    int closest;
    int diff = INT_MAX;

    node*temp = root;

    while(temp!=NULL)
    {
        int curr_diff = abs(key-temp->key);

        if(curr_diff==0)
        {
            return temp->key;
        }

        if(curr_diff<diff)
        {
            diff = curr_diff;
            closest = temp->key;
        }

        if(temp->key<key)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left; 
        }
    }

    return closest;
}

int main()
{
    node* root = NULL;

    int arr[] = {8,3,10,6,1,14,4,7,13}

    for(auto d : arr)
    {
        root = insert(d);
    }
    
    cout<<findClosestInBST(12, root)
    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 8,3,10,6,1,14,4,7,13
 *
 * OUTPUT
 * 13
 * 
 */