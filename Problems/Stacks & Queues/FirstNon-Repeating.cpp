/**
 * @file FirstNon-Repeating.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-08
 * 
 * @copyright Copyright (c) 2022
 * 
 * You are given a running stream of characters, output the first non-repeating characters in the string formed so far after every new character you get in the input. Output -1 if such a character doesn't exist. 
 * 
 * 
 */


#include<bits/stdc++.h>
using namespace std;

vector<char> FindFirstNonRepeatingCharacter(string S)
{
    queue<char>St;
    vector<char>ans;
    int freq[27] = {0};

    for(int i=0;i<S.length();i++)
    {
        char ch = S[i];
        freq[ch-'a']++;
        St.push(ch);
        bool flag = false;
        while(!St.empty())
        {
            if(freq[St.front()-'a']>1)
            {
                St.pop();
            }
            else
            {
                ans.push_back(St.front());
                flag = true;
                break;
            }
        }
        
        if(!flag)
        {
            ans.push_back('0');
        }
    }
    return ans;
}

int main()
{
    string S;
    cin>>S;

    vector<char>ans = FindFirstNonRepeatingCharacter(S);
    
    for(auto ch: ans)
        cout<<ch;
        
    cout<<endl;

    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * aabccbcd
 *
 * OUTPUT
 * a0bbb00d
 * 
 */