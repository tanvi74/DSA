/** 
 * Given a string, write a function to replace all the spaces in a string "%20". It is given that the string has sufficient space at the end to hold the additional characters.
 **/

#include<bits/stdc++.h>
using namespace std;

string space(string S)
{
    
    int space = 0;
    string ans = "";
    for(int i=0;i<S.size();i++)
    {
        if(S[i] === ' ')
            space++;
    }

    int idx = S.size() + (space*2);
    ans[idx] = '\0';

    for(int i=S.size()-1;i>=0;i--)
    {
        if(S[i]==' ')
        {
            ans[idx-1] = '0';
            ans[idx-2] = '2';
            ans[idx-3] = '%';
            idx = idx-3;
        }
        else
        {
            ans[idx-1] = S[i];
            idx--;
        }
    }
    
   return ans;
}

int main()
{
    string S;
    
    getline(cin,S);

    string ans = space(S);
    
    cout<<ans<<endl;

}

/**
 * @brief 
 * Input
 * hello world, how are you?
 * 
 * 
 * Output
 * hello%20world,%20how%20are%20you?
 * 
 * 
 */