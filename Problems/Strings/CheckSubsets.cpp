/** 
 * 
 * Given the two non-empty strings, write a function that determines if the second string is the subsequence of the first one. 
 * 
 **/ 

#include<bits/stdc++.h>
using namespace std;

string isSubset(string A,string B)
{
    int i = A.size()-1;
    int j = B.size()-1;
    while(i>=0 && j>=0)
    {
        if(B[j]==A[i])
        {
            i--;
            j--;
        }
        else 
        {
            i--;
        }
    }

    if(j==-1)
        return "Yes";
    
    return "No";
    
}


int main()
{
    string A,B;
    cin>>A>>B;

    string x = isSubset(A,B);
    cout<<x<<endl;

}

/**
 * @brief 
 * Input
 * condingminutes
 * cines
 * 
 * 
 * Output
 * Yes
 * 
 */