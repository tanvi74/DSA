
/**
 * @file FirstRepeatingLetter.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-19
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a string, find the first repeating letter in a string in a single scan of the string. Return 
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;


char firstRepeatChar(string input){
    
    unordered_set<char>S;
    
    S.insert(input[0]);
    
    char ans;
    
    for(int i=1;i<input.size();i++)
    {
        int size = S.size();
        
        S.insert(input[i]);
        
        if(S.size()==size)
        {
            ans = input[i];
            break;
        }
    }
    
    return ans;
    
}

int main()
{
    string S;
    cin>>S;

    cout<<firstRepeatChar(S)<<endl;
    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * codingminutes
 * 
 * OUTPUT
 * i
 * 
 */
