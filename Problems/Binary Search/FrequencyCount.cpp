/**
 * @file FrequencyCount.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-19
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 * Given a sorted array which can contain repeated elements, and an element K, we need to find the frequency of given element.  
 * 
 */


#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int>array, int key)
{
    int s = 0;
    int e = array.size()-1;
    int ans = -1;

    while(s<e)
    {
        int mid = (s+e)/2;
        if(array[mid]==key)
        {
            ans = mid;
            e = mid-1;
        }
        else if(array[mid]<key)
        {
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }

    return ans;
}

int upper_bound(vector<int>array, int key)
{
    int s = 0;
    int e = array.size()-1;
    int ans = -1;

    while(s<e)
    {
        int mid = (s+e)/2;
        if(array[mid]==key)
        {
            ans = mid;
            s = mid+1;
        }
        else if(array[mid]<key)
        {
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }

    return ans;
}

int main()
{
    int N,key;
    cin>>N>>key;

    int X;
    vector<int> Ti;
    for(int i=0;i<N;i++)
    {
        cin>>X;
        Ti.push_back(X);
    }  

    int l = lower_bound(Ti,key);
    int u = lower_bound(Ti,key);

    cout<<u-l+1<<endl;

    // Can use STL;
    // cout<< upper_bound(Ti.begin(),Ti.end(),key) - lower_bound(Ti.begin(), Ti.end(), key)<<endl;


    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 13 2
 * 0 1 1 1 1 2 2 2 3 4 4 5 10
 * 
 *
 * OUTPUT
 * 1
 * 
 */