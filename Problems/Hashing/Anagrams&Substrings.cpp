
/**
 * @file Anagrams&Substrings.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-23
 * 
 * @copyright Copyright (c) 2022
 * 
 * Two strings are anagrams of each other if the letter of one string can be rearranged to form the other string.
 * Given a string, find the number of pairs of substrings of the string that are anagrams of each other.   
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

vector<int> getHashValue(string S, int i, int j)
{
    vector<int> freq(26,0);

    for(int k=i;k<=j;k++)
    {
        char ch = S[k];
        freq[ch-'a']++;
    }

    return freq;
}

int anagrams_substrings(string S)
{
    map<vector<int>, int> m; 
    for(int i=0;i<S.length;i++)
    {
        for(int j=i;j<S.length;j++)
        {
            vector<int> h = getHashValue(S, i, j);
            m[h]++;
        }
    }

    int ans = 0;
    for(auto p : m)
    {
        int freq = p.second;
        if(freq>=2)
        {
            ans += (freq)(freq-1)/2;
        }
    }

    return ans;

}

int main()
{
    string S;
    cin>>S;

    cout<<anagrams_substrings<<endl;

    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * abba
 * 
 * OUTPUT
 * 4
 * 
 */


