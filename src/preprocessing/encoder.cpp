#include "../include/preprocessing/encoder.h"
#include <map>

void Encoder::labelEncode(vector<vector<string>> &data, const vector<int> &categoricalCols)
{
    
    for (auto colIndex : categoricalCols)
    {
        map<string, int> valueToLabel;
        int labelCounter = 0;

        
        for (auto &row : data)
        {
            string value = row[colIndex];
            if (valueToLabel.find(value) == valueToLabel.end())
            {
                valueToLabel[value] = labelCounter++;
            }
        }

        
        for (auto &row : data)
        {
            string value = row[colIndex];
            row[colIndex] = to_string(valueToLabel[value]);
        }
    }
}

void Encoder::oneHotEncode(vector<vector<string>> &data, int colIndex)
{
    vector<string> uniqueValues;
    for (const auto &row : data)
    {
        string value = row[colIndex];
        bool found = false;
        for (const auto &uniqueValue : uniqueValues)
        {
            if (uniqueValue == value)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            uniqueValues.push_back(value);
        }
    }

    vector<vector<string>> newData;

    for (auto &row : data)
    {
        vector<string> newRow;
        for (int i = 0; i < row.size(); ++i)
        {
            if (i == colIndex)
            {
                for (const auto &uniqueValue : uniqueValues)
                {
                    if (row[i] == uniqueValue)
                    {
                        newRow.push_back("1");
                    }
                    else
                    {
                        newRow.push_back("0");
                    }
                }
            }
            else
            {
                newRow.push_back(row[i]);
            }
        }
        newData.push_back(newRow);
    }

    data = newData;
}

void Encoder::ordinalEncode(vector<vector<string>> &data, vector<string> &order, int colIndex)
{
    for (auto &row : data)
    {
        string value = row[colIndex];
        for (int i = 0; i < order.size(); ++i)
        {
            if (order[i] == value)
            {
                row[colIndex] = to_string(i);
                break;
            }
        }
    }
}
