
/**
 * @file CommonElements.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-19
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given two vectors, your task is to find the common elements between them.
 * All elements in one vector are unique among themselves.
 * 
 * Input Format:
 * Function contains two integer vectors v1 and v2 as parameters.
 * 
 * Output Format:
 * Return a vector containing list of common elements in sorted order.
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<int> v1, vector<int> v2)
{
    //Write your code here. Do not modify the function or the parameters. You can use helper function if needed.
    unordered_set <int> A ;
    
    for(int i=0;i<v1.size();i++)
    {
        A.insert(v1[i]);
    }
    
    int s = A.size();
    vector<int>ans;
    
    for(int i=0;i<v2.size();i++)
    {
        s = A.size();
        A.insert(v2[i]);
        
        if(s==A.size())
            ans.push_back(v2[i]);
    }
    
    sort(ans.begin(), ans.end());
    return ans;
    
}

int main()
{
    
    vector<int> A = {1,45,54,71,76,12};
    vector<int> B = {1,7,5,4,6,12};
    
    vector<int>ans = commonElements(A,B);

    for(auto it : ans)
        cout<<it<<" ";

    cout<<endl;

    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 1,45,54,71,76,12
 * 1,7,5,4,6,12
 * 
 * OUTPUT
 * 1 12
 * 
 */


