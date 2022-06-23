
/**
 * @file QuickBrownfox.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-23
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a string without spaces, and a list of words. Write a function that finds the minimum bars to be added to the string, so that all resulting words in are found in the list.
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int min_bars_helper(string S, vector<string>words, int idx, unordered_set<string> &m)
{
    // Base Case
    if(S[idx]=='\0')
    {
        return 0;
    }

    // Recursive Case
    int ans = INT_MAX;
    string current_string = "";

    for(int j=idx; S[j]!='\0'; j++)
    {
        current_string += S[j];

        // to check if it is present or not in set
        if(m.find(current_string) !=m.end())
        {
            int remaining_ans = min_bars_helper(S, words, j+1, m);
            if(remaining_ans!=-1)
            {
                ans = min(ans, 1 + remaining_ans);
            }
        }
    }

    1if(ans == INT_MAX)
        return -1;

    return ans;

}

int min_bars(string S, vector<string>words)
{
    unordered_set<string> m;

    for(string w: words)
    {
        m.insert(w);
    }

    // Recursive helper function
    int output = min_bars_helper(S,words,0,m);

    return output-1
}

int main()
{
    string S, si;
    cin>>S;

    int N;
    cin>>N;

    vector<string> subS;

    for(int i=0;i<N;i++)
    {
        cin>>si;
        subS.push_back(si);
    }

    cout<<min_bars(S,subS)<<endl;

    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * thequickbrownfoxjumpsoverthehighbridge
 * 14
 * the 
 * fox
 * thequickbrownfox
 * jumps
 * lazy
 * lazyfox
 * highbridge
 * the
 * over
 * bridge
 * high 
 * tall
 * brown
 * quick
 *  
 * OUTPUT
 * 4
 * 
 */


