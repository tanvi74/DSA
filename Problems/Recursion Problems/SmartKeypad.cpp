/**
 * @file SmartKeypad.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-14
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a number N and a modern phone keypad. Find out all the possible strings generated using that number.
 * 
 */


#include<bits/stdc++.h>
using namespace std;

string keypad = ["", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"];

void printKeypadOutput(string input, string output, int i=0)
{
    // Base Case
    if(input[i]=='\0')
    {
        cout<<output<<endl;
        return;
    }

    // Recursive Case
    int curr_digit = input[i] - '0';
    if(curr_digit == 0 || curr_digit == 1)
    {
        printKeypadOutput(input, output, i+1);
    }

    for(int k=0; k<kepad[curr_digit].size(); k++)
    {
        printKeypadOutput(input, output + keypad[curr_digit][k], i+1);
    }

    return;

}

int main()
{
    string input;
    cin>>input;

    string output;
    printKeypadOutput(input, output); 
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 23
 *
 * OUTPUT
 * AD
 * AE
 * AF
 * BD
 * BE
 * BF
 * CD
 * CE
 * CF
 * 
 * 
 */