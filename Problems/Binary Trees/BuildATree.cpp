/**
 * @file LevelOrderPrint.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-12
 * 
 * @copyright Copyright (c) 2022
 * 
 * Building a binary tree from Level order Input, -1 represents NULL.
 * 
 * 
 */


#include <bits/stdc++.h>
using namespace std;

class Node
{
    public: 
            int data;
            Node* left;
            Node* right;

            Node(int d)
            {
                data = d;
                left = null; 
                right = null;
            }
};

Node* preOrderBuildTree()
{
    int d;
    cin>>d;
    
    if(d==-1)
        return NULL;

    Node* n = new Node(d);
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

int main()
{
    Node* rootPre = preOrderBuildTree();
    levelOrderPrint(rootPre);
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
 */

