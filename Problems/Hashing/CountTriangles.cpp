
/**
 * @file CountTriangles.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-23
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given N cartesian points in 2D plane, find the number of right angled triangles such that the base or perpendicular is parallel to X or Y axis  
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int count_triangles(vector<pair<int,int>> &points)
{   
    unordered_map<int int>vx,vy;
    
    for(auto it : points)
    {
        vx[it.first]++;
        vy[it.second]++;
    }

    int ans = 0;

    for(auto it:points)
    {
        int x = it.first;
        int y = it.second;

        int fx = vx[x];
        int fy = vy[y];

        ans += (fx-1)*(fy-1);
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<pair<int,int>>coor;

    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        coor.push_back({x,y});
    }

    cout<<count_triangles(coor)<<endl;

    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 5
 * 1 2
 * 2 1
 * 2 2
 * 2 3
 * 3 2
 * 
 * OUTPUT
 * 4
 * 
 */


