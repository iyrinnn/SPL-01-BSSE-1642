#include <iostream>
#include <vector>
#include <cmath>   
#include <numeric> 


double calculate_mae(const std::vector<double> &actual, const std::vector<double> &predicted)
{
    double sum_error = 0.0;
    for (size_t i = 0; i < actual.size(); ++i)
    {
        sum_error += std::abs(actual[i] - predicted[i]);
    }
    return sum_error / actual.size();
}


double calculate_rmae(const std::vector<double> &actual, const std::vector<double> &predicted)
{
    double sum_abs_error = 0.0;
    double sum_actual = 0.0;

    for (size_t i = 0; i < actual.size(); ++i)
    {
        sum_abs_error += std::abs(actual[i] - predicted[i]);
        sum_actual += std::abs(actual[i]);
    }

    
    return (sum_actual == 0) ? 0.0 : (sum_abs_error / sum_actual);
}

double calculate_mse(const std::vector<double> &actual, const std::vector<double> &predicted)
{
    double sum_error = 0.0;
    for (size_t i = 0; i < actual.size(); ++i)
    {
        double error = actual[i] - predicted[i];
        sum_error += error * error;
    }
    return sum_error / actual.size();
}