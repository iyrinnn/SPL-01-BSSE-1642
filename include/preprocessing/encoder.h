#pragma once
#include <vector>
#include <string>
using namespace std;

class Encoder
{
public:
    void labelEncode(vector<vector<string>> &data, const vector<int> &categoricalCols);
    void oneHotEncode(vector<vector<string>> &data, int colIndex);
    void ordinalEncode(vector<vector<string>> &data, vector<string> &order, int colIndex);
};