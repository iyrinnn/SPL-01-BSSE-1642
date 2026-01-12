#pragma once
#include <vector>
#include <stdlib.h>
using namespace std;

void train_test_split(const vector<vector<double>> &X,
                      const vector<double> &y,
                      vector<vector<double>> &X_train,
                      vector<vector<double>> &X_test,
                      vector<double> &y_train,
                      vector<double> &y_test,
                      double test_size,
                      int seed);