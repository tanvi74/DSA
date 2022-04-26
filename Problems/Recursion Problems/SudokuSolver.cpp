/**
 * @file SudokuSolver.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-17
 * 
 * @copyright Copyright (c) 2022
 * 
 * You are given a 9X9 2D array which is partially filled. Your aim is to completely fill the grid from digits from 1 to 9 such that every row, column and sub-grid of size 3X3 (as shown) contains all digits from 1 to 9 exactly once.
 * 
 * IMAGE: https://img-c.udemycdn.com/redactor/raw/coding_exercise_instructions/2021-05-09_17-55-06-9a06ca50cd3456c2426c60ea371c1acb.gif
 * 
 * INPUT: 
 * Input will have 2D vector(9X9 matrix) containing integers from 0 to 9 where 0 represents empty cell and other integers represent already filled cells.
 * 
 * OUTPUT:
 * Return a solved 2D vector(matrix).
 * 
 * 
 */


#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> mat, int i, int j, int no, int N )
{
    // Checking for row and col
    for(int k=0;k<N;k++)
    {
        if(mat[k][j]==no || mat[i][k]==no)
            return false;
    }

    // Checking for subgrid
    int sx = (i/3)*3;
    int sy = (j/3)*3;

    for(int x=sx;x<sx+3;x++)
    {
        for(int y = sy; y<sy+3; y++)
        {
            if(mat[x][y]==no)
                return false;
        }
    }

    return true;

}

bool solve(vector<vector<int>>& mat , int i, int j, int N)
{
    // Base Case
    if(i==N)
    {
        // Return true
        return true;
    }

    // Recursive Case
    if(j==N)
    {
        return solve(mat, i+1, 0, N);
    }

    // Skip the prefilled cell
    if(mat[i][j] != 0)
    {
        return solve(mat, i, j+1, N);
    }

    // Cell to be filled 
    // Try out all possiblities
    for(int k=1; k<=N; k++)
    {
        if(isSafe(mat, i, j, k, N))
        {
            mat[i][j] = k;
            bool solveSubproblem = solve(mat, i, j+1, N);

            if(solveSubproblem)
                return true;
        }
    }

    // if no option works
    mat[i][j] = 0;
    return false;


}


vector<vector<int> > solveSudoku(vector<vector<int> > input){
    
    solve(input, 0,0, input.size());
    
    return input;
    
}

int main()
{
    int N=9, x;
    vector<vector<int>> mat,ans;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>x;
            mat[i][j] = x;
        }
    }

    ans = solveSudoku(mat);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<ans[i][j];
        }
        cout<<endl;
    }

    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 030000900
 * 006000000
 * 000241030
 * 000900700
 * 000002004
 * 080070020
 * 850000000
 * 090704000
 * 000006001
 *
 * OUTPUT
 * 132567948
 * 546389217
 * 978241635
 * 264918753
 * 715632894
 * 389475126
 * 857123469
 * 691754382
 * 423896571
 * 
 */