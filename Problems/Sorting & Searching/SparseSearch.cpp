/**
 * @file SparseSearch.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a sorted array of strings that is interpersed with empty strings, write a method to find the location of a given string.
 * 
 */


#include<bits/stdc++.h>
using namespace std;

int sparse_search(vector<string>A, int n, int key)
{
    int s = 0;
    int e = n-1;

    while(s<=e)
    {
        int mid = (s+e)/2;

        int mid_left = mid-1;
        int mid_right = mid+1;

        if(a[mid]=="")
        {
            //update the mid to the nearest non-empty string
            while(1)
            {
                if(mid_left<s && mid_right>e)
                    return -1;
                
                else if(mid_left>=s && A[mid_left]!="")
                {
                    mid = mid_left;
                    break;
                }
                else if(mid_right<=e && A[mid_right]!="")
                {
                    mid = mid_right;
                    break;
                }
                mid_left--;
                mid_right++;
            }
        }
        else if(A[mid]==key)
            return mid;
        else if(A[mid]>key)
        {
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }
    }

    return -1;
    

}

int main()
{
    int N;
    cin>>N;

    vector<string>A;
    string X;
    for(int i=0;i<N;i++)
    {
        cin>>X;
        A.push_back(X);
    }

    string key;
    cin>>key;

    cout<<sparse_search(A,N,key)<<endl;
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 12 
 * "ai" "" "" "bat" "" "" "car" "cat" "" "" "dog" ""
 * bat
 * 
 * 
 * OUTPUT
 * 4
 * 
 */