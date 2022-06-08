/**
 * @file TreeDiameter.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * Find the diameter of the binary tree, diameter is defined as the largest distance between any two nodes of the tree.
 * 
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

// Helper function
int height(node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int h1 = height(root->left);
    int h2 = height(root->right);

    return 1 + max(h1,h2);
}

// Diameter function
// Time Complexity: O(N2)
int diameter(node* root)
{
    // base case
    if(root==NULL)
    {
        return 0;
    }

    // recursive case
    int d1 = height(root->left) + height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);

    return max(d1, max(d2,d3));

}

// _________Optimizes code
// Time complexity: O(N )

class HDPair
{
    public:
            int height;
            int diameter;
};

HDPair optDiameter(node* root)
{
    HDPair p;
    if(root == NULL)
    {
        p.height = 0;
        p.diameter = 0;
        return p;
    }

    HDPair Left = optDiameter(root->left);
    HDPair Right = optDiameter(root->right);

    p.height = max(Left.height, Right.height) + 1;

    int D1 = Left.height + Right.height;
    int D2 = Left.diameter;
    int D3 = Right.diameter;  

    p.diameter =  max(D1, max(D2,D3));

    return p;

}

int main()
{
    node* rootPre = preOrderBuildTree();
    cout<< diameter(rootPre) <<endl; 
    cout<< optDiameter(rootPre).diameter << endl;
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
 *
 * OUTPUT
 * 5 
 * 
 */