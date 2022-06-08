/**
 * @file HeightBalancedTree.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-30
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a binary tree, check if it is of balanced height.
 * A non-empty binary tree T is balanced f:
 * 
 * -- left subtree of T is balnced 
 * -- right subtree of T is balnced
 * -- the difference between heights of left subtree and right subtree is not more than 1
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

pair<int,bool> isHeightBalanced(node* root)
{
    pair<int,bool> p, Left, Right;

    if(root==NULL)
    {
        p.first = 0;
        p.second = true;

        return p;
    }

    //Recursive case
    Left = isHeightBalanced(root->left);
    Right = isHeightBalanced(root->right);

    p.first = max(Left.first, Right.first) + 1;
    p.second = false;

    if(abs(Left.first - Right.first)<=1 and Left.second and Right.second)
    {
        p.second = true;
    }
    
    return p; 

}

int main()
{
    node* root = preOrderBuildTree();
    levelOrderPrint(root);

    pair<int, bool> ans = isHeightBalanced(root);

    if(ans.second)
        cout<<"TRUE"<<endl;
    else
        cout<<"FALSE"<<endl;

    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
 *
 * OUTPUT
 * 
 * 
 */