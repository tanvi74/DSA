/** 
 * Tokenisation a string denotes splitting a string h respect to some delimiter(s)
 **/

#include<bits/stdc++.h>
using namespace std;

vector<string>tokenisation(string S)
{ 
    vector<string>tokens;

    char *token = strtok(S, " ");

    while(token!=NULL)
    {
        tokens.push_back(token);
        *token = strtok(NULL, " ");
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