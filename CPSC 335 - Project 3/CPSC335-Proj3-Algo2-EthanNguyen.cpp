// ===================================================
// Attached: Project 3
// ===================================================
// Program: Algorithm 2: Delivery Route Planning
// ===================================================
// Programmer: Ethan Nguyen (816500144)
// Class: CPSC 335-1 13503 - Algorithm Engineering
// ===================================================

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

int findCheapestRoute(int n, vector<vector<int>>& routes, int src, int dst, int k) 
{
    vector<vector<pii>> graph(n); //make graph as adjacency list
    for (const auto& route : routes) 
    {
        int from = route[0], to = route[1], price = route[2];
        graph[from].emplace_back(to, price); // add route
    }
    
    // min-heap priority queue, check least-cost path
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq; 
    pq.emplace(0, src, 0);

    vector<int> visited(n, INT_MAX); //check least-cost for each node
    visited[src] = 0;

    while (!pq.empty()) //process priority queue
    {
        auto [cost, node, stops] = pq.top();
        pq.pop();

        if (node == dst) return cost; // if destination reached, cost returned
        if (stops > k) continue; // skip path if more than k stops

        for (const auto& [neighbor, price] : graph[node]) //check neighbor nodes
        {
            int newCost = cost + price;
            if (newCost < visited[neighbor] || stops < k) 
            {
                visited[neighbor] = newCost;
                pq.emplace(newCost, neighbor, stops + 1);
            }
        }
    }

    return -1; //unreachable
}

int main() 
{
    vector<vector<int>> routes1 = 
    {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500}
        
    };

    cout << "Test Case 1 Output: " << findCheapestRoute(3, routes1, 0, 2, 1) << endl;
    cout << "Test Case 2 Output: " << findCheapestRoute(3, routes1, 0, 2, 0) << endl;
    cout << "Test Case 3 Output: " << findCheapestRoute(3, routes1, 0, 3, 1) << endl;
    
    return 0;
    
}


// ===================================================
//OUTPUT:
//Test Case 1 Output: 200
//Test Case 2 Output: 500
//Test Case 3 Output: -1
//
// ===================================================

