/**
 * @file SubsetsSumToX.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-14
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equals to given sum.
 * 
 */


#include<bits/stdc++.h>
using namespace std;

int countSubsets(vector<int>arr, int n, int i, int X)
{
    // Base Case
    if(i==n)
    {
        if(X==0)
            return 1;
        return 0;
    }

    // Recursive Case
    int inc = countSubsets(arr, n, i+1, X-arr[i]);
    int dec = countSubsets(arr, n, i+1, X);

    return inc+dec;
}

int main()
{
    int N, sum, x;
    cin>>N>>sum;

    vector<int> arr;
    for(int i=0;i<N;i++)
    {
        cin>>x;
        arr.push_back(x);
    }

    cout<<countSubsets(arr,N,0,sum)<<endl;
    

    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 6 16
 * 10 12 15 6 19 20
 *
 * OUTPUT
 * Yes
 * 
 */
