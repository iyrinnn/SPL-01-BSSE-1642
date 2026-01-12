#include "../../include/preprocessing/splitter.h"
#include "../../include/preprocessing/shuffle.h"

using namespace std;

void train_test_split(const vector<vector<double>> &X, const vector<double> &y, vector<vector<double>> &X_train, vector<vector<double>> &X_test, vector<double> &y_train, vector<double> &y_test, double test_size, int seed)
{

    int numberOfRows = X.size();

    int test_size_count = (numberOfRows * test_size);
    int train_size_count = numberOfRows - test_size_count;

    X_train.resize(train_size_count);
    X_test.resize(test_size_count);
    y_train.resize(train_size_count);
    y_test.resize(test_size_count);

    // copies cause const..
    vector<vector<double>> X_shuffled = X;
    vector<double> y_shuffled = y;
    shuffleData(X_shuffled, y_shuffled, seed);

    for (int i = 0; i < train_size_count; i++)
    {
        X_train[i] = X_shuffled[i];
        y_train[i] = y_shuffled[i];
    }

    for (int i = 0; i < test_size_count; i++)
    {
        X_test[i] = X_shuffled[train_size_count + i];
        y_test[i] = y_shuffled[train_size_count + i];
    }
}