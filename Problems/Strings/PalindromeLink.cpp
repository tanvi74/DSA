/**
 * @file PAlindromeLink.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a palindromic string of lowercase English letters palindrome, replace exactly one character with any lowercase English letter so that the resulting string is not  a palindrome and that it is the lexicographically smallest one possible.
 * Return the resulting string. If there is no way to replace a character to make it not a palindrome, return an empty string. 
 * 
 */


#include<bits/stdc++.h>
using namespace std;

string breakPalindrome(string palindrome) {
        
        if(palindrome.length()==1)
            return "";
    
        bool flag = 0;
    
        string ans = palindrome;
        int N = palindrome.length();
        
        
        for(int i=0; i<N/2;i++)
        {
            if(ans[i]!='a')
            {
                flag = 1;
                ans[i] = 'a';
                break;
            }
        }
        
        if(flag)
            return ans;
        else
        {
            int idx = N-1;
            ans[idx] = 'b';
            return ans;
        }
        
        
}

int main()
{
    string S;
    cin>>S;

    cout<<breakPalindrome(S)<<endl;
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * abccba
 * 
 * OUTPUT
 * aaccba
 * 
 * 
 */