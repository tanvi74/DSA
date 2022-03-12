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



int main()
{
    int N, K;
    cin>>N>>K;

    int A[N];

    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }

    vector<vector<int>>ans = 

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