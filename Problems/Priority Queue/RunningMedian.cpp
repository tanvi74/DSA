
/**
 * @file RunningMedian.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-19
 * 
 * @copyright Copyright (c) 2022
 * 
 * You are given a running stream of integers. Write an efficient algorithm to output median of numbers read so far after every input.
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> leftHeap;  // by default it makes maxheap

    priority_queue<int, vector<int>, greater<int> > rightHeap;  // minheap

    int d;
    cin>>d;

    float med = d;
    cout<<med<<" ";

    cin>>d;

    while(d!=-1)
    {
        // left or right or equal
        if(leftHeap.size() > rightHeap.size())
        {
            if(d<med)
            {
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(d);
            }
            else
            {
                rightHeap.push(d);
            }

            med = (leftHeap.top() + rightHeap.top())/2.0;
        }
        else if(leftHeap.size() < rightHeap.size())
        {
            if(d>med)
            {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(d);
            }
            else
            {
                leftHeap.push(d);
            }

            med = (leftHeap.top() + rightHeap.top())/2.0;
        }
        else
        {
            if(d<med)
            {
                leftHeap.push(d);
                med = leftHeap.top();
            }
            else
            {
                rightHeap.push(d);
                med = rightHeap.top();
            }
        }

        cout<<med<<" ";
        cin>>d;

    }


    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 10,5,2,3,0,12,18,20,22, -1
 * 
 * OUTPUT
 * 10,7.5,5,4,3,4,5,7.5,10
 * 
 */


