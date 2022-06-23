
/**
 * @file MergingRopes.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-19
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given N Ropes each having a different size, your task is to join the ropes together. The cost of joining two ropes of different sizes X, Y is (X+Y). Find the minimum cost to join all ropes together.
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int join_ropes(vector<int>A, int N)
{
    // Min heap
    priority_queue<int, vector<int>, greater<int> > min_heap(A,A+N);

    int cost = 0;

    while(min_heap.size() > 1)
    {
        int A = min_heap.top();
        min_heap.pop();

        int B = min_heap.top();
        min_heap.pop();

        cost += (A+B);

        min_heap.push(A+B);
    }  

    return cost;
}

int main()
{
    int N;
    cin>>N;

    int x;
    vector<int> A;

    for(int i=0;i<N;i++)
    {
        cin>>x;
        A.push_back(x);
    }

    

    cout<<join_ropes(A,N)<<endl;

    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 4
 * 4,3,2,6
 * 
 * OUTPUT
 * 29
 * 
 */


