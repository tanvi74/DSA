
/**
 * @file MergingArrays.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-19
 * 
 * @copyright Copyright (c) 2022
 * 
 * The k-way Merge problem consists of merging k sorted arrays to produce a single sorted array with the same elements. 
 * k-way merges are used in external sorting procedures. External sorting algorithms are a class of sorting algorithms that can handle massive amounts of data 
 * 
 * Input
 * - No. of arrays
 * - each line contains a sorted array
 * 
 * Output
 * - a single sorted array
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;


// 1st M

vector<int> mergeKArrays(vector<vector<int> > arrays)
{
    //Complete this function
    
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int> > minHeap;  // minheap
    
    vector<int>idx(arrays.size(),0);
   
    
    // For intial building
    for(int i=0; i<arrays.size(); i++)
    {
        minHeap.push(arrays[i][0]);
    }
    
    while(!minHeap.empty())
    {
        int x = minHeap.top();
        ans.push_back(x);
        minHeap.pop();
        
        for(int i=0; i<arrays.size(); i++)
        {
            if(arrays[i][idx[i]] == x)
            {
                idx[i] = idx[i] + 1;
                
                if(arrays[i].size()>idx[i])
                {
                    minHeap.push(arrays[i][idx[i]]);
                }
            }
        }
        
    }
    
    return ans;
}

//2nd M
vector<int> mergeKArrays(vector<vector<int> > arrays)
{
    //Complete this function
    
    vector<int> ans;
    // triplet heap - element, array idx, element idx
    priority_queue< vector<int>, vector<vector<int>>, greater<int> > minHeap;  // minheap
   
    
    // For intial building
    for(int i=0; i<arrays.size(); i++)
    {
        minHeap.push({arrays[i][0], i, 0});
    }
    
    while(!minHeap.empty())
    {
        int x = minHeap.top();
        minHeap.pop();

        int element = x[0];
        int aIdx = x[1];
        int eIdx = x[2];

        ans.push_back(element);

        if(arrays[aIdx].size()>eIdx+1)
        {
            minHeap.push({arrays[aIdx][eIdx+1], aIdx, eIdx+1});
        }
            
    }
    
    return ans;
}


int main()
{
    int K=3;
    
    vector<vector<int>> A{
        {10,15,20,30},
        {2,5,8,14,24},
        {0,11,60,90}
    };
    
    vector<int> ans = mergeKArrays(A);
    
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 *  {10,15,20,30},
    {2,5,8,14,24},
    {0,11,60,90}
 * 
 * OUTPUT
 * 0 2 5 8 10 11 14 15 20 24 30 60 90 
 * 
 */


