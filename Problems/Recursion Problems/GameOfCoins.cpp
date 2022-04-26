/**
 * @file GameOfCoins.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 * Oswald and Henry are playing the game of coins. They have a row of 'n' coins [C1,C2,C3...Cn] with values [V1,V2,V3...Vn] where Ci coin has Vi value. They take turns alternatively. In one turn the player can pick either the first or the last coin of the row. Given both Oswald and Henry are very smart players, you need to find the maximum possible value Oswald can earn if he plays first.
 * 
 * INPUT FORMAT
 * In the function you are given an integer N i.e. the number of coins and a vector V which represents the values of each coin in the row respectively.
 * 
 * OUTPUT FORMAT
 * Return a single integer which is the maximum possible value as asked in the question.
 * 
 * CONSTRAINT
 * 1<=N<=15
 * 1<=V[i]<=1000
 * 
 */


#include<bits/stdc++.h>
using namespace std;

int MaxValue(int n, vector<int> arr)
{
    int table[n][n];

    for (int gap = 0; gap < n; ++gap) {
        for (int i = 0, j = gap; j < n; ++i, ++j) 
        {
            int x = ((i + 2) <= j)
                        ? table[i + 2][j]
                        : 0;
            int y = ((i + 1) <= (j - 1))
                        ? table[i + 1][j - 1]
                        : 0;
            int z = (i <= (j - 2))
                        ? table[i][j - 2]
                        : 0;
 
            table[i][j] = max(
                arr[i] + min(x, y),
                arr[j] + min(y, z));
        }
    }
 
    return table[0][n - 1];
    
}

int main()
{
    int N;
    cin>>N;

    int A;
    vector<int> arr;
    for(int i=0;i<N;i++)
    {
        cin>>A;
        arr.push_back(A);
    }

    cout<<MaxValue(N,arr)<<endl;
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 4
 * 1 2 3 4
 *
 * OUTPUT
 * 6
 * 
 */