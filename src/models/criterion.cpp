#include "../../include/models/criterion.h"

double average(const vector<double> &values)
{
    double sum = 0.0;
    for (const auto &val : values)
    {
        sum += val;
    }
    return sum / values.size();
}

// Simple selection-based median (no sort, no algorithm)
static double median(const vector<double> &values)
{
    int n = values.size();
    vector<double> temp = values;

    for (int i = 0; i <= n / 2; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (temp[j] < temp[min_index])
            {
                min_index = j;
            }
        }
        double swap = temp[i];
        temp[i] = temp[min_index];
        temp[min_index] = swap;
    }

    if (n % 2 == 1)
    {
        return temp[n / 2];
    }
    else
    {
        return (temp[n / 2 - 1] + temp[n / 2]) / 2.0;
    }
}

double Gini::impurity(const vector<double> &target_values)
{

    unordered_map<int, int> class_count;
    for (auto val : target_values)
    {
        class_count[val]++;
    }
    double gini = 1.0;
    int total_count = target_values.size();
    for (auto pair : class_count)
    {
        double prob = (pair.second * 1.0) / total_count;
        gini -= prob * prob;
    }
    return gini;
}

double Gini::leaf_value(const vector<double> &target_values)
{
    unordered_map<int, int> class_count;
    for (auto val : target_values)
    {
        class_count[val]++;
    }
    int majority_class = -1;
    int max_count = 0;
    for (const auto &pair : class_count)
    {
        if (pair.second > max_count)
        {
            max_count = pair.second;
            majority_class = pair.first;
        }
    }
    return majority_class;
}

double Entropy::impurity(const vector<double> &target_values)
{
    unordered_map<int, int> class_count;
    for (auto val : target_values)
    {
        class_count[val]++;
    }
    double entropy = 0.0;
    int total_count = target_values.size();
    for (auto pair : class_count)
    {
        double prob = (pair.second * 1.0) / total_count;
        entropy -= prob * log2(prob);
    }
    return entropy;
}

double Entropy::leaf_value(const vector<double> &target_values)
{
    unordered_map<int, int> class_count;
    for (auto val : target_values)
    {
        class_count[val]++;
    }
    int majority_class = -1;
    int max_count = 0;
    for (auto pair : class_count)
    {
        if (pair.second > max_count)
        {
            max_count = pair.second;
            majority_class = pair.first;
        }
    }
    return majority_class;
}

double MSE::impurity(const vector<double> &target_values)
{
    double mean = average(target_values);
    double sum = 0.0;
    for (const auto &val : target_values)
    {
        sum += (val - mean) * (val - mean);
    }
    return sum / target_values.size();
}

double MSE::leaf_value(const vector<double> &target_values)
{
    double mean = average(target_values);
    return mean;
}

double MAE::impurity(const vector<double> &target_values)
{
    double mean = average(target_values);
    double sum = 0.0;
    for (auto val : target_values)
    {
        sum += abs(val - mean);
    }
    return sum / target_values.size();
}

double MAE::leaf_value(const vector<double> &target_values)
{
    return median(target_values);
}

double Poisson::impurity(const std::vector<double> &targets)
{
    double mean_val = average(targets);
    if (mean_val <= 0)
        return 0.0;

    double sum = 0.0;
    for (const auto &val : targets)
    {
        if (val > 0)
        {
            sum += val * log(val / mean_val) - (val - mean_val);
        }
    }
    return sum / targets.size();
}

double Poisson::leaf_value(const std::vector<double> &targets)
{
    return average(targets);
}
