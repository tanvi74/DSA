/**
 * @file Ladders.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a ladder containing N steps, you can take a jump of 1,2, or 3 at each step. Find the number of ways to climb a ladder.
 * 
 */


#include<bits/stdc++.h>
using namespace std;

int ladder(int N, int dp[])
{
    // Base Case
    if(N<0)
        return 0;
    
    if(N==0)
        return 1;
    
    if(dp[N] != -1 ){
        return dp[N] ;
    }
    
    dp[N] = ladder(N-1,dp) + ladder(N-2,dp) + ladder(N-3,dp);

    return dp[N];
}

int main()
{
    int N;
    cin>>N;

    int dp[N+1] ;
    memset(dp, -1, sizeof dp) ;
    
    cout<<ladder(N,dp)<<endl;
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 4
 *
 * OUTPUT
 * 7
 * 
 */