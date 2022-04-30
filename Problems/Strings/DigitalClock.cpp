/**
 * @file DigitalClock.cpp
 * @author Tanvi 
 * @brief 
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 * You are building a login for the clock that requires you convert absolute time in minutes into a format supported by a digital clock.
 * 125 minutes can be displayed as 2:05
 * 155 minutes can be displayed as 2:35
 * 
 * (You can assume the maximum value of minutes will be less than 24 X 60)
 * 
 * 
 */


#include <bits/stdc++.h>
using namespace std;

string convert_to_digital_time(int N)
{
    int hr = N/60;
    int min = N%60;
   
    
    string ans = "";
    ans = to_string(hr);
    ans += ":";
    if(min<10){
        ans += '0';
    }
    
    ans += to_string(min);
    
    return ans;
}

int main()
{
    int N;
    cin>>N;
    string S = convert_to_digital_time(N);
    cout<<S<<endl;
    return 0;
}


/**
 * @brief 
 * INPUT
 * 1180
 * 
 * OUTPUT
 * 19:40
 * 
 */