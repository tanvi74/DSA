/** 
 * Implement a function that takes input of vector of integers, and return vector of same length, where each element in the output array is equal to the product of every other number in the input array.
 * Solve this problem without using division.
 * 
 * In other words, the value at output[i] is equal to the product of every number in the input array other than input[i]. You can assume that answer can be stored inside int datatype and no-overflow will occur due to products.
 * 
 *  
 **/

#include<bits/stdc++.h>
using namespace std;


vector<int>productArray(vector<int>arr){
    
    //Create an output Array
    int n = arr.size();
    vector<int>output(n,1);
    vector<int>left(n,1);
    vector<int>right(n,1);
    
    for(int i=1;i<n-1;i++)
    {
        left[i] = left[i-1]*arr[i-1];
        right[n-1-i] = right[n-i]*arr[n-i];
    }
    
    left[n-1] = left[n-2]*arr[n-2];
    right[0] = right[1]*arr[1];
    
    for(int i=0;i<n;i++)
    {
        output[i] = left[i]*right[i];
    }
    
    return output;
}

int main()
{
    int N;
    cin>>N;

    vector<int>A;

    for(int i=0;i<N;i++)
        cin>>A[i];

    vector<int> ans =  productArray(A);

    for(int i=0;i<N;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}

/**
 * @brief 
 * Input
 * 5
 * [1,2,3,4,5]
 * 
 * 
 * Output
 * [120,60,40,30,24]
 * 
 */