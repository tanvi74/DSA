/**
 * @file QuickSort.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 * O(nlogn)
 * O(n2) - worst case
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

void quicksort(vector<int> &arr, int s, int e)
{
    if(s>=e)
        return;
    
    int p = partition(arr, s, e);
    quicksort(arr, s, p-1);
    quicksort(arr, p+1, e); 
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

    quicksort(A,0, N-1)

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