/**
 * @file QuickSelect.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 * 
 * Write a function, that takes input an array of distinct integers and returns kth smallest int the array.
 * 
 * 
 */


#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int s, int e)
{
    int i = s-1;
    int pivot = a[e];

    for(int j=0;j<e;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i+1], a[e]);
    return i+1;

}

int quicksort(vector<int> &arr, int s, int e, int k)
{
    if(s>=e)
        return;
    
    int p = partition(arr, s, e);

    if(p>k)
        quicksort(arr, s, p-1,k);
    else if(p<k)
        quicksort(arr, p+1, e, k); 
    else
        return arr[p]
}

int main()
{
    int N,X,K;
    cin>>N>>K;

    vector<int>A;
    for(int i=0;i<N;i++)
    {
        cin>>X;
        A.push_back(X);
    }

    quicksort(A,0, N-1, K)

    for(int i=0;i<N;i++)
        cout<<A[i]<<" ";
    
    cout<<endl;
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 7 4
 * 10 5 2 0 7 6 4
 * 
 * OUTPUT
 * 5 
 * 
 */