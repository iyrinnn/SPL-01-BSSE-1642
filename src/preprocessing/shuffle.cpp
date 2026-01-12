#include "../../include/preprocessing/shuffle.h"
#include <stdlib.h>

void shuffleData(vector<vector<double>> &X, vector<double> &y, int seed)
{
    srand(seed);
    int n = X.size();

    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(X[i], X[j]);
        swap(y[i], y[j]);
    }
}