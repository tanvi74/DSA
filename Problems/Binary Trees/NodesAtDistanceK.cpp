
/**
 * @file NodesAtDistanceK.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-30
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a Binary Tree, a target node T. Find all nodes at distance K from given node, where K is also an integer from the input.
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

void printAtLevel(int k , node*root)
{
    if(k==0)
    {
        cout<<root->data<<endl;
        return;
    }

    if(root == NULL || k<0)
    { 
        return;
    }

    int k1 = k-1;
    printAtLevel(k1, root->left);
    printAtLevel(k1, root->right);

    return;
}

int printNodesAtDistanceK(node* root, node* target, int K)
{
    // base case
    if(root===NULL)
    {
        return -1;
    }

    // Reach the target node
    if(root == target)
    {
        printAtLevel(target,K);
        return 0;
    }

    // Other Case
    int DL = printNodesAtDistanceK(root->left, target, K);

    if(DL != -1)
    {
        // 2 cases

        // CASE 1: TO PRINT THE CURRENT NODE
        if(DL+1==K)
        {
            cout<<root->data<<endl;
        }
        else
        {
            printAtLevel(root->right,K-2-DL);
        }
        return 1+DL;
    }


    int DR = printNodesAtDistanceK(root->right, target, K);

    if(DR != -1)
    {
        // 2 cases

        // CASE 1: TO PRINT THE CURRENT NODE
        if(DR+1==K)
        {
            cout<<root->data<<endl;
        }
        else
        {
            printAtLevel(root->left,K-2-DR);
        }
        return 1+DR;
    }

    return -1;

}

int main()
{
    node* root = preOrderBuildTree();
    levelOrderPrint(root);

    int k;
    cin>>k;

    nodesAtDistanceK(root, )

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