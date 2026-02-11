// ===================================================
// Attached: Project 2
// ===================================================
// Program: Algorithm 1: Target Terms or Substrings
// ===================================================
// Programmer: Ethan Nguyen (816500144)
// Class: CPSC 335-1 13503 - Algorithm Engineering
// ===================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> parseWordList(const string& line) // parsing B to remove unnecessary characters
{
    vector<string> words;
    string word;
    string cleaned = line.substr(1, line.length() - 2);

    stringstream ss(cleaned);
    while (getline(ss, word, ',')) 
    {
        word.erase(remove(word.begin(), word.end(), '\''), word.end());
        word.erase(0, word.find_first_not_of(" "));
        words.push_back(word);
    }
    return words;
}

void findTargetWords(const string& A, const vector<string>& B, vector<int>& output_order, vector<string>& output_array) 
{
    vector<pair<int, string>> paired; // pair is index and city name

    for (const string& word : B) 
    {
        size_t index = A.find(word);
        if (index != string::npos) 
        {
            paired.emplace_back(index, word);
        }
    }

    sort(paired.begin(), paired.end());

    output_order.clear();
    output_array.clear();
    output_order.reserve(paired.size());
    output_array.reserve(paired.size());

    for (const auto& p : paired) 
    {
        output_order.push_back(p.first);
        output_array.push_back(p.second);
    }
}

int main() 
{
    ifstream inputFile("in2a.txt");
    ofstream outputFile("out2a.txt");

    if (!inputFile.is_open()) 
    {
        cerr << "ERROR" << endl;
        return 1;
    }
    if (!outputFile.is_open()) 
    {
        cerr << "ERROR" << endl;
        return 1;
    }

    string A, B_line;
    vector<int> output_order;
    vector<string> output_array;
    int array_count = 0;

    while (getline(inputFile, A) && getline(inputFile, B_line)) 
    {
        vector<string> B = parseWordList(B_line);

        findTargetWords(A, B, output_order, output_array);

        outputFile << "Results for Array " << ++array_count << ":\n";
        outputFile << "Output_order = [";
        for (size_t i = 0; i < output_order.size(); ++i) 
        {
            outputFile << output_order[i] << (i < output_order.size() - 1 ? ", " : "");
        }
        outputFile << "]\n";

        outputFile << "Output_array = [";
        for (size_t i = 0; i < output_array.size(); ++i) 
        {
            outputFile << "'" << output_array[i] << "'" << (i < output_array.size() - 1 ? ", " : "");
        }
        outputFile << "]\n\n";
    }

    inputFile.close();
    outputFile.close();
    cout << "COMPLETE - REVIEW 'out2a.txt'" << endl;

    return 0;
}

// ===================================================
//in2a.txt
//
//sanoaklandrialtofullertonmarcolongbreacoronamodestoclovissimithousand
//['brea', 'modesto', 'clovis', 'corona']
//marcopolmonafremontrialtofullertonmarcolongfresnochinoclovissimisalinas
//['fullerton', 'chino', 'fremont', 'fresno']
//torranceoaklandrialtomarcooxnardchinofresnoirvineclovissimiorange
//['oxnard', 'irvine', 'orange', 'marco']
//
// ===================================================


// ===================================================
//out2a.txt
//
//Results for Array 1:
//Output_order = [34, 44, 51]
//Output_array = ['brea', 'modesto', 'clovis']
//
//Results for Array 2:
//Output_order = [12, 25, 49]
//Output_array = ['fremont', 'fullerton', 'chino']
//
//Results for Array 3:
//Output_order = [26, 43, 59]
//Output_array = ['oxnard', 'irvine', 'orange']
//
// ===================================================


