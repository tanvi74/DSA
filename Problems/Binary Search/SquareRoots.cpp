/**
 * @file SquareRoots.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-20
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given an integer N and an integer P, you need to find the square root of number N upto P places. 
 * Do it without using library function. 
 * 
 */


#include<bits/stdc++.h>
using namespace std;

float squareroot(int N,int P)
{
    int s = 0;
    int e = N;
    float ans = 0;

    // Binary Search
    while(s<e)
    {
        int mid = (s+e)/2;
        
        if(mid*mid == N )
        {
            ans = mid;
        }
        else if(mid*mid<N)
        {
            ans = mid;
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }

    // Linear Search for Precision
    float inc = 0.1;

    while(P--)
    {
        while(ans*ans<=N)
        {
            ans += inc;
        }

        ans = ans - inc;
        inc = inc/10.0;
    }

    return ans;

}

int main()
{
    int N,P;
    cin>>N>>P;

    cout<<squareroot(N,P)<<endl;
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 10 
 * 3
 *
 * OUTPUT
 * 3.162
 * 
 */