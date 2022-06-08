
/**
 * @file MaxSubsetSum.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-30
 * 
 * @copyright Copyright (c) 2022
 * 
 * Find the largest sum of a subset of nodes in a binary tree, such that if a node is included in the sum then its parent and children must not be included in a subset sum.
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

class Pair{
    public: 
        int exc;
        int inc;
}


Pair maxSubsetSum(node*root)
{
    Pair p;
    if(root==NULL)
    {
       p.inc = p.exc = 0;
       return p; 
    }

    Pair left = maxSubsetSum(root->left);
    Pair right = maxSubsetSum(root->right);

    p.inc = root->data + left.exc + right.exc;
    p.exc = max(left.inc, left.exc) + max(right.inc, right.exc);

    return p;
}



int main()
{
    node* root = preOrderBuildTree();
    levelOrderPrint(root);

    Pair p = maxSubsetSum(root);

    cout<<max(p.inc, p.exc)<<endl;

    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
 *
 * OUTPUT
 * 18
 * 
 */