
/**
 * @file .cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given an array, find the maximum XOR that you can form by picking two numbers from the array.
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
            Node* left;
            Node* right;
};

class Trie
{
    Node* root;

    public:
            Trie()
            {
                root = new Node();
            }

            void insert(int n)
            {
                Node* temp = root;
                for(int i=31; i>=0; i--)
                {
                    int bit = (n>>i)&1;
                    if(bit==0)
                    {
                        if(temp->left == NULL)
                        {
                            temp->left = new Node();
                        }
                        temp = temp->left;
                    }
                    else
                    {
                        if(temp->right == NULL)
                        {
                            temp->right = new Node();
                        }
                        temp = temp->right;
                    }
                }
            }

            int max_xor_helper(int value)
            {
                int current_ans = 0;
                Node* temp = root;

                for(int j = 31;j>=0;j--)
                {
                    int bit = (value>>j)&1;

                    if(bit==0)
                    {
                        if(temp->right != NULL)
                        {
                            temp = temp->right;
                            current_ans += (1<<j);
                        }
                        else
                        {
                            temp = temp->left;
                        }
                    }
                    else
                    {
                        if(temp->left != NULL)
                        {
                            temp = temp->left;
                            current_ans += (1<<j);
                        }
                        else
                        {
                            temp = temp->right;
                        }
                    }
                }
                return current_ans;
            }

            int max_xor(vector<int>input, int n)
            {
                int max_xor = 0;

                for(int i=0;i<n;i++)
                {
                    int value = input[i];
                    insert(value);
                    int current_xor = max_xor_helper(value);
                    max_xor = max(current_xor, max_xor);
                }

                return max_xor;
            }   
};

int main()
{
    int N;
    cin>>N;

    int x;
    vector<int> arr;

    for(int i=0;i<N;i++)
    {
        cin>>x;
        arr.push_back(x);
    }

    Trie T;

    cout<<T.max_xor(arr,N)<<endl;


    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 6
 * 3 10 5 25 9 2
 * 
 * OUTPUT
 * 28
 * 
 */


