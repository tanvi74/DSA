/** Given an array of N integers, and an number N denoting a target sum. Find two distinct integers that can pair up to rm target sum.
 * Let's assume there is only one such pair
 **/


#include<bits/stdc++.h>
using namespace std;

pair<int,int> pairs(vector<int>arr, int N)
{    
    pair<int,int>Ti;
    unordered_set<int>T;

    sort(arr.begin(),arr.end());

    for(int i=0;i<arr.size();i++)
    {
        int X = N-arr[i];
        if(T.find(X)!=T.end())
        {
            Ti.first = arr[i];
            Ti.second = X;
        }
        Ti.insert(arr[i]);
    }

    return Ti;
}

int main()
{
    int N, targetSum;
    cin>>N>>targetSum;

    vector<int>A;
    pair<int,int>ans;

    for(int i=0;i<N;i++)
        cin>>A[i];

    ans = pairs(A,targetSum);

    cout<<ans.first<<" "<<ans.second<<endl;
}

/**
 * @brief 
 * Input
 * 7 4
 * [10,5,2,3,-6,9,11]
 * 
 * 
 * Output
 * [10,-6]
 * 
 */