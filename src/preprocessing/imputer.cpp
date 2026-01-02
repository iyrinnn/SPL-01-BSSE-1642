#pragma once
#include <vector>
#include <string>
using namespace std;

class Imputer
{
public:
};

class SimpleImputer : public Imputer
{
private:
    vector<double> columnMeans;
    int missingValue = -1; // Define a constant to represent missing values

public:
    void fitTransform(vector<vector<double>> &data)
    {
        fit(data);
        transform(data);
    }

    void fit(const vector<vector<double>> &data)
    {
        int numColumns = data[0].size();
        columnMeans.resize(numColumns, 0.0);
        vector<int> count(numColumns, 0);
        for (auto &row : data)
        {
            for (int j = 0; j < numColumns; j++)
            {
                if (row[j] != missingValue)
                {
                    columnMeans[j] += row[j];
                    count[j]++;
                }
            }
        }
        for (int j = 0; j < numColumns; j++)
        {
            if (count[j] > 0)
            {
                columnMeans[j] /= count[j];
            }
            else
            {
                columnMeans[j] = 0.0; // or some default value
            }
        }
    }
    void transform(vector<vector<double>> &data)
    {
        int numColumns = data[0].size();
        for (auto &row : data)
        {
            for (int j = 0; j < numColumns; j++)
            {
                if (row[j] == missingValue)
                {
                    row[j] = columnMeans[j];
                }
            }
        }
    }
};

class KNNImputer : public Imputer
{
    int k;
    int missingValue;

public:
    KNNImputer(int k_neighbors) : k(k_neighbors), missingValue(-1)
    {
    }

    double distance(const vector<double> &a, const vector<double> &b)
    {
        int sum = 0;
        int count = 0;

        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != missingValue && b[i] != missingValue)
            {
                sum += (a[i] - b[i]) * (a[i] - b[i]);
                count++;
            }
        }
        return count > 0 ? sqrt(sum) / count : 0.0;

        // need a built in sqrt function
    }

    vector<int> findKNearestNeighbors(const vector<vector<double>> &data, int targetRowIndex)
    {
        vector<pair<double, int>> distances; // pair of (distance, index)

        for (int i = 0; i < data.size(); i++)
        {
            if (i != targetRowIndex)
            {
                double dist = distance(data[targetRowIndex], data[i]);
                distances.push_back(make_pair(dist, i));
            }
        }

        sort(distances.begin(), distances.end());

        // sort function needed

        vector<int> neighbors;
        for (int i = 0; i < k && i < distances.size(); i++)
        {
            neighbors.push_back(distances[i].second);
        }
        return neighbors;
    }

    void transform(vector<vector<double>> &data)
    {
        int numRows = data.size();
        int numCols = data[0].size();

        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < numCols; j++)
            {
                if (data[i][j] == missingValue)
                {
                    vector<int> neighbors = findKNearestNeighbors(data, i);
                    double sum = 0.0;
                    int count = 0;
                    for (int neighborIndex : neighbors)
                    {
                        if (data[neighborIndex][j] != missingValue)
                        {
                            sum += data[neighborIndex][j];
                            count++;
                        }
                    }
                    if (count > 0)
                    {
                        data[i][j] = sum / count;
                    }
                    else
                    {
                        data[i][j] = 0.0; // or some default value
                    }
                }
            }
        }
    }
};

class IterativeImputer : public Imputer
{
};
