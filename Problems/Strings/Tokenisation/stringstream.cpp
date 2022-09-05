/** 
 * Tokenisation a string denotes splitting a string h respect to some delimiter(s)
 **/

#include<bits/stdc++.h>
using namespace std;

vector<string>tokenisation(string S)
{
    stringstream ss(S);
    
    string token;
    vector<string>tokens;

    while(getline(ss, token, ' '))
    { 
        tokens.push_back(token);
    }

    return tokens;
}

int main()
{
    string S;
    
    getline(cin,S);

    vector<string>ans = tokenisation(S);

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;

}

/**
 * @brief 
 * Input
 * today is a sunny day
 * 
 * 
 * Output
 * today
 * is 
 * a 
 * sunny
 * day
 * 
 * 
 */