#include "../../include/preprocessing/imputer.h"
#include "../../include/utils/utils.h"

void SimpleImputer::fitTransform(vector<vector<double>> &data)
{
    fit(data);
    transform(data);
}

void SimpleImputer::fit(const vector<vector<double>> &data)
{
    int numColumns = data[0].size();
    columnMeans.resize(numColumns, 0.0);
    vector<int> count(numColumns, 0);
    for (auto &row : data)
    {
        for (int j = 0; j < numColumns; j++)
        {
            if (!isnan(row[j]))
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
            columnMeans[j] = 0.0;
        }
    }
}
void SimpleImputer::transform(vector<vector<double>> &data)
{
    int numColumns = data[0].size();
    for (auto &row : data)
    {
        for (int j = 0; j < numColumns; j++)
        {
            if (isnan(row[j]))
            {
                row[j] = columnMeans[j];
            }
        }
    }
}

double KNNImputer::distance(const vector<double> &a, const vector<double> &b)
{
    int sum = 0;
    int count = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (!isnan(a[i]) && !isnan(b[i]))
        {
            sum += (a[i] - b[i]) * (a[i] - b[i]);
            count++;
        }
    }
    return count > 0 ? sqrt(sum) / count : 0.0;

    // need a built in sqrt function
}

vector<int> KNNImputer::findKNearestNeighbors(const vector<vector<double>> &data, int targetRowIndex)
{
    vector<pair<double, int>> distances;

    for (int i = 0; i < data.size(); i++)
    {
        if (i != targetRowIndex)
        {
            double dist = distance(data[targetRowIndex], data[i]);
            distances.push_back(make_pair(dist, i));
        }
    }

    quickSort(distances, 0, distances.size() - 1);

    vector<int> neighbors;
    for (int i = 0; i < k && i < distances.size(); i++)
    {
        neighbors.push_back(distances[i].second);
    }
    return neighbors;
}

void KNNImputer::transform(vector<vector<double>> &data)
{
    int numRows = data.size();
    int numCols = data[0].size();

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            if (isnan(data[i][j]))
            {
                vector<int> neighbors = findKNearestNeighbors(data, i);
                double sum = 0.0;
                int count = 0;
                for (int neighborIndex : neighbors)
                {
                    if (!isnan(data[neighborIndex][j]))
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
                    data[i][j] = 0.0;
                }
            }
        }
    }
}
