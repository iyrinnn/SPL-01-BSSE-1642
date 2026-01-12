#include "../../include/metrics/metrics.h"
using namespace std;

double MAE(const vector<double> &y_true, const vector<double> &y_pred)
{
    double sum = 0;
    for (int i = 0; i < y_true.size(); i++)
    {
        sum += abs(y_true[i] - y_pred[i]);
    }
    return sum / y_true.size();
}

double MSE(const vector<double> &y_true, const vector<double> &y_pred)
{
    double sum = 0;
    for (int i = 0; i < y_true.size(); i++)
    {
        double diff = y_true[i] - y_pred[i];
        sum += diff * diff;
    }
    return sum / y_true.size();
}

double RMSE(const vector<double> &y_true, const vector<double> &y_pred)
{
    return sqrt(MSE(y_true, y_pred));
}

double R2Score(const vector<double> &y_true, const vector<double> &y_pred)
{
    int n = y_true.size();
    double mean_y = 0;
    for (int i = 0; i < n; i++)
    {
        mean_y += y_true[i];
    }
    mean_y /= n;

    double ss_tot = 0;
    double ss_res = 0;
    for (int i = 0; i < n; i++)
    {
        ss_tot += (y_true[i] - mean_y) * (y_true[i] - mean_y);
        ss_res += (y_true[i] - y_pred[i]) * (y_true[i] - y_pred[i]);
    }
    double r2 = 1 - (ss_res / ss_tot);
    return r2;
}

double AdjustedR2Score(const vector<double> &y_true, const vector<double> &y_pred, int num_features)
{
    int n = y_true.size();
    if (n == num_features + 1)
    {
        return 0.0;
    }
    double r2 = R2Score(y_true, y_pred);
    double adjusted_r2 = 1 - (1 - r2) * (n - 1) / (n - num_features - 1);
    return adjusted_r2;
}