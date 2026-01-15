#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <limits> 
using namespace std;

class Converter
{
public:
    static vector<vector<double>>
    toDouble(const vector<vector<string>> &data);
};

// toDouble()
// toInt()
// toSparse()
// toMatrix()
// toCategorical()