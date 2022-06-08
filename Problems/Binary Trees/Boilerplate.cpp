/**
 * @file Boilerplate.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 * Preorder : Node, left, right
 * Postorder: Left, right, node
 * Inorder: left, node, right
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

Node* postOrderBuildTree()
{
    int d;
    cin>>d;
    
    if(d==-1)
        return NULL;

    n->left = postOrderBuildTree();
    n->right = postOrderBuildTree();
    Node* n = new Node(d);

    return n;
}

Node* inOrderBuildTree()
{
    int d;
    cin>>d;
    
    if(d==-1)
        return NULL;

    n->left = inOrderBuildTree();
    Node* n = new Node(d);
    n->right = inOrderBuildTree();

    return n;
}

int main()
{
    Node* rootPre = preOrderBuildTree();
    Node* rootPost = postOrderBuildTree();
    Node* rootIn = inOrderBuildTree();
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
 *
 * OUTPUT
 * yes
 * 
 */