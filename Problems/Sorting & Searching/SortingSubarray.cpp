/**
 * @file SortingSubarray.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * Write a function that takes in an array and returns two integers, denoting starting and ending indices of the smallest subarray in the input array that needs to be sorted in place so that the entire input is sorted.
 * If the input array is already sorted, return a pair [-1,-1].
 * 
 * 
 */


#include<bits/stdc++.h>
using namespace std;

pair<int,int> subarraySorting(vector<int> a){
    //Expected Optimal Complexity O(n) Time, O(1) Space
    //may be start with O(NLogN) and try to improve
    //complete this function

    int N = a.size();
    int maxN = 0;
    int minN = INT_MAX;
    
    int s,e;
    for (s = 0; s < N-1; s++)
    {
        if (a[s] > a[s+1])
        break;
    }
    
    if (s == N-1)
    {
        return{-1,-1};
    }
    
    for(e = N - 1; e > 0; e--)
    {
        if(a[e] < a[e-1])
        break;
    }

    maxN = a[s];
    minN = a[s];
    for(int i=s+1;i<=e;i++)
    {
            maxN = std::max(a[i],maxN);
            minN = std::min(a[i],minN);
    }
    
    for(int i = 0; i < s; i++)
    {
        if(a[i] > minN)
        {
            s = i;
            break;
        }    
    }
    
    for(int i = N-1; i >= e+1; i--)
    {
        if(a[i] < maxN)
        {
            e = i;
            break;
        }
    }

    return {s,e};
}

int main()
{
    int N,K;
    cin>>N;

    vector<int>A;
    for(int i=0;i<N;i++)
    {
        cin>>K;
        A.push_back(K);
    }

    pair<int,int>ans;
    ans = subarraySorting(A);

    cout<<ans.first<<" "<<ans.second<<endl;

    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 13
 * 0 2 4 7 10 11 7 12 13 14 16 19 29
 *
 * OUTPUT
 * 4 6
 * 
 */