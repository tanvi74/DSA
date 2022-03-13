/**
 * @file CountSubarraysWithSum.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given an unsorted array of integers.
 * Find the number of subarrays having sum exactly equal to the number K.
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int cntSubarrays(vector<int> A,int K){
    //complete this method
    
    unordered_map<int,int>Ti;
    
    int currSum = 0;
    int cnt = 0;
    int N = A.size();
    
    for(int i=0;i<N;i++)
    {
        currSum += A[i];
        
        if(currSum == K)
            cnt++;
            
        if (Ti.find(currSum - K) != Ti.end())
            cnt += (Ti[currSum - K]);
            
        Ti[currSum]++;
         
    }
    return cnt;
}

int main()
{
    int N,K,X;
    cin>>N>>K;

    vector<int> A;
    for(int i=0;i<N;i++)
    {
        cin>>X;
        A.push_back(X);
    }

    cout<<cntSubarrays(A,K)<<endl;

    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 5 -10
 * 10 2 -2 -20 10
 * 
 * OUTPUT
 * 
 * 
 */