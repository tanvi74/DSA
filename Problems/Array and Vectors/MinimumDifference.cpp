/** Implement a function that takes an input two non-empty vector of integers, finds a pair of number (one from each array) whose absolute difference is closest to zero and returns a pair contiaining these 2 no.
 * Only one such pair exists 
 **/

#include<bits/stdc++.h>
using namespace std;


pair<int,int> minDifference(vector<int>a, vector<int>b)
{    
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int n1 = a.size();
    int n2 = b.size();
    
    int i=0,j=0,min=__INT16_MAX__;
    pair<int,int>Ti;
     
    while(i<n1 && j<n2)
        {
            if(abs(a[i]-b[j])<min)
            {
                min = abs(a[i]-b[j]);
                Ti.first = a[i];
                Ti.second = b[j];
            }
            if(a[i]>b[j])
                j++;
            else if(a[i]<b[j])
                i++; 
            else
                break;
        }
        
    return Ti;
}

int main()
{
    int N;
    cin>>N;

    vector<int>A,B;

    for(int i=0;i<N;i++)
        cin>>A[i];

    for(int i=0;i<N;i++)
        cin>>B[i];

    pair<int,int> ans =  minDifference(A);

    cout<<ans.first<<" "<<ans.second<<endl;
}

/**
 * @brief 
 * Input
 * 5
 * [23,5,10,17,30]
 * [26,134,135,14,19]
 * 
 * 
 * Output
 * 17,19
 * 
 */