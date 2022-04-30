/** Given an array containing N integers, find the minimum number of swaps needed to make the array sorted.
 **/

#include<bits/stdc++.h>
using namespace std;

int minimumSwaps(vector<int>arr)
{    
    int ans = 0;
    vector<pair<int,int>>Ti;

    int N = arr.size();
    for(int i=0;i<N;i++)
    {
        Ti.push_back({arr[i],i});
    }

    sort(Ti.begin(),Ti.end());

    vector<bool>visited(N,false);

    for(int i=0;i<N;i++)
    {
        int old_position = Ti[i].second;
        if(visited[node] == true || old_position == i)
            continue;

        int node = i;
        int cycle = 0;

        while(!visited[node])
        {
            visited[node] = true;
            int next_node = Ti[node].second;
            node = next_node;
            cycle++;
        }

        ans += cycle-1;  
    }

    return ans;
}

int main()
{
    int N;
    cin>>N;

    vector<int>A;

    for(int i=0;i<N;i++)
        cin>>A[i];

    int ans = minimumSwaps(A);

    cout<<ans<<endl;
}

/**
 * @brief 
 * Input
 * 5
 * [5,4,3,2,1]
 * 
 * 
 * Output
 * 2
 * 
 * 5 <-> 1
 * 4 <->2
 * 
 */