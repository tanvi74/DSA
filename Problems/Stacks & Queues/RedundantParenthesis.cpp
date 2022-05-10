/**
 * @file RedundantParenthesis.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-08
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a string of balanced expression, find if it contains a redundant parenthesis or not. 
 * A set of parenthesis is redundant if same sub-expression is surrounded by unnecessary or multiple brackets. 
 * Print "Yes" if it is else "No". 
 * 
 */


#include<bits/stdc++.h>
using namespace std;

bool isRedundant(string str)
{
    stack<char>S;
    for(char ch : str)
    {
        if(ch!=')')
        {
            S.push(ch);
        }
        else
        {
            bool oprn = false;
            while(!S.empty() && S.top()!='(')
            {
                char top = S.top();
                if(top=='+' || top=='-' || top=='*' || top=="/")
                {
                    oprn = true;
                }

                S.pop();
            }
            S.pop();
            if(!oprn)
                return true;
        }
    }

    if(S.empty())
    {
        return false;
    }

    return true;
}

int main()
{
    string S;
    cin>>S;

    cout<<isRedundant(S)<<endl;
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * ((a+b))
 * (a+(b))/c
 * (a+b*(c-d))
 *
 * OUTPUT
 * Yes
 * Yes
 * No
 * 
 */