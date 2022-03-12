/** Implement a function that takes an input a vector of integers, and print the maximum subarray sum that can be formed. 
 * A subarray is defined as consecutive segment of the array.
 * If all the numbers are negative, return 0 
 **/

#include<bits/stdc++.h>
using namespace std;

// Kadane's Theorem
int maximumSum(vector<int>arr)
{    
    int largest = 0;
    int N = arr.size();
    int sum = 0;
    for(int i=0;i<N;i++)
    {
        sum += arr[i];
        if(sum>largest)
            largest = sum;
        
        if(sum<0)
            sum = 0;
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

    int ans = maximumSum(A);

    cout<<ans<<endl;
}

/**
 * @brief 
 * Input
 * 8
 * [-1,2,3,4,-2,6,-8,3]
 * 
 * 
 * Output
 * 13
 * 
 * [2,3,4,-1,6]
 * 
 */