/**
 * @file ModuloExpoentiations.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-17
 * 
 * @copyright Copyright (c) 2022
 * 
 * You are given two numbers a and b, your task is to compute a raised to power b. As this value can be very large compute it to modulo 1000000007.
 * 
 * HINT
 * Use modulo property
 * (m*n)%p = ((m%p)*(n%p))%p
 */


#include<bits/stdc++.h>
using namespace std;

long long int powerModulo(int A, int B)
{
    if(B<=0)
        return 1;
    
    return ((A%1000000007) * powerModulo(A,B-1)) % 1000000007;
}

int main()
{
    int A1, A2;
    cin>>A1>>A2;

    cout<<powerModulo(A1,A2)<<endl;
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 5 3 
 *
 * OUTPUT
 * 125
 * 
 */