/** Given an array of size at-least two, find the smallest subarray that needs to be sorted in place so that the entire input array become entirely sorted.
 * If the input array is already sorted, the function should return [-1,-1], otherwise return the start and end index of smallest subarray. 
 **/

#include<bits/stdc++.h>
using namespace std;

bool outOfOrder(vector<int>arr, int i)
{
    int x = arr[i];
    if(i==0)
    {
        return x>arr[1];
    }
    else if(i==arr.size()-1)
    {
        return x<arr[i-1];
    }

    return x>arr[i+1] || x<arr[i-1];
}

pair<int,int> subarraySort(vector<int>arr)
{    
    pair<int,int> ans;
    int N = arr.size();

    int lar = 0, smal = __INT_MAX__;

    for(int i=0;i<N;i++)
    {
        if(outOfOrder(arr,i))
        {
            lar = max(lar,arr[i]);
            smal = min(smal, arr[i]);
        }
    }

    if(smal === __INT_MAX__)
    {
        ans.first = -1;
        ans.second = -1;
    }

    int left = 0;
    while(arr[left] <= smal)
        left++;

    int right = N-1;
    while(arr[right] >= lar)
        right--;

    ans.first = left;
    ans.second = right;

    return ans;
}

int main()
{
    int N;
    cin>>N;

    vector<int>A;

    for(int i=0;i<N;i++)
        cin>>A[i];

    pair<int,int> ans = subarraySort(A);

    cout<<ans.first<<" "<<ans.second<<endl;
}

/**
 * @brief 
 * Input
 * 11
 * [1,2,3,4,5,8,6,7,9,10,11]
 * 
 * 
 * Output
 * [5,7]
 * 
 */