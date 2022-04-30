/**
 * @file BiggestNumberString.cpp
 * @author Tanvi 
 * @brief 
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 * You are given a vector of numbers. You want to concatenate these numbers together to form the lexicographically largest number. 
 * Print that largest number number. 
 * You can't rearrange the digits of any number, however you can place the numbers next to each other in any order.
 * 
 * 
 * 
 */


#include <bits/stdc++.h>
using namespace std;

bool compare(string n1, string n2)
{
    string XY = n1.append(n2);
    string YX = n2.append(n1);
    
    return XY>YX;
}

string concatenate(vector<int> numbers){
    //complete this method and return the largest number you can form as a string
    
    vector<string>comp;
    
    for(int i=0;i<numbers.size();i++)
        comp.push_back(to_string(numbers[i]));
    
    
    sort(comp.begin(), comp.end(), compare);
    
    string ans="";
    
    for(int i=0;i<numbers.size();i++)
        ans += comp[i];
    
    
    return ans;
    
}

int main()
{
    int N;
    cin>>N;
    
    int A[N];
    for(int i=0;i<N;i++)
        cin>>A[i];

    string ans = concatenate(A);
    cout<<ans<<endl;

    return 0;
}


/**
 * @brief 
 * INPUT
 * 5
 * 10,11,20,30,3
 * 
 * OUTPUT
 * 330201110
 * 
 */