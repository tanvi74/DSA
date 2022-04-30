/** Given a non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
 **/

#include<bits/stdc++.h>
using namespace std;

int rains(vector<int>arr)
{    
    int total = 0;
    
    int n = arr.size();
    if(n<=2)
        return 0;

    vector<int>right;
    vector<int>left;

    left[0] = arr[0];
    right[n-1] = arr[n-1];

    for(int i=1;i<n-1;i++)
    {
        left[i] = max(left[i-1],arr[i]);
        right[n-1-i] = max(right[n-i], arr[n-1-i]);
    }

    for(int i=0;i<n;i++)
    {
        int minHeight = min(left[i], right[i]);
        total += minHeight-arr[i];
    }

    return total;
}

int main()
{
    int N;
    cin>>N;

    vector<int>A;

    for(int i=0;i<N;i++)
        cin>>A[i];

    int ans = rains(A);

    cout<<ans<<endl;
}

/**
 * @brief 
 * Input
 * 12
 * [0,1,0,2,1,0,1,3,2,1,2,1]
 * 
 * 
 * Output
 * 6
 * 
 */