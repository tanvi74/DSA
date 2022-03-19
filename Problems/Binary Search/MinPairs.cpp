/**
 * @file MinPairs.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-20
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given two non-empty arrays, find the pair of numbers (one from each array) whose absolute difference is minimum. Print the any one pair with the smallest difference.
 * 
 */


#include<bits/stdc++.h>
using namespace std;

void min_pair(vector<int>A, vector<int>B)
{
    // Sorting the second Array
    sort(B.begin(),B.end());

    int p1, p2;
    int dif = __INT_MAX__;

    // Iterating on first array and finding the lowerbound of it in second array
    for(auto x : A)
    {
        auto lb = lower_bound(B.begin(),B.end(),x)-B.begin();

        // left
        if(lb >= 1 && x-B[lb-1] < diff)
        {
            diff = x-B[lb-1];
            p1 = x;
            p2 = B[lb-1];
        }

        // right
        if(lb!=B.size() && B[lb]-x<diff)
        {
            diff = B[lb]-x;
            p1 = x;
            p2 = B[lb];
        }

    }
    cout<<p1<<" "<<p2<<endl;
}

int main()
{
    int N,X;
    cin>>N;

    vector<int>A, B;

    for(int i=0;i<N;i++)
    {
        cin>>X;
        A.push_back(X);
    }

    for(int i=0;i<N;i++)
    {
        cin>>X;
        B.push_back(X);
    }

    min_pair(A,B);

    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 5
 * -1 5 10 20 3
 * 26 134 135 15 17 
 *
 * OUTPUT
 * 20 17
 * 
 */