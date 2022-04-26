/**
 * @file RotatedSearch.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-20
 * 
 * @copyright Copyright (c) 2022
 * 
 * Write a function that takes input an sorted array of distinct integers, which is rotated about a pivot point and finds the index of any given element
 * 
 */


#include<bits/stdc++.h>
using namespace std;

int rotatedSearch(vector<int> arr, int key)
{
    int n = arr.size();
    int s = 0;
    int e = n-1;

    while(s<=e)
    {
        int mid = (s+e)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[s]<=arr[mid])
        {
            //left
            if(arr[s]<key && arr[mid]>=key)
            {
                e = mid-1;
            }
            else
            {
                s = mid+1;
            }
        }
        else
        {
            if(arr[mid]<=key && arr[e]>=key)
            {
                s = mid+1;
            }
            else
            {
                e = mid-1;
            }
        }

    }

    return -1;
}

int main()
{
    int N, key;
    cin>>N>>key;

    int X;
    vector<int> Ti;
    for(int i=0;i<N;i++)
    {
        cin>>X;
        Ti.push_back(X);
    }  

    cout<<rotatedSearch(Ti, key)<<endl;
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 9 4
 * 7 9 10 1 2 3 4 5 6
 *
 * OUTPUT
 * 6
 * 
 */