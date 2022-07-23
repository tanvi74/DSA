
/**
 * @file FlattenTree.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-08
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a BST, convert it into sorted linked list, right pointer should behave as next pointer for the linked list.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class node
{
    public: 
            int key;
            node* left;
            node* right;

            node(int d)
            {
                key = d;
                left = null; 
                right = null;
            }
};

node* insert(int x, node*root)
{
    if(root==NULL)
    {
        return new node(x);
    }

    if(key <= root->key)
    {
        root->left = insert(x, root->left);
    }
    else
    {
        root->right = insert(x, root->right);
    }

    return root;
}

void printInOrder(node*root)
{
    if(root==NULL)
    {
        return ;
    }

    printInOrder(root->left);
    cout<<root->key<<" ";
    printInOrder(root->right);
}

class LinkedList
{
    public:
            node * head;
            node * tail;
};

LinkedList tree2LL(node * root)
{
    LinkedList ll;

    // Base Case
    if(root==NULL)
    {
        ll.head = ll.tail = NULL;
        return ll;
    }

    // 4 cases
    if(root->left==NULL && root->right==NULL)
    {
        ll.head = ll.tail = root;
        return ll;
    }
    else if(root->left!=NULL && root->right==NULL)
    {
        LinkedList leftLL = tree2LL(root->left);
        leftLL.tail->right = root;

        l.head = leftLL.head;
        l.tail = root;
    }
    else if(root->left==NULL && root->right!=NULL)
    {
        LinkedList rightLL = tree2LL(root->right);
        root->right = rightLL.head;

        l.head = root;
        l.tail = rightLL.tail;
    }
    else if(root->left!=NULL && root->right!=NULL)
    {
        LinkedList leftLL = tree2LL(root->left);
        LinkedList rightLL = tree2LL(root->right);

        leftLL.tail->right = root;
        root->right = rightLL.head;

        l.head = leftLL.head;
        l.tail = rightLL.tail;
    }

    return l;
    
}

int main()
{
    node* root = NULL;
    int arr[] = {8,3,10,6,1,14,4,7,13}

    for(auto d : arr)
    {
        root = insert(d, root);
    }

    LinkedList l = tree2LL(root);
    node*temp = l.head;

    while(temp!=NULL)
    {
        cout<<temp->key<<" ";
        temp = temp->right; 
    }

    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 8,3,10,1,6,14,4,7,13
 *
 * OUTPUT
 * 1,3,4,6,7,8,10,13,14 
 * 
 */