// ===================================================
//Attached: Project 1
// ===================================================
//Program: Algorithm 1: Greedy Approach to Hamiltonian Problem
// ===================================================
//Programmer: Ethan Nguyen (816500144)
//Class: CPSC 335-1 13503 - Algorithm Engineering
// ===================================================

#include <iostream>
#include <vector>
using namespace std;

int findTheStartingCity(const vector<int>& city_distances, const vector<int>& fuel, int mpg) //find starting city function
{
    int totFuel = 0; 
    int fuelNow = 0;
    int startCity = 0;
    
    for (int i = 0; i < city_distances.size(); i++) //loop to track fuel
    {
        int fuelGet = fuel[i] * mpg;
        int fuelLost = city_distances[i];
        
        totFuel += fuelGet - fuelLost;
        fuelNow += fuelGet - fuelLost;
        
        if (fuelNow < 0) //if the fuel is below 0, we simulate the next city
        {
            startCity = i + 1;
            fuelNow = 0; //reset fuel
        }
    }
    
    return startCity;
}

int main() 
{
    vector<int> city_distances = {5, 25, 15, 10, 15}; //sample input
    vector<int> fuel = {1, 2, 1, 0, 3};
    int mpg = 10;

    int prefCity = findTheStartingCity(city_distances, fuel, mpg);
    cout << "The preferred starting city is: " << prefCity << endl;

    return 0;
}


// ===================================================
//OUTPUT:
//The preferred starting city is: 4
//
// ===================================================

