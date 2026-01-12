#pragma once
#include <vector>
#include <cmath>
using namespace std;

double MAE(const vector<double> &y_true,
           const vector<double> &y_pred);

double MSE(const vector<double> &y_true,
           const vector<double> &y_pred);

double RMSE(const vector<double> &y_true,
            const vector<double> &y_pred);

double R2Score(const vector<double> &y_true,
               const vector<double> &y_pred);

double AdjustedR2Score(const vector<double> &y_true,
                       const vector<double> &y_pred,
                       int num_features);
