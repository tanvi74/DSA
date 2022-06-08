
/**
 * @file MinHeightBST.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-06
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a sorted array, construct a BST of minimum height. 
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

node* sortedArrayToBST(vector<int> arr, int start, int end) 
{ 
    if (start > end) 
        return NULL; 
  
    int mid = (start + end)/2; 
    node *root = new node(arr[mid]); 
  
    root->left = sortedArrayToBST(arr, start, mid - 1); 
    root->right = sortedArrayToBST(arr, mid + 1, end); 
 
    return root; 
} 

int main()
{
    node* root = NULL;
    int arr[] = {8,3,10,6,1,14,4,7,13}

    sortedArrayToBST(arr, 0, arr.length-1);

    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 8,3,10,6,1,14,4,7,13
 *
 * OUTPUT
 * 1,3,4,6,7,8,10,13,14
 * 
 */