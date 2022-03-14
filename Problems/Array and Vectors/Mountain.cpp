/** Write a function that takes input an array of distinct integers, and return the length of the highest mountain.
 * A mountain is defined as adjacent integers that are strictly increasing until they reach a peak, at which it becomes strictly decreasing.
 * At least 3 nos are required to form a mountain.
 * 
 **/

#include<bits/stdc++.h>
using namespace std;

int mountain(vector<int>arr)
{    
    int largest = 0;

    for(int i=1;i<arr.size()-1;)
    {
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
        {
            int l = i;
            int cnt = 1;
            while(l>0 && arr[l]>arr[l-1])
            {
                cnt++;
                l--;
            }

            while(i<arr.size()-1 && arr[i]>arr[i+1])
            {
                cnt++;
                i++;
            }
            largest = max(cnt,largest);
        }
        else
            i++;

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

    int ans = mountain(A);

    cout<<ans<<endl;
}

/**
 * @brief 
 * Input
 * 16
 * [5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4]
 * 
 * 
 * Output
 * 9
 * 
 */