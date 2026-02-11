// ===================================================
// Attached: Project 2
// ===================================================
// Program: Algorithm 2: Run Encoding Problem
// ===================================================
// Programmer: Ethan Nguyen (816500144)
// Class: CPSC 335-1 13503 - Algorithm Engineering
// ===================================================

#include <iostream>
#include <string>

using namespace std;

string runLengthEncoding(const string& S) 
{
    if (S.empty()) return "";

    string C = "";
    int count = 1;

    for (size_t i = 1; i < S.length(); i++) 
    {
        if (S[i] == S[i - 1]) 
        {
            count++;
        } else 
        {
            if (count > 1) 
            {
                C += to_string(count);
            }
            C += S[i - 1];
            count = 1;
        }
    }

    if (count > 1) // last char and #
    {
        C += to_string(count);
    }
    C += S[S.length() - 1];

    return C;
}

int main() 
{
    string test1 = "ddd";
    string test2 = "heloooooooo there";
    string test3 = "choosemeeky and tuition-free";

    cout << "Encoded 1: " << runLengthEncoding(test1) << endl;
    cout << "Encoded 2: " << runLengthEncoding(test2) << endl;
    cout << "Encoded 3: " << runLengthEncoding(test3) << endl;

    return 0;
}

// ===================================================
//OUTPUT:
//Encoded 1: 3d
//Encoded 2: hel8o there
//Encoded 3: ch2osem2eky and tuition-fr2e
//
// ===================================================

