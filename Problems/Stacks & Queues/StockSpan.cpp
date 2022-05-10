/**
 * @file StockSpan.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * You are given price of a stock over next n days, your task is to calculate span of stock’s price for all n days.
 * The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.
 * For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].
 * 
 * https://img-c.udemycdn.com/redactor/raw/coding_exercise_instructions/2021-05-14_07-26-13-d8b5b9b5dc7de5f29feb1ed0df650487.jpg
 * 
 * INPUT: Vector V is passed in the function which represents the price of a stock over N days.
 * OUTPUT: Return a vector of stock spans.
 * 
 * 
 */


#include<bits/stdc++.h>
using namespace std;

vector<int> stockSpan(vector<int> v) 
{
//Write your code here. Do not modify the function or param
    vector<int>ans(v.size(), 1);
    for(int i=v.size()-1;i>=0;i--)
    {
        int x = v[i];
        int j = i-1;
        int cnt = 1;
        
        while(v[j]<=x && j>=0)
        {
            cnt++;
            j--;
        }
        
        ans[i] = cnt;
    }
    
    return ans;
}

int main()
{
    int N;
    cin>>N;
    
    int X;
    vector<int> V;
    
    for(int i=0;i<N;i++)
    {
        cin>>X;
        V.push_back(X);
    }
    
    vector<int>ans = stockSpan(V);
    for(auto ch: ans)
        cout<<ch<<" ";
        
    cout<<endl;
    
    return 0;
}



/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 7
 * 100 80 60 70 60 75 85
 *
 * OUTPUT
 * 1 1 1 2 1 4 6
 * 
 */