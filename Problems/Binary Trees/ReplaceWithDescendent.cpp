
/**
 * @file ReplaceWithDescendent.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a binary tree, replace every node by sum of all its descendent, leave leaf nodes intact  
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class node
{
    public: 
            int data;
            node* left;
            node* right;

            node(int d)
            {
                data = d;
                left = null; 
                right = null;
            }
};

node* preOrderBuildTree()
{
    int d;
    cin>>d;
    
    if(d==-1)
        return NULL;

    node* n = new node(d);
    n->left = preOrderBuildTree();
    n->right = preOrderBuildTree();

    return n;
}

// Replace with descendent sum
int ReplaceWithSum(node* root)
{
    // base case
    if(root==NULL)
    {
        return 0;
    }

    if(root->left==NULL && root->right==NULL)
    {
        return root->data;
    }

    // recursive case
    int LS = ReplaceWithSum(root->left);
    int RS = ReplaceWithSum(root->right);
    int temp = root->data;
    root->data = LS+RS;

    return temp + root->data;
}

void levelOrderPrint(Node* root)
{
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp = q.front();
        if(temp==NULL)
        {
            cout<<endl;
            q.pop();

            // INSERT a new null for a new level
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            q.pop();
            cout<<temo->data<<" ";

            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node* root = preOrderBuildTree();
    levelOrderPrint(root);
    ReplaceWithSum(root);
    levelOrderPrint(root);
    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
 *
 * OUTPUT
 * 1
 * 2 3
 * 4 5 6
 * 7
 * 
 * 27
 * 16 6
 * 4 7 6 
 * 7
 * 
 */