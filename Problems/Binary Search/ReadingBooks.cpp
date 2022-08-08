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

bool isPossible(vector<int> &books,int m,int mid){
    
    int n = books.size();
    int cs = 0;
    int students = 1;
    
    for(int i = 0; i < n; i++){
        
        if(cs + books[i] > mid){
            students++;
            cs = books[i];
            
            if(students > m){
                return false;
            }
        }
        else{
            cs += books[i];
        }
    }
    
    return true;
}


int minPages(vector<int> books, int m){
    int n = books.size();
    //complete this code
    int end = 0;
    int start = 0;
    
    for(int b:books){
        end += b;
        start = max(start,b);
    }
    int result = INT_MAX;
    
    while(start<=end){
        int mid = (start + end)/2;
        if(isPossible(books,m,mid)){
            result = min(result,mid);
            end = mid - 1;
        }
        
        else{
            start = mid + 1;
        }
    }
    return result;
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

    cout<<minPages(arr,stu)<<endl;

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