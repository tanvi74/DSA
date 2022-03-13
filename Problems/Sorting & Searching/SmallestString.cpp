/**
 * @file SmallestString.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 * You are given a list of n strings a1,a2,a3,....,an. You like to concatenate them together in some order such that the resulting string is lexicographically smallest.
 * Given the list of strings, output the lexicographically smallest concatenation. 
 * 
 */


#include<bits/stdc++.h>
using namespace std;

bool compare(string X, string Y)
{
    return X+Y < Y+X;
}

int main()
{
    int N;
    cin>>N;

    vector<string> A;
    string X;

    for(int i=0;i<N;i++)
    {
        cin>>X;
        A.push_back(X);
    }

    sort(A, A+N, compare);

    for(int i=0;i<N;i++)
        cout<<A[i];

    cout<<endl; 

    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 2
 * 3
 * c
 * cb
 * cba
 * 3
 * a
 * ab
 * aba
 * 
 * OUTPUT
 * cbacbc
 * abaaba
 * 
 */