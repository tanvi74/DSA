/**
 * @file Sudoku.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-17
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given a partial filled sudoku matrix 9*9. Write a function to fill the matrix using sudoku rules
 * 
 */


#include<bits/stdc++.h>
using namespace std;

bool isSafe(int mat[][9], int i, int j, int no, int N )
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

bool solveSudoku(int mat[][9], int i, int j, int N)
{
    // Base Case
    if(i==N)
    {
        // Print the solution
        for(int i1=0;i1<N;i1++)
        {
            for(int j1=0;j1<N;j1++)
            {
                cout<<mat[i1][j1]<<" ";
            }
            cout<<endl;
        }

        // Return true
        return true;
    }

    // Recursive Case
    if(j==N)
    {
        return solveSudoku(mat, i+1, 0, N);
    }

    // Skip the prefilled cell
    if(mat[i][j] != 0)
    {
        return solveSudoku(mat, i, j+1, N);
    }

    // Cell to be filled 
    // Try out all possiblities
    for(int k=1; k<=N; k++)
    {
        if(isSafe(mat, i, j, k, N))
        {
            mat[i][j] = k;
            bool solveSubproblem = solveSudoku(mat, i, j+1, N);

            if(solveSubproblem)
                return true;
        }
    }

    // if no option works
    mat[i][j] = 0;
    return false;


}

int main()
{
    int N=9;
    int mat[N][N];

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>mat[i][j];
        }
    }

    if(!solveSudoku(mat, 0 ,0 N))
    {
        cout<<"No solution exist"<<endl;
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