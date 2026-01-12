#include "../../include/dataset/dataset_loader.h"

vector<vector<string>> fileRead(string fileName)
{
    ifstream file(fileName);

    if (!file.is_open())
    {
        cerr << "Failed to open file: " << fileName << endl;
    }

    vector<vector<string>> dataset;
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        vector<string> row;
        string cell;

        while (getline(ss, cell, ','))
        {
            row.push_back(cell);
        }

        dataset.push_back(row);
    }

    file.close();
    return dataset;
}