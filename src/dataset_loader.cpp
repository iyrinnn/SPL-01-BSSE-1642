#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

// struct DataFrame
// {
//     vector<string> columnNames;    // stores column header
//     vector<vector<string>> values; // rows of data

//     vector<string> &getRow(int row, int col)
//     {
//         return values[row];
//     }

//     string &getRow(int row, int col)
//     {
//         return values[row][col];
//     }
// }



 vector<vector<string>> fileRead (string fileName){


    ifstream file(fileName);

    if(!file.is_open()){
        cerr << "Failed to open file: "  << fileName << endl;
    }

    vector<vector<string>> dataset;
    string line;
    while (getline(file, line)){
        stringstream ss(line);
        vector<string> row;
        string cell;

        while (getline(ss, cell, ',')){
            row.push_back(cell);
        }

        dataset.push_back(row);

    }

    return dataset;
}



int main()
{
    string fileName = " ";
    ifstream file(fileName);

    if (!file.is_open())
    {
        cerr << "Failed to open file: " << fileName << endl;
    }

    stringstream buffer;
    buffer << file.rdbuf();
    // here we are using vector which i am not sure of whether i am allowed to or not
    vector<string> fileContent;
    string intermediate;
    while (buffer >> intermediate)
    {
        fileContent.push_back(intermediate);
    }

    file.close();
}