#include "../../include/dataset/dataset_splitter.h"

void splitFeatureAndTarget(const vector<vector<double>> &dataset,
                           vector<vector<double>> &X,
                           vector<double> &y)
{
    int numRows = dataset.size();
    int numCols = dataset[0].size();

    X.resize(numRows, vector<double>(numCols - 1));
    y.resize(numRows);

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols - 1; j++)
        {
            X[i][j] = dataset[i][j];
        }
        y[i] = dataset[i][numCols - 1];
    }
}