#pragma once
#include <vector>
#include <string>
#include <cmath>
#include "../utils/utils.h"
using namespace std;

class SimpleImputer
{ // using mean only ....i didnt include median and mode yet
private:
    vector<double> columnMeans;
    int missingValue = -1;

public:
    void fitTransform(vector<vector<double>> &data);
    void fit(const vector<vector<double>> &data);
    void transform(vector<vector<double>> &data);
};

class KNNImputer
{
private:
    int k;
    int missingValue;

    double distance(const vector<double> &a, const vector<double> &b);

    vector<int> findKNearestNeighbors(const vector<vector<double>> &data, int targetRowIndex);

public:
    KNNImputer(int k_neighbors) : k(k_neighbors), missingValue(-1)
    {
    }

    void transform(vector<vector<double>> &data);
};

class IterativeImputer
{
};
