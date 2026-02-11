// ===================================================
//Attached: Project 1
// ===================================================
//Program: Algorithm 2: Connecting Pairs of Persons
// ===================================================
//Programmer: Ethan Nguyen (816500144)
//Class: CPSC 335-1 13503 - Algorithm Engineering
// ===================================================

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int minSwaps(vector<int>& row) //find minimum number of swaps
{
    int n = row.size() / 2;
    unordered_map<int, int> position; //store positions of all people in row

    for (int i = 0; i < row.size(); i++) //index of each person
    {
        position[row[i]] = i;
    }

    int swaps = 0;

    for (int i = 0; i < row.size(); i += 2) //find paired seating
    {
        int first = row[i];
        int pair = first ^ 1;

        if (row[i + 1] != pair) //swap to find correct partner
        {
            swaps++;

            int partner = position[pair];

            swap(row[i + 1], row[partner]);

            position[row[partner]] = partner;
            position[row[i + 1]] = i + 1;
        }
    }

    return swaps;
}

int main() 
{
    vector<int> row1 = {0, 2, 1, 3}; //test case
    cout << "Output: " << minSwaps(row1) << endl;

    vector<int> row2 = {3, 2, 0, 1}; //test case
    cout << "Output: " << minSwaps(row2) << endl;

    return 0;
}


// ===================================================
//OUTPUT:
//Output: 1
//Output: 0
//
// ===================================================

