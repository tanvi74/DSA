/**
 * @file SmallestDistinctWindow.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a string, find the smallest window(substring) having distinct character of the string.
 * 
 */


#include<bits/stdc++.h>
using namespace std;

string smallestWindow(string S){
    
    if(S.length()<=1)
        return S;
    
    int i=0;
    int j=0;

    int window_length = 0;
    int max_window_length = 0;
    int start_window = -1;

    unordered_map<char,int>m;

    while(j<S.length())
    {
        char ch = S[j];

        if(m.count(ch) && m[ch]>=i)
        {
            i = m[ch] + 1;
            window_length = j-i;
        }

        m[ch] = j;
        window_length++;
        j++;

        if(window_length>max_window_length)
        {
            max_window_length = window_length;
            start_window = i;
        }
    }
    
    return S.substr(start_window, max_window_length);
    
}
int main()
{
    string S;
    cin>>S;

    cout<<smallestWindow(S)<<endl;
    
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * aabcbcdbcaaad
 * 
 * OUTPUT
 * dbca
 * 
 */