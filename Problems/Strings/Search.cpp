/** 
 * Implement a function that returns a list of all occurences of a given substring inside a big string.
 * Return empty vector if there is no occurence of small string inside the big one.
 **/

#include<bits/stdc++.h>
using namespace std;

vector<int>stringSearch(string big,string small){
    //store the occurrences in the result vector
    vector<int>result = {};
    
    int index = big.fid(small);

    while(index!=-1)
    {
        result.push_back(index);
        index = big.find(small,index+1);
    }
    
    return result;
}

int main()
{
    string big, small;
    
    getline(cin,big);
    getline(cin,small);

    vector<int>ans = stringSearch(big,small);

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    
    cout<<endl;

}

/**
 * @brief 
 * Input
 * I like the movie, acting in movie was great!
 * movie
 * 
 * 
 * Output
 * 12,29
 * 
 * 
 */