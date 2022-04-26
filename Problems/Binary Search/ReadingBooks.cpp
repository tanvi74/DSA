/**
 * @file ReadingBooks.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-20
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given number of pages in n different books and m students. The books are arranged in any order (not necessarily ascending) of number of pages. Every student is assigned to read some consecutive segments of books. The task is to assign books in such a way that the maximum number of pages assingned to a student is minimum. 
 * 
 * Find the maximum nummber of pages a student has to read. 
 * 
 */


#include<bits/stdc++.h>
using namespace std;

int reading_book(vector<int>arr, int N, int stu)
{

}

int main()
{
    int N,student,X;
    vector<int>arr;

    cin>>N>>student;

    for(int i=0;i<N;i++)
    {
        cin>>X;
        arr.push_back(X);
    }

    cout<<reading_book(arr,N,stu)<<endl;

    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 4 2
 * 10 20 30 15
 *
 * OUTPUT
 * 45
 * 
 */