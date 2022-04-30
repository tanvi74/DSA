/**
 * @file AdvancedGameOfCoins.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-20
 * 
 * @copyright Copyright (c) 2022
 * 
 * Oswald and Henry are again playing the game of coins. They have a row of 'n' coins [C1,C2,C3...Cn] with values [V1,V2,V3...Vn] where Ci coin has Vi value. They take turns alternatively. In one turn the player can pick either the first or the last coin of the row and he is supposed to do it 'k' times in a turn. Given both Oswald and Henry are very smart players, you need to find the maximum possible value Oswald can earn if he plays first.
 * 
 * INPUT FORMAT
 * In the function you are given an integer N i.e. the number of coins, an integer K which is number of pickups in one turn and a vector V which represents the values of each coin in the row respectively.
 * 
 * OUTPUT FORMAT
 * Return a single integer which is the maximum possible value as asked in the question.
 * 
 * CONSTRAINT
 * 1<=N<=15
 * 1<=K<=N
 * 1<=V[i]<=1000
 * 
 */


#include<bits/stdc++.h>
using namespace std;

int MaxValue(int n, vector<int> v, int k)
{
    
}

int main()
{
    int N,K,A;
    cin>>N>>K;

    vector<int>arr;

    for(int i=0;i<N;i++)
    {
        cin>>A;
        arr.push_back(A);
    }

    cout<<MaxValue(N,arr,K)<<endl;

    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 6 2
 * 10 15 20 9 2 5
 *
 * OUTPUT
 * 32
 * 
 */