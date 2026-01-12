#pragma once
#include <vector>
using namespace std;

void splitFeatureAndTarget(const vector<vector<double>> &dataset,
                           vector<vector<double>> &X,
                           vector<double> &y);