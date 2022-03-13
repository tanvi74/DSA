/**
 * @file ICPCStandings.cpp
 * @author Tanvi (1998tanvi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * Usually, results of competitions are based on the scores of participants. However, we are planning a change for the next year of ICPC. During the registration each team will be able to enter a single positive integer : their preferred place in the ranklist. We would take all these preferences into account, and at the end of the competition we will simply announce a ranklist that would please all of you.
 * But wait... How would that ranklist look like if it won't be possible to satisfy all the requests?
 * Suppose that we already have a ranklist. For each team, compute the distance between their preferred place and their place in the ranklist. The sum of these distances will be called the badness of this ranklist.
 * 
 * GOAL
 * Given team names and their preferred placements find one ranklist with the minimal possible badness.
 * 
 * 
 * 
 */


#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Another MEthod
 * 
 * 
 int badness(vector<pair<string,int> > teams){
    //Complete this function to return the min badness
    
    int N = teams.size();
    int cnt = 0;
    
    vector<pair<string,int> > Ti(N+1,{"nothing",0} );
    int j = 0;
    
    for(int i=0;i<N;i++)
    {
        int pos = teams[i].second;
        
        if(Ti[pos].second == 0)
        {
            Ti[pos] = teams[i];
        }
        else
        {
            int left = pos-1;
            int right = pos+1;
            while(1)
            {
                if(left<1 && right>N)
                    return -1;
                
                else if(left>=1 && Ti[left].second == 0)
                {
                    Ti[left] = teams[i];
                    break;
                }
                else if(right<=N && Ti[right].second == 0)
                {
                    Ti[right] = teams[i];
                    break;
                }
                left--;
                right++;
            }
        }
    }
    
    for(int i=1;i<=N;i++)
    {
        int s = abs(Ti[i].second-i);
        cnt+= s;
    }
     return cnt;
}

 */


bool compare(pair<string,int>A, pair<string,int>B)
{
    return A.second<B.second;
}

int badness(vector<pair<string,int> > teams)
{
    //Complete this function to return the min badness

    sort(teams.begin(), teams.end(), compare);
    int N = teams.size();
    int cnt = 0;
    
    for(int i=0;i<N;i++)
    {
        int s = abs(teams[i].second-(i+1));
        cnt+=s;
    }
    
     return cnt;
}

int main()
{
    int N,X;
    cin>>N;
    string S;

    vector<pair<string,int>>V;
    for(int i=0;i<N;i++)
    {
        cin>>S>>X;
        V.push_back({S,X});
    }
    cout<<badness(V)<<endl;
    return 0;
}


/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 7
 * WinOrBooze 1
 * BallOfDuty 2
 * WhoKnows 2
 * BholeChature 1
 * DCECoders 5
 * StrangeCase 7
 * WhoKnows 7
 * 
 * 
 * OUTPUT
 * 5
 * 
 */