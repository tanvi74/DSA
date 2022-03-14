/**
 * @file StringWindow.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given two strings, one big string, one small string, find the smallest window in the big string that contains all the characters of a small string
 *      - Window can have additional characters if required
 *      - If small string has duplicates, then those duplicates must be present with same or higher count in window.
 * 
 */


#include<bits/stdc++.h>
using namespace std;

string string_window(string A, string B)
{
    // Array as Frquency map(Hashmap)
    int FP[256] = {0};
    int FS[256] = {0};

    for(int i=0;i<B.length();i++)
    {
        FP[B[i]]++; 
    }

    // Sliding Window Algo
    int cnt = 0;
    int start = 0;
    int start_window = -1;
    int minWindowSize = __INT16_MAX__;
    int windowSize;

    for(int i=0;i<A.length();i++)
    {
        char ch = A[i];

        // expand Window
        FS[ch]++;

        //Count is the no of characters that are matched.
        if(FP[ch]!=0 && FP[ch]<=FS[ch])
        {
            cnt++;
        }

        //If all the characters are found 
        if(cnt == B.length())
        {
            // start contracting
            while(FP[A[start]]==0 || FP[A[start]]<FS[A[start]])
            {
                FS[A[start]]--;
                start++;
            }

            windowSize = i-start+1;
            if(windowSize<minWindowSize)
            {
                minWindowSize = windowSize;
                start_window = start;
            }

        }
    }

    if(start_window == -1)
        return "No window found";
    
    return A.substr(start_window, minWindowSize);

}

int main()
{
    int T;
    while(T--)
    {
        string A,B;
        cin>>A>>B;
        cout<<string_window(A,B)<<endl;
    }
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 2
 * hello_world lol
 * fizzbuzz fuzz
 * 
 * OUTPUT
 * llo
 * fizzbu
 * 
 */