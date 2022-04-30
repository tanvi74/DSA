/**
 * @file AngryBirds.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-20
 * 
 * @copyright Copyright (c) 2022
 * 
 * There is a long wire along at straight line, which contains N birds nest at position x1,x2,x3,....xN.
 * There are B(B<=N) birds, which become angry towards each other once put into a nest. To put the birds from hurting each other you want to assign birds to nests such that the minimum distance between any two bird is as large as possible. What is the largest minimum distance?  
 * 
 */


#include<bits/stdc++.h>
using namespace std;

bool canPlaceBirds(vector<int>arr, int N, int B, int mid)
{
    int birds = 1;
    int location = arr[0];

    for(int i=1;i<N;i++)
    {
        if(arr[i]-location >= mid)
        {
            location = arr[i];
            birds++;

            if(birds == B)
                return true;
        }
    }

    return false;
}

int angry_bird(vector<int>arr, int N, int B)
{
    // Binary search
    int s = 0;
    int e = arr[N-1]-arr[0];
    int ans = -1;

    while(s<=e)
    {
        int mid = (s+e)/2;
        
        bool canPlace = canPlaceBirds(arr, N, B, mid);
        
        if(canPlace)
        {
            ans = mid;
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
    int N,B,X;
    cin>>N>>B;
    
    vector<int>arr;
    for(int i=0;i<N;i++)
    {
        cin>>X;
        arr.push_back(X);
    }

    sort(arr.begin(), arr.end());
    cout<<angry_bird(arr,N,B)<<endl;

    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 5 3
 * 1 2 4 8 9
 *
 * OUTPUT
 * 3
 * 
 */