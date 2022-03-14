/** Given an array containing N integers, find the length of the longest band.
 * A band is defined as a subsequesnce which can be reorder in such a manner all elements appear consecutive (i.e. absolute difference between consecutive elements is 1)
 * Longest band is the one having maximum elements
 **/

#include<bits/stdc++.h>
using namespace std;

int longestBand(vector<int>arr)
{    
    int largest = 0;
    unordered_set<int> S;

    for(int i=0;i<N;i++)
        S.insert(arr[i]);

    for(int i=0;i<arr.size()-1;)
    {
        int parent = arr[i]-1;
        if(S.find(parent)==S.end())
        {
            int no = arr[i]+1;
            int cnt = 1;
            while(S.find(no)!=S.end())
            {
                cnt++;
                no++;
            }

            largest = max(largest,cnt);
        }
        
    }

    return largest;
}

int main()
{
    int N;
    cin>>N;

    vector<int>A;

    for(int i=0;i<N;i++)
        cin>>A[i];

    int ans = longestBand(A);

    cout<<ans<<endl;
}

/**
 * @brief 
 * Input
 * 12
 * [1,9,3,0,18,5,2,4,10,7,12,6]
 * 
 * 
 * Output
 * 8
 * 
 * Longest band {0,1,2,3,4,5,6,7}
 * 
 */