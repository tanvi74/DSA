/**
 * @file Permutations.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-14
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a string, find all the permutations of the string.
 * 
 */


#include<bits/stdc++.h>
using namespace std;

void permute(string a, int l, int r, set<string>& ans)
    {
        // Base case
        if (l == r)
            ans.insert(a);
        else
        {
            for (int i = l; i <= r; i++)
            {
                swap(a[l], a[i]);
                permute(a, l+1, r, ans);
                swap(a[l], a[i]);
            }
        }
    }

vector<string> findSortedPermutations(string s)
{
    set<string> ans;
    vector<string> vect;
    

    permute(s, 0, s.size()-1, ans);
    for (auto itr = ans.begin();  itr != ans.end(); itr++) 
    {
        vect.push_back(*itr);
    }
    
    return vect;
}

int main()
{
    string s;
    cin>>s;
    
    vector<string> ans;
    ans = findSortedPermutations(s);
    
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * abc
 *
 * OUTPUT
 * abc
 * acb
 * bca
 * bac
 * cab
 * cba
 * 
 */