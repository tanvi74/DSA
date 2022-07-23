
/**
 * @file SortingHeaps.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * Making maxHeap and minheap and custom comparator
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Compare
{
    public: 
            bool operator()(int a, int b)   // function overloading
            {
                return a>b
            }
};

int main()
{
    int arr = {10,15,20,13,6,90};
    int n = sizeof(arr)/sizeof(arr[0]);

    priority_queue<int> heap;  // by default it makes maxheap

    priority_queue<int, vector<int>, greater<int> > minHeap;  // minheap

    priority_queue<int, vector<int>, Compare > minHeap;  // minheap using custom comparator

    for(auto x: arr)
    {
        heap.push(x);
    } 

    while(!heap.empty())
    {
        cout<<heap.top()<<endl;
        heap.pop();
    }

    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 10,15,20,13,6,90
 *
 * OUTPUT
 * 90
 * 20
 * 15
 * 13
 * 10
 * 6
 * 
 */


