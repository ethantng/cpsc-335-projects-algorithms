// ===================================================
// Attached: Project 3
// ===================================================
// Program: Algorithm 1: The Spread of Fire in a Forest
// ===================================================
// Programmer: Ethan Nguyen (816500144)
// Class: CPSC 335-1 13503 - Algorithm Engineering
// ===================================================

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//0 = empty, 1 = healthy, 2 = burning
int minDaysBurnHealthyTrees(vector<vector<int>>& forest) 
{
    int rows = forest.size();
    int cols = forest[0].size(); //dimensions for 2d forest grid

    queue<pair<int, int>> q; //queue for breadth-first search for burning
    int healthyTrees = 0;

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            if (forest[i][j] == 2) 
            {
                q.push({i, j}); //initial burning trees in queue
            } 
            else if (forest[i][j] == 1) 
            {
                healthyTrees++; //num healthy trees
            }
        }
    }

    if (healthyTrees == 0) return 0; //no trees to burn
    if (q.empty()) return -1;

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int days = 0; //count for days to burn all healthy trees

    while (!q.empty()) 
    {
        int size = q.size();
        bool burnedToday = false; //check if any tree burned on that day

        for (int i = 0; i < size; ++i) 
        {
            auto [x, y] = q.front();
            q.pop(); //next burning tree

            for (auto [dx, dy] : directions) 
            {
                int newX = x + dx;
                int newY = y + dy;

                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && forest[newX][newY] == 1) 
                {
                    forest[newX][newY] = 2; //burning
                    healthyTrees--; //minus healthy tree
                    q.push({newX, newY}); //add burning tree
                    burnedToday = true;
                }
            }
        }

        if (burnedToday) days++;
    }

    return healthyTrees == 0 ? days : -1;
}

int main() 
{
    vector<vector<int>> forest1 = 
    {
        {2,1,1},//standard example
        {1,1,0},
        {0,1,1}
        
    };

    vector<vector<int>> forest2 = 
    {
        {2,1,1},//not all trees can burn
        {0,1,1},
        {1,0,0}
        
    };

    vector<vector<int>> forest3 = 
    {
        {0,2}//no healthy trees
        
    };

    cout << "Test Case 1 Output: " << minDaysBurnHealthyTrees(forest1) << endl;
    cout << "Test Case 2 Output: " << minDaysBurnHealthyTrees(forest2) << endl;
    cout << "Test Case 3 Output: " << minDaysBurnHealthyTrees(forest3) << endl;

    return 0;
}


// ===================================================
//OUTPUT:
//Test Case 1 Output: 4
//Test Case 2 Output: -1
//Test Case 3 Output: 0
//
// ===================================================

