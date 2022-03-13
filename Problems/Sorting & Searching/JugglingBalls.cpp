/**
 * @file JugglingBalls.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given an array containing balls of Red, Blue and Green Color in a random order. Your goal is to arrange these balls in sorted order - Red Balls, followed by Blue and then Green Balls. Red balls are denoted using number 0, Blue using 1 and Green using 2.
 * 
 * NOTE
 *      -> Try to solve the problem in a single scan of the array without using extra space. 
 * 
 * HINT
 *      -> read about DNF algorithm
 * 
 */


#include<bits/stdc++.h>
using namespace std;


/**
 * @brief sort the balls in place in a single pass (O(N) time, O(1) space)
 * 
 * @param balls 
 * @return vector<int> 
 * 
vector<int> sortBalls(vector<int> balls)
{
    int i=0,j=0,k=0;
    for(int i1=0;i1<balls.size();i1++)
    {
        if(balls[i1]==0)
            i++;
        else if(balls[i1]==1)
            j++;
        else if(balls[i1]==2)
            k++;
    }
    for(int k1=0;k1<balls.size();k1++)
    {
        if(i)
        {
            balls[k1] = 0;
            i--;
        }
        else if(j)
        {
            balls[k1] = 1;
            j--;
        }
        else if(k)
        {
            balls[k1] = 2;
            k--;
        }
    }
    return balls;
}
 */

// O(NlogN)
vector<int> sortBalls(vector<int> balls)
{
    sort(balls.begin(), balls.end());        
    return balls;
}

int main()
{
    int N,X;
    cin>>N>>X;

    vector<int>A, ans;
    for(int i=0;i<N;i++)
    {
        cin>>X;
        A.push_back(X);
    }

    ans = sortBalls(A);
    for(int i=0;i<N;i++)
        cout<<ans[i]<<" ";

    cout<<endl;
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 8
 * 0 0 1 2 0 1 2 0
 *
 * OUTPUT
 * 0 0 0 0 1 1 2 2 
 * 
 */