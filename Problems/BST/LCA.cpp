
/**
 * @file LCA.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-08
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a Binary Search Tree and values of two nodes that lie inside the tree, find the Lowest Common Ancestor (LCA).
 * Let T be a rooted tree. The lowest common ancestor between two nodes n1 and n2 is defined as the lowest node in T that has both n1 and n2 as descendants (where we allow a node to be a descendant of itself).
 * 
 * You may assume that both the values exist in the tree and are unique.
 * 
 * img: https://img-c.udemycdn.com/redactor/raw/coding_exercise_instructions/2021-05-13_17-13-11-ddb567945910a46b697931801f206c1f.png
 * 
 * For example - LCA of Node(9) and Node(25) is 12. 12 is closes to both 9 and 25, and in ancestor of both the nodes.
 * More examples
 * - LCA of Node(9) and Node(3) is 5.
 * - LCA of Node(9) and Node(12) is 12.
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