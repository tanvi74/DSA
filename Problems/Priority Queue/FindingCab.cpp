
/**
 * @file FindingCab.cpp
 * @author Tanvi (tanvi.agrawal@byjus.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-19
 * 
 * @copyright Copyright (c) 2022
 * 
 * Given N cartesian points in 2D plane, each represents the location of the cab. You are standing at origin, you want to know the names of the nearest K cars 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Car
{
    public: 
            string id;
            int x,y;

            Car(string id, int x, int y)
            {
                this->id = id;
                this->x = x;
                this->y = y;
            }

            int dist const()
            {
                return x*x + y*y;
            }
};

class  CarCompare
{
    public: 
            bool operator()(const Car A, const Car B)
            {
                return A.dist() < B.dist();
            }
}

void printNearestCars(vector<Car>cars, int K)
{
    // Create a max heap of size K
    priority_queue<Car, vector<Car>cars, CarCompare> max_heap(cars.begin(), cars.begin()+K);

    // Remaining Cars
    for(int i=K; i<cars.size(); i++)
    {
        auto car = cars[i];

        if(car.dist() < max_heap.top().dist())
        {
            max_heap.pop();     // Remove the largest node
            max_heap.push(car);
        }
    }

    // Print all the cars inside the heap they will be the smallest;
    vector<Car> output;
    while(!max_heap.empty())
    {
        output.push_back(max_heap.top());
        max_heap.pop();
    }

    reverse(output.begin(), output.end());

    for(auto car : output)
    {
        cout<<car.id<<endl;
    }

    return;

}

int main()
{
    int N, K;
    cin>>N>>K;

    string d;
    int x,y;

    vector<Car>cars;

    for(int i=0;i<N;i++)
    {
        cin>>d>>x>>y;
        Car car(d,x,y);
        cars.push_back(car);
    }

    printNearestCars(cars,K);

    return 0;
}

/**
 * @brief EXAMPLE
 * 
 * INPUT
 * 5 3
 * C1 1 1
 * C2 2 1
 * C3 3 2
 * C4 0 1
 * C5 2 3
 * 
 * OUTPUT
 * C4
 * C1
 * C2
 * 
 */

