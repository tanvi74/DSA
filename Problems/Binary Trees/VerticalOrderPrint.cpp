
/**
 * @file VerticalOrderPrint.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-01
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a Binary Tree, we need to print it vertically
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

void traverse(map<int,vector<int>> &m, node*tree, int d)
{
    if(root==NULL)
    {
        return;
    }

    m[d].push_back(root->data);
    traverse(m,root->left, d-1);
    traverse(m,root->right, d+1);
}

void verticalOrderPrint(node*root)
{
    map<int,vector<int>> m;
    int d = 0;

    traverse(m, root, d);

    for(auto p:m)
    {
        int key = p.first;
        vector<int> vect = p.second;

        for(auto v: vect)
        {
            cout<<v<<" ";
        }

        cout<<endl;
    }

    return;
}



int main()
{
    node* root = preOrderBuildTree();
    levelOrderPrint(root);

    verticalOrderPrint(root)

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