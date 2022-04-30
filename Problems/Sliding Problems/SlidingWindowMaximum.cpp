/**
 * @file SlidingWindowMaximum.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given an array of integers and an integer K, returns a vector of containing maximum for each and every contiguous subarray of size k.
 * 
 * Constraints
 *      -> -10000<=A[i]<=10000
 *      -> 0<i<100
 *      -< k>0
 */


#include<bits/stdc++.h>
using namespace std;

vector<int> maxInWindow(vector<int> input,int k){
    
    int N = input.size();
    
    deque<int>Q;
    vector<int>ans;
    
    int i=0;
    for(;i<k;i++)
    {
        while(!Q.empty() && input[i]>=input[Q.back()])
            Q.pop_back();
        
        Q.push_back(i);
        
    }
    
    for(;i<N;i++)
    {
        ans.push_back(input[Q.front()]);
        
        while(!Q.empty() && Q.front()<=i-k)
            Q.pop_front();
            
        while(!Q.empty() && input[i]>=input[Q.back()])
            Q.pop_back();
        
        Q.push_back(i);
        
    }
    
    ans.push_back(input[Q.front()]);
    
    return ans;
}

int main()
{
    int N,K;
    cin>>N>>K;
    
    vector<int>A;
    int x;
    for(int i=0;i<N;i++)
    {
        cin>>x;
        A.push_back(x);
    }
        
    vector<int>ans = maxInWindow(A,K);
    
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
        
    
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 9 3
 * 1 2 3 1 4 5 2 3 6

 * OUTPUT
 * 3 3 4 5 5 5 6 
 * 
 */