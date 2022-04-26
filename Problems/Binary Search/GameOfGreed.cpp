/**
 * @file GameOfGreed.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-20
 * 
 * @copyright Copyright (c) 2022
 * 
 * You are playing a game with your 'k' friends. You have an array of N coins, at each index 'i' you have a coin with value a[i].
 * Your task is to divide the coins, among a group of K friends by doing consecutive segments (k-subarrays) of the array. 
 * Each friend will get a total sum of the coins of that subarray. Since all your friends are greedy, and they will pick up the largest k-1 segment and you will get the smallest segment. Find out the maximum value you can make by making an optimal paritition.
 * 
 * NOTE: The array may or may not be sorted.
 * 
 * HINTS: 
 * -> Can you apply recursion, Brute Force?
 * -> Can you apply Binary Search, is the search space is monotonic?
 * -> You can do binary search on search space(MIN,MAX) where MIN is the smallest coin denomination in the array, and MAX is the sum of all the coins in the array.   
 * 
 */


#include<bits/stdc++.h>
using namespace std;

int game_of_greed(vecotor<int>arr, int N, int key)
{
    
}

int main()
{
    int N,key,X;
    vecotor<int>arr;
    cin>>N>>key;

    for(int i=0;i<N;i++)
    {
        cin>>X;
        arr.push_back(X);
    }

    cout<<game_of_greed(arr, N, key)<<endl;

    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 4 3
 * 1 2 3 4
 *
 * OUTPUT
 * 3
 * 
 */