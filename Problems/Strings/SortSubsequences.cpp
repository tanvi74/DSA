/** 
 * 
 * You are given a string, you need to print all subsequences of the string sorted by length and lexicographic order if length is same.
 * 
 **/ 

#include<bits/stdc++.h>
using namespace std;

void sortSubsequence(string S, string S1, vector<string>&V )
{
    // base case
    if(S.size()==0)
    {
        V.push_back(S1);
        return;
    }

    char ch = S[0];
    string reduced_input = S.substr(1);

    sortSubsequence(reduced_input, S1, V);
    sortSubsequence(reduced_input, S1+ch, V);
}

bool compare(string S1, string S2)
{
    if(S1.length() == S2.length())
        return S1<S2;

    return S1.length()<S2.length();
}

int main()
{
    string A;
    cin>>A;

    vector<string>V;
    sortSubsequence(A,"",V);

    sort(V.begin(),V.end(),compare);

    for(auto i : V)
    {
        cout<<i<<endl;
    }


}

/**
 * @brief 
 * Input
 * abcd
 * 
 * 
 * Output
 * 
 * a
 * b
 * c
 * d
 * ab
 * ac
 * ad
 * bc
 * bd
 * cd
 * abc
 * abd
 * bcd
 * abcd
 * 
 */