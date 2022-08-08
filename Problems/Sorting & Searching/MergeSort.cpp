/**
 * @file MergeSort.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * O(nlogn)
 * 
 */


#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr, int s, int e)
{
    int i=s;
    int m = (s+e)/2;
    int j=m+1;

    vector<int> temp;

    while(i<=m && j<=e)
    {
        if(arr[i]<arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=m)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=e)
    {
        temp.push_back(arr[j]);
        j++;
    }

    int k=0;
    for(int i=s;i<=e;i++)
    {
        arr[i] = temp[k];
        k++;
    }

    return;
}

void mergeSort(vector<int>&arr, int s, int e)
{
    //Base case
    if(s>=e)
        return;

    int mid = (s+e)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    return merge(arr, s, e);
}

int main()
{
    int N,X;
    cin>>N;

    vector<int>A;
    for(int i=0;i<N;i++)
    {
        cin>>X;
        A.push_back(X);
    }

    mergeSort(A,0, N-1)

    for(int i=0;i<N;i++)
        cout<<A[i]<<" ";
    
    cout<<endl;
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 
 * OUTPUT
 * 
 * 
 */