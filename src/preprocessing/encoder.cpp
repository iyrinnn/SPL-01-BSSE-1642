#include "../include/preprocessing/encoder.h"

void Encoder::labelEncode(vector<vector<string>> &data, const vector<int> &categoricalCols)
{
    vector<string> uniqueValues;

    for (auto colIndex : categoricalCols)
    {
        for (auto &row : data)
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
    }

    for (auto &row : data)
    {
        for (auto colIndex : categoricalCols)
        {
            string value = row[colIndex];
            for (int i = 0; i < uniqueValues.size(); ++i)
            {
                if (uniqueValues[i] == value)
                {
                    row[colIndex] = to_string(i);
                    break;
                }
            }
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
