/** 
 * You are actually very busy person. You have a long list of activities. Your aim is to finish much as activities as possible.
 * In the given figure, if you go to date with crush, you cannot participate in the coding contest and you can’t watch the movie. Also if you play DotA, you can’t study for the exam. If you study for the exam you can’t sleep peacefully. The maximum number of activities that you can do for this schedule is 3.
 *  
 * Either you can - 
 *      watch movie, play DotA and sleep peacefully (or)
 *      date with crush, play DotA and sleep peacefully
 * 
 * Image : https://img-c.udemycdn.com/redactor/raw/coding_exercise_instructions/2021-04-16_18-57-03-1cdc0c5414215f2da959a07b8f3d27bc.png
 * 
 * Given the start and finish times of activities, print the maximum number of activities. Input is already store in a vector of pairs. Each pair contains the start and end of the activity.
 * 
 * 
 **/

#include<bits/stdc++.h>
using namespace std;


bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

int countActivites(vector<pair<int,int> > act){
      
    sort(act.begin(), act.end(), sortbysec);
    
    int cnt = 1;
    int i = 0, j=1;
    
    while(j<act.size())
    {
        if(act[i].second<=act[j].first)
        {
            cnt++;
            i = j;
        }
        j++;
    }
    
    return cnt;
    

int main()
{
    int N;
    cin>>N;

    vector<pair<int,int>>A;

    int x,y;
    for(int i=0;i<N;i++)
    {
        cin>>x>>y;
        A.push_back({x,y})
    }

    int ans =  countActivites(A);
    
    cout<<ans<<endl;
}

/**
 * @brief 
 * Input
 * 6
 * [(7,9) (0,10) (4,5) (8,9) (4,10) (5,7)]
 * 
 * 
 * Output
 * 3
 * 
 */