/**
 * @file N-Queen.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-15
 * 
 * @copyright Copyright (c) 2022
 * 
 * N-Queen is the problem of placing N chess queens on N*N chessboard so that no 2 queens attack each other.
 * 
 * POSSIBLE VARIATIONS
 * -- Count all the possible options
 * -- Print any one of them
 * -- Print all of them
 * 
 */


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> result;

void printBoard(int N, int board[][20])
{
    vector<int> v;
        
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if (board[i][j] == 1)
                v.push_back(j + 1);

            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    result.push_back(v);
}

bool canPlace(int board[][20], int N, int x, int y)
{
    // In the same column
    for(int k=0;k<x;k++)
    {
        if(board[k][y]==1)
            return false;
    }

    // In the left diagonal
    int i=x;
    int j=y;

    while(i>=0 && j>=0)
    {
        if(board[i][j]==1)
        {
            return false;
        }
        i--;
        j--;
    }

    i=x;
    j=y;

    // Right diagonal
    while(i>=0 && j<N)
    {
        if(board[i][j]==1)
        {
            return false;
        }
        i--;
        j++;
    }

    return true;

}

bool solveNQueen(int N, int board[][20], int i)
{
    // Base Case
    if(i==N)
    {
        printBoard(N, board);
        
        return true;
    }

    // Recursive Case
    for(int j=0;j<N;j++)
    {
        // Whether the current pos is safe or not
        if(canPlace(board,N,i,j))
        {
            board[i][j] = 1;
            bool success = solveNQueen(N, board, i+1);
            if(success)
                return true;

            board[i][j] = 0;
        }
    }

    return false;
    
}

int main()
{
    int board[20][20] = {0};

    int N;
    cin>N;

    solveNQueen(N, board, 0);

    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 4
 *
 * OUTPUT
 * 0 1 0 0 
 * 0 0 0 1
 * 1 0 0 0
 * 0 0 1 0
 * 
 */