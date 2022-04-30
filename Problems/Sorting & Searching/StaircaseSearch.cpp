/**
 * @file StaircaseSearch.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * You are given a M*N matrix which is row wise and column wise sorted. You have to search an index of a given integer K in the matrix.
 * 
 * Input Format
 *      function contains an integer M, integer N, 2D vector containing integers and an integer K.
 * 
 * Output Format
 *      Returns a pair of integers {x,y} 
 * 
 */


#include<bits/stdc++.h>
using namespace std;

pair<int,int> search(int M, int N, vector<vector<int>> V, int K){
    //write your code here.
    
    pair<int,int>ans;
    int j = N-1;
    int k = 0;
    
    for(int i=0;i<M;i++)
    {
        int mid = (j+k)/2;
        if(V[i][mid]==K)
        {
            ans.first = i;
            ans.second = mid;
        }
        else if(V[i][mid]<K)
        {
            k = mid+1;
        }
        else 
        {
            j = mid-1;
        }
    }
    
    return ans;
    
}

int main()
{
    int M, N, K, X;
    cin>>N>>M>>K;

    vector<vector<int>>A;

    for(int i=0;i<M;i++)
    {
        vector<int>S;
        for(int j=0;j<N;j++)
        {
            cin>>X;
            S.push_back(X);
        }
        A.push_back(S);
    }

    pair<int,int>ans = search(M,N,A,K);
    cout<<ans.first<<" "<<ans.second<<endl;

    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 3 3 10
 * 1 4 9
 * 2 5 10
 * 6 7 11
 * 
 * 
 * 
 * OUTPUT
 * 1 2
 * 
 * 
 */