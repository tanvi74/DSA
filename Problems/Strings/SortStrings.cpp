/** 
 * 
 * Given a list of 'n' strings S0,S1,S2,S3....,Sn-1, each consisting of spaces and digits, the number of spaces is the same for each entry.
 * The goal is to implement a variation of a sort command. None of the strings contain consecutive spaces.
 * Also no string starts or ends with a space
 * Spaces are used to divide string into columns, which can be used as keys in comparisons.
 * The program has to support the required parameters:-
 * key -> integer denoting the column used as key in comparisons. The left most colum denoted by 1.
 * reversed -> boolean variable indicating whether to reverse the results of comparisons.
 * comparison-type -> either lexicographic or numeric.
 * numeric -> It means that we compare the strings by their numeric values, so (13<122). If the comparison type is numeric for Si and Sj, for som i<j, and if both of them appear to be equal, then Si is considered to be strictly smaller than Sj as it comes first.        
 * 
 **/ 

#include<bits/stdc++.h>
using namespace std;

string extractStringsByKey(string S, int key)
{
    // strtok takes char input an array
    char *s = strtok((char *)S.c_str(), " ");
    while(key>1)
    {
        s = strtok(NULL," ");
        key--;
    }

    return (string)s;

}

int convertToInt(string S)
{
    int ans = 0;
    int p = 1;

    for(int i = S.length()-1;i>=0;i--)
    {
        ans += ((S[i]-'0')*p);
        p = p * 10;
    }

    return ans;
}

bool numericCompare(pair<string,string>S1, pair<string,string>S2)
{
    string key1 = S1.second;
    string key2 = S2.second;

    return convertToInt(key1) < convertToInt(key2);

}

bool lexicoCompare(pair<string,string>S1, pair<string,string>S2)
{
    string key1 = S1.second;
    string key2 = S2.second;

    return key1<key2;

}

int main()
{
    int N;
    cin>>N;

    string temp;
    vector<string> S;

    for(int i=0;i<N;i++)
    {
        getline(cin, temp);
        S.push_back(temp);
    }

    int key;
    string type, reverse;
    cin>>key>>reverse>>type;

    vector<pair<string,string>>Ti;

    for(int i=0;i<N;i++)
    {
        Ti.push_back({S[i], extractStringsByKey(S[i], key)});
    }


    if(type=="numeric")
    {
        sort(Ti.begin(),Ti.end(),numericCompare);
    }
    else
    {
        sort(Ti.begin(),Ti.end(),lexicoCompare);
    }
    
    if(reverse == "true")
        reverse(Ti.begin(),Ti.end());

    for(int i=0;i<N;i++)
        cout<<Ti[i].first<<endl;

}

/**
 * @brief 
 * Input
 * 3
 * 92 022
 * 82 12
 * 77 13
 * 2 false numeric
 * 
 * 
 * Output
 * 82 12
 * 77 13
 * 92 022
 * 
 */