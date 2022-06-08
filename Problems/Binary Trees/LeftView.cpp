
/**
 * @file LeftView.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-01
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a Binary Tree, print left view of it. Left view of Binary Tree is set of nodes that are visible when a tree visited from the left side. Refer below examples.
 * Return the answer in a vector of integers.
 * 
 * e.g.
 * 
 *                      1
 *                     / \
 *                    2   3
 *                   / \   \
 *                  4   5   6
 * 
 *      o/p    1 2 4 
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

int maxLevel = 0;

void helperFunc(Node*root, vector<int>&V, int label)
{
    if(root==NULL)
    {
        return;
    }
    
    if(maxLevel<label)
    {
        V.push_back(root->key);
        maxLevel = label;
    }
    
    helperFunc(root->left, V, label+1);
    helperFunc(root->right, V, label+1);
}

vector<int> leftView(Node * root)
{
    maxLevel = 0;    
    vector<int>ans;
    helperFunc(root, ans, 1);
    
    return ans;
    
}

int main()
{
    node* root = preOrderBuildTree();
    vector<int> ans = leftView(root);

    for(auto d:ans)
        cout<<d<<" ";

    cout<<endl;

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