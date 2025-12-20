#include <iostream>
#include <vector>
#include <cmath>   
#include <numeric> 

/**
 * Calculates the Mean Absolute Error (MAE)
 */
double calculate_mae(const std::vector<double> &actual, const std::vector<double> &predicted)
{
    double sum_error = 0.0;
    for (size_t i = 0; i < actual.size(); ++i)
    {
        sum_error += std::abs(actual[i] - predicted[i]);
    }
    return sum_error / actual.size();
}

/**
 * Calculates the Relative Mean Absolute Error (RMAE)
 * Formula: (Sum of Absolute Errors) / (Sum of Actual Values)
 */
double calculate_rmae(const std::vector<double> &actual, const std::vector<double> &predicted)
{
    double sum_abs_error = 0.0;
    double sum_actual = 0.0;

    for (size_t i = 0; i < actual.size(); ++i)
    {
        sum_abs_error += std::abs(actual[i] - predicted[i]);
        sum_actual += std::abs(actual[i]);
    }

    // Check for division by zero
    return (sum_actual == 0) ? 0.0 : (sum_abs_error / sum_actual);
}

int main()
{
    // Example Data
    std::vector<double> actual = {100.0, 150.0, 200.0, 250.0};
    std::vector<double> predicted = {110.0, 140.0, 205.0, 240.0};

    double mae = calculate_mae(actual, predicted);
    double rmae = calculate_rmae(actual, predicted);

    std::cout << "Mean Absolute Error (MAE): " << mae << std::endl;
    std::cout << "Relative Mean Absolute Error (RMAE): " << rmae << " (" << rmae * 100 << "%)" << std::endl;

    return 0;
}