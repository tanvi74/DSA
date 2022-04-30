/**
 * @file InversionCount.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 * Given an array of integers, you need to count total number of inversions.
 * Inversion -> Two element, a[i], a[j] forms an inversion, if a[i]>a[j] and i<j
 * 
 */


#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>&arr, int s, int e)
{
    int i=s;
    int mid = (s+e)/2;
    int j=m+1;

    vector<int> temp;

    int cnt = 0;
    while(i<=m && j<=e)
    {
        if(arr[i]<arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            cnt += (mid-i+1); 
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

    return cnt;
}

int inversion_count(vector<int>&arr, int s, int e)
{
    //Base case
    if(s>=e)
        return 0;

    int mid = (s+e)/2;
    int C1 = mergeSort(arr, s, mid);
    int C2 = mergeSort(arr, mid+1, e);
    int C3 = merge(arr, s, e);
    return C1+C2+C3;
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

    cout<<inversion_count(A,0, N-1)<<endl;
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 5
 * 0 5 2 3 1
 * 
 * OUTPUT
 * 5
 * 
 */