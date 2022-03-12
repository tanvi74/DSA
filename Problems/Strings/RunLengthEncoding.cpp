/**
 * @file RunLengthEncoding.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 * Write a function to perform basic string compression using the counts of repeated characters, also known as Run Length Encoding. 
 * Let see one example, the input string "aaaabcccccaaa" would become "a4b1c5a3". 
 * If the "compressed" string would not become smaller than the original string, your function should return the input string. 
 * You can assume the string has only uppercase and lowercase letters. 
 * You may use the to_string(int) method to convert integer to string.
 * 
 */


#include<bits/stdc++.h>
using namespace std;

//str is the input the string
string compressString(const string &S){   
    //complete the function to return output string
   char ch = S[0];
    int cnt = 0;
    string ans = "";
    for(size_t i=0;i<S.size();i++)
    {
        if(ch == S[i])
            cnt++;
        else
        {
            ans += ch;
            ans += to_string(cnt);
            ch = S[i];
            cnt = 1;
        }
    }
    
    ans += ch;
    ans += to_string(cnt);
    
    if(ans.length()<S.length())
        return ans;
    
    return S;
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string S;
        cin>>S;
        string ans = compressString(S);
        cout<<ans<<endl;
    }
    return 0;
}



/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 2
 * bbbaaaadexxxxxx
 * abc
 * 
 * OUTPUT
 * b3a4d1e1x6
 * abc
 * 
 * 
 */