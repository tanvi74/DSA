/**
 * @file StringNormalization.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * You are given a sentence with words separated by spaces.
 * Your task is to:
 *      Write a function that returns a copy of this sentence where all the words:
 *          start with a capital letter
 *          the rest of the letters are lower case
 * Note: 
 *      Your function should not modify the sentence given as argument.
 * 
 */


#include<bits/stdc++.h>
using namespace std;

string normalize(const string &sentence) {
    string copy = sentence;
    //Make the changes in copy, and return it
    
    for(int i=0;i<sentence.length();i++)
    {
        if(sentence[i]==' ')
        {
            if(copy[i+1]!=' ')
            {
                copy[i+1]=toupper(copy[i+1]);
                i++;
            }
        }
        else if(i==0)
        {
            copy[i] = toupper(copy[i]);
        }
        else
        {
            copy[i]=tolower(copy[i]);
        }
    }
    
    return copy;
}

int main()
{
    string S;
    getline(cin,S);
    cout<<normalize(S)<<endl;
  
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * This is SO MUCH FUN!
 * 
 * OUTPUT
 * This Is So Much Fan
 * 
 * 
 */