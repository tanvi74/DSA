/**
 * @file GenerateBrackets.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-14
 * 
 * @copyright Copyright (c) 2022
 * 
 * Write a function to generate all possible n pairs of balanced parenthesis '(' and ')'
 * 
 * 
 */


#include<bits/stdc++.h>
using namespace std;

void generateBrackets(string output, int n, int open, int close, int i)
{
    //base case
    if(i==2*n)
        cout<<output<<endl;

    // Adding opening brackets
    if(open<n)
        generateBrackets(output + '(', n, open+1, close, i+1);

    // Adding closing brackets
    if(close<open)
        generateBrackets(output + ')', n, open, close+1, i+1);
}

int main()
{
    string output;
    int n;
    cin>>n;

    generateBrackets(output, n, 0, 0, 0);

    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 2
 *
 * OUTPUT
 * ()()
 * (())
 * 
 */