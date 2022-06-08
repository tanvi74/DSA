/**
 * @file LevelOrderPrint.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * Building a tree from level order.
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

Node* levelOrderBuild()
{
    int d;
    cin>>d;

    Node* root = new Node(d);
    queue<Node*> q;

    q.push(root);

    while(!q.empty)
    {
        Node* current = q.front();
        q.pop();

        int c1, c2;
        cin>>c1>>c2;

        if(c1!=-1)
        {
            current->left = new Node(c1);
            q.push(current->left);
        }

        if(c2!=-1)
        {
            current->right = new Node(c2);
            q.push(current->right);
        }
    }

    return root;
}

int main()
{
    Node* rootPre = levelOrderBuild();
    
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

