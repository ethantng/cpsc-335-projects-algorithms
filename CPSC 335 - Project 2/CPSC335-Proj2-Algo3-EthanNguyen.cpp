// ===================================================
// Attached: Project 2
// ===================================================
// Program: Algorithm 3: Merging Techniques
// ===================================================
// Programmer: Ethan Nguyen (816500144)
// Class: CPSC 335-1 13503 - Algorithm Engineering
// ===================================================

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct HeapNode 
{
    int value;
    int arrayIdx;
    int elementIdx;

    bool operator>(const HeapNode& other) const
    {
        return value > other.value;
    }
};

vector<int> mergeSortedArrays(const vector<vector<int>>& all_lists)
{
    priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode>> minHeap;
    vector<int> result;

    for (int i = 0; i < all_lists.size(); i++)
    {
        if (!all_lists[i].empty()) 
        {
            minHeap.push({all_lists[i][0], i, 0});
        }
    }

    while (!minHeap.empty()) 
    {
        HeapNode current = minHeap.top();
        minHeap.pop();

        result.push_back(current.value);

        if (current.elementIdx + 1 < all_lists[current.arrayIdx].size()) 
        {
            minHeap.push({all_lists[current.arrayIdx][current.elementIdx + 1], current.arrayIdx, current.elementIdx + 1});
        }
    }

    return result;
}

vector<vector<int>> parseInputFile(const string& filename)
{
    ifstream file(filename);
    vector<vector<int>> arrays;
    string line;
    
    while (getline(file, line))
    {
        if (line.find("[") != string::npos)
        {
            vector<int> tempArray;
            stringstream ss(line);
            string num;
            while (getline(ss, num, ','))
            {
                num.erase(remove(num.begin(), num.end(), '['), num.end());
                num.erase(remove(num.begin(), num.end(), ']'), num.end());
                num.erase(remove(num.begin(), num.end(), ' '), num.end());

                if (!num.empty())
                {
                    try
                    {
                        tempArray.push_back(stoi(num));
                    }
                    catch (const exception&)
                    {
                        cerr << "Invalid number format: " << num << endl;
                    }
                }
            }
            arrays.push_back(tempArray);
        }
    }
    
    return arrays;
}

int main() 
{
    vector<vector<int>> all_lists = parseInputFile("in2c.txt");

    vector<int> mergedList = mergeSortedArrays(all_lists);

    cout << "Merged List: ";
    for (int num : mergedList) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// ===================================================
//OUTPUT:
//Merged List: -10 -4 -3 -2 -1 0 0 0 2 2 2 3 4 4 5 5 6 6 6 7 7 8 9 9 10 10 10 11 11 12 12 12 14 15 17 18 19 20 20 21 21 24 25 29 29 81 81 88 121 121 131 150 
//
// ===================================================