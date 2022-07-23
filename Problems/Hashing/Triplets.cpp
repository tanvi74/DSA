
/**
 * @file Triplets.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-23
 * 
 * @copyright Copyright (c) 2022
 * 
 * You are given an array and you need to count number of triplets with indices i,j,k such that the number of elements at those indices are in geometric progression for a given common ratio r and i<j<k
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int count_triplets(vector<int>arr, int R)
{
    int n = arr.size();
    unordered_map<long,long>left,right;

    // Initialize the right map
    for(auto x:arr)
    {
        right[x]++;
        left[x]=0;
    }

    // compute by iterating left to right
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        right[arr[i]]--;

        if(arr[i]%R == 0)
        {
            long a = arr[i]/R;
            long b = arr[i];
            long c = arr[i]*R;

            ans += left[a]*right[c];
        }

        left[arr[i]]++;
        
    }

    return ans;
}

int main()
{
    int N,R;
    cin>>N>>R;

    vector<int> arr(N,0);

    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }

    cout<<count_triplets(arr,R)<<endl;

    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 6 4 
 * 1 16 4 16 64 16
 * 
 * OUTPUT
 * 3
 * 
 */


