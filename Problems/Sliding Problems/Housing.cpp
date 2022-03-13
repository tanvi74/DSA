/**
 * @file Housing.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * Along one side of the road there is a sequence of vacant plots of land. 
 * Each plot has a different area(non-zero). So, the areas form a sequence A[0], A[1], A[2],...,A[N],
 * You want to buy K acres of land for your house.
 * You want to find all segments of contiguous plots (ie a subsequence) of whose sum is exactly K. 
 * 
 */


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> housing(int *A, int N, int K)
{
    int i=0;
    int j=0;
    int cn = 0;

    vector<vector<int>>ans;

    while(j<N)
    {
        cn += A[j];
        j++;

        while(cn>K && i<j)
        {
            cn = cn-A[i];
            i++;
        }

        if(cn==K)
        {
            ans.push_back({i,j-1});
        }
    }

    return ans;
}


int main()
{
    int N, K;
    cin>>N>>K;

    int A[N];

    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }

    vector<vector<int>>ans = housing(A, N, K)

    for(int i=0;i<ans.size();i++)
        cout<<ans[i][0]<<"-"<<ans[i][1]<<endl;

    int minX = __INT16_MAX__;
    pair<int,int> minW;

    // smallest window
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i][1]-ans[i][0] < minX)
        {
            minX = ans[i][1]-ans[i][0];
            minW.first = ans[i][0];
            minW.second = ans[i][1];
        }
    } 

    cout<<"Smallest Window - "<<minW.first<<" "<<minW.second<<endl


    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 11 8
 * 1 3 2 1 4 1 3 2 1 1 2
 * 
 * 
 * OUTPUT
 * 2 5 
 * 4 6
 * 5 9
 * 
 */