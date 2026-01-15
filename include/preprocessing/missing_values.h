#pragma once
#include <vector>
#include <string>
using namespace std;

class MissingValuesUtils
{
public:
    static bool isMissing(string &value);
    static void dropMissing(vector<vector<string>> &dataset);
    static void fillMissing(vector<vector<string>> &dataset, string fillValue);
};

string standardizeCategory(string value);
void cleanCategoricalColumns(vector<vector<string>> &data,
                             vector<int> categoricalCols);
