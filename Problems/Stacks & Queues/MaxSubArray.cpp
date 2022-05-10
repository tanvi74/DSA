/**
 * @file MaxSubArray.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-09
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given an array and an integer K, find the maximum for each and every contiguous subarray of size K. 
 * 
 */


#include<bits/stdc++.h>
using namespace std;

void maxSubArray(vector<int>arr, int N, int K)
{
    // Algorithm
    dequeue<int> Q(K);

    // For first k elements
    for(int i=0;i<K;i++)
    {
        while(!Q.empty() && arr[i]>=arr[Q.back()])
        {
            Q.pop_back();
        }

        Q.push_back(i);
    }

    // For Remaining elements
    for(int i=K;i<N;i++)
    {
        cout<<a[Q.front()]<<" ";
        // Contaction from the front -> Removing indices which are not in window
        while(!Q.empty() && Q.front()<=i-K)
        {
            Q.pop_front();
        }
        while(!Q.empty() && arr[i]>=arr[Q.back()])
        {
            Q.pop_back();
        }
        Q.push_back(i);
    }

    cout<<endl;
}

int main()
{
    int N,K,x;
    cin>>N>>K;
    
    vector<int> A;
    for(int i=0;i<N;i++)
    {
        cin>>x;
        A.push_back(x);
    }

    vector<int>ans = maxSubArray(A,N,K);

    for(auto itr : ans)
    {
        cout<<itr<<" ";
    }

    cout<<endl;
    
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 9 3
 * 1 2 3 1 4 5 2 3 6
 *
 * OUTPUT
 * 3 3 4 5 5 5 6
 * 
 */