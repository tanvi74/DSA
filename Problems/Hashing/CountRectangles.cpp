
/**
 * @file CountRectangles.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-23
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given N cartesian points in a 2D plane, find the number of axis parallel rectangles that can be formed.
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Point{
    public:
            int x,y;
            Point(int x, int y)
            {
                this->x = x;
                this->y = y;
            }
};

// Comparator
class Compare
{
    public: 
            bool operator()(const Point p1, const Point p2)
            {
                if(p1.x == p2.x)
                    return p1.y < p2.y;

                return p1.x < p2.x;
            }
}

int count_rectangles(vector<Point>points)
{
    // Insert all points in the set
    set<Point, Compare>S;

    for(Point p : points)
    {
        s.insert(p);
    }

    int ans = 0;

    // MAinlogic
    for(auto it = s.begin(); it!=prev(s.end()); it++)
    {
        for(auto jt = next(it); jt!=s.end(); jt++)
        {
            Point p1 = *it;
            Point p2 = *jt;

            // a check to determine if the points are not in the same line of axis
            if(p1.x == p2.x or p1.y == p2.y)
            {
                continue;
            }

            // Continue finding p3 and p4
            Point p3(p1.x,p2.y);
            Point p4(p2.x, p1.y);

            // Lookup
            if(s.find(p3) != s.end() and s.find(p4) != s.end())
            {
                ans++;
            }

        }
    }

    return ans/2;
}

int main()
{
    int N;
    cin>>N;

    int x,y;
    vector<Point>points;

    for(int i=0;i<N;i++)
    {
        cin>>x>>y;
        Point p(x,y);
        points.push_back(p);
    }

    cout<<count_rectangles(points)<<endl;

    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 8
 * 4 1
 * 4 0 
 * 0 0
 * 0 1
 * 1 1
 * 1 0 
 * 2 0
 * 2 1
 * 
 * OUTPUT
 * 6
 * 
 */


