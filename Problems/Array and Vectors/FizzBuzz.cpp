/** Write a FizzBuzz function that returns a vector<string> with the numbers from 1 to n with the following restrictions:
 * for multiples of 3 store "Fizz" instead of a number
 * for multiples of 5 store "Buzz" instead of a number
 * for multiples of 3 & 5 store "FizzBuzz" instead of a number
 **/


#include<bits/stdc++.h>
using namespace std;

vector<string> fizzbuzz(int n)
{    
    vector<string>ans;
    for(int i=1;i<=n;i++)
    {
        if(i%3 == 0 && i%5 == 0)
        {
            ans.push_back("FizzBuzz");
        }
        else if(i%3 == 0)
        {
            ans.push_back("Fizz");
        }
        else if(i%5 == 0)
        {
            ans.push_back("Buzz");
        }
        else
        {
            auto s = std::to_string(i);
            ans.push_back(s);
        }
    }
    return ans;
}

int main()
{
    int N;
    cin>>N;
    vector<string>ans;
    ans = fizzbuzz(N);

    for(int i=0;i<N;i++)
        cout<<ans[i]<<" ";

    cout<<endl;
}

/**
 * @brief 
 * Input
 * 15
 * 
 * Output
 * 1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 
 * 
 */