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



#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > result;

bool isSafe(vector<vector<int> > board,
            int row, int col)
{
    int i, j;
    int N = board.size();
 
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
 
    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
}
 
/* A recursive utility function to solve N
Queen problem */
bool solveNQUtil(vector<vector<int> >& board, int col)
{
    int N = board.size();
    if (col == N) {
        vector<int> v;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1)
                    v.push_back(j + 1);
            }
        }
        result.push_back(v);
        return true;
    }
 
    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            res = solveNQUtil(board, col + 1) || res;
            board[i][col] = 0; // BACKTRACK
        }
    }
 
    return res;
}

int nQueen(int n){
//Write your code below. Do not modify this function or parameters. You can use helper function if needed.
    result.clear();
    vector<vector<int> > board(n, vector<int>(n, 0));
 
    if (solveNQUtil(board, 0) == false) {
        return {};
    }
 
    sort(result.begin(), result.end());
    return result.size();

}

int main()
{
    int N;
    cin>N;

    // No of methods possible
    cout<<nQueen(N)<<endl;

    // No of methods
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
            cout<<result[i][j]<<" ";

        cout<<endl;
    }


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