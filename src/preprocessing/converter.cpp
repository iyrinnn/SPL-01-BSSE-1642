#include "../../include/preprocessing/converter.h"

vector<vector<double>> Converter::toDouble(const vector<vector<string>> &data)
{
    vector<vector<double>> numericData;

    for (int i = 0; i < data.size(); i++)
    {
        vector<double> row;

        for (int j = 0; j < data[i].size(); j++)
        {
            double value;
            string valStr = data[i][j];

            // Check for missing
            if (valStr == "MISSING" || valStr == "NA" || valStr.empty())
            {
                value = numeric_limits<double>::quiet_NaN(); // Use NaN
            }
            else
            {
                stringstream ss(valStr);
                ss >> value;
                if (ss.fail()) // just in case
                    value = numeric_limits<double>::quiet_NaN();
            }

            row.push_back(value);
        }

        numericData.push_back(row);
    }

    return numericData;
}
