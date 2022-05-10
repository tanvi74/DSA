/**
 * @file BalancedParenthesis.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-08
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given an expression string, write a program to check all the pair of parenthesis are valid.
 * 
 */


#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string input)
{
    stack<char>S;
    for(auto ch : input)
    {
        switch(ch)
        {
            case '(': 
            case '[':
            case '{': S.push(ch); break;
            case ')': 
                        if(!S.empty() and S.top()=='(')
                        {
                            S.pop();
                            break;
                        }
                        else    
                            return false;
            case '}': 
                        if(!S.empty() and S.top()=='{')
                        {
                            S.pop();
                            break;
                        }
                        else    
                            return false;
            case ']': 
                        if(!S.empty() and S.top()=='[')
                        {
                            S.pop();
                            break;
                        }
                        else    
                            return false;

            default: continue;
        }
    }

    if(S.empty())
        return true;

    return false;
}

int main()
{
    string S;
    cin>>S;

    cout<<isBalanced(S)<<endl;
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * ((a+b)*x-d)
 * ((a+b]+c))*(d-e)
 *
 * OUTPUT
 * true
 * false
 * 
 */