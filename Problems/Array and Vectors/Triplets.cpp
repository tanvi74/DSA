/** Given an array of N integers, and an number N denoting a target sum. 
 * Find all distinct integers that can add up to form target sum. The numbers in each triplet should be ordered in aescending order, and triplets should be ordered too.
 * Return an empty array if there is no such triplet exists.
 * 
 **/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> triplets(vector<int>arr, int N)
{    
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    for(int i=0;i<arr.size()-3;i++)
    {
        int l = i+1;
        int r = arr.size()-1;

        while(l<r)
        {
            int sum = arr[i]+arr[l]+arr[r];
            if(sum == N)
            {
                ans.push_back({arr[i], arr[l], arr[k]});
                l++;
                k--;
            }
            else if(sum > N)
            {
                k--;
            }
            else if(sum < N)
            {
                l++;
            }
        }
    }

    return ans;
}

int main()
{
    int N, targetSum;
    cin>>N>>targetSum;

    vector<int>A;
    vector<vector<int>>ans;

    for(int i=0;i<N;i++)
        cin>>A[i];

    ans = triplets(A,targetSum);

    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<3;j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}

/**
 * @brief 
 * Input
 * 10 18
 * [1,2,3,4,5,6,7,8,9,15]
 * 
 * 
 * Output
 * [
 *      [1,2,15],
 *      [3,7,8],
 *      [4,6,8],
 *      [5,6,7]
 * ]
 * 
 */