#include "../../include/preprocessing/missing_values.h"
using namespace std;
#include <algorithm>

bool MissingValuesUtils::isMissing(string &value)
{

    if (value.empty() ||
        value == "NA" ||
        value == "NaN" ||
        value == "null" ||
        value == "NULL" ||
        value == "N/A" ||
        value == "missing" ||
        value == "?" ||
        value == "-")
    {
        return true;
    }
    return false;
}

void MissingValuesUtils::dropMissing(vector<vector<string>> &dataset)
{
    for (int i = 0; i < dataset.size();)
    {
        bool hasMissing = false;
        for (int j = 0; j < dataset[i].size(); j++)
        {
            if (isMissing(dataset[i][j]))
            {
                hasMissing = true;
                break;
            }
        }
        if (hasMissing)
        {
            dataset.erase(dataset.begin() + i);
        }
        else
        {
            i++;
        }
    }
}

void MissingValuesUtils::fillMissing(vector<vector<string>> &dataset, string fillValue)
{
    for (int i = 0; i < dataset.size(); i++)
    {
        for (int j = 0; j < dataset[i].size(); j++)
        {
            if (isMissing(dataset[i][j]))
            {
                dataset[i][j] = fillValue;
            }
        }
    }
}


string standardizeCategory(string value)
{
   
    transform(value.begin(), value.end(), value.begin(), ::tolower);

    
    if (value == "rce")
        return "rice";
    if (value == "dkaha" || value == "dhka")
        return "dhaka";
    if (value == "chittagng")
        return "chittagong";

    
    if (!value.empty())
    {
        value[0] = toupper(value[0]);
    }
    return value;
}

void cleanCategoricalColumns(vector<vector<string>> &data,
                             vector<int> categoricalCols)
{
    for (int colIdx : categoricalCols)
    {
        for (auto &row : data)
        {
            row[colIdx] = standardizeCategory(row[colIdx]);
        }
    }
}
