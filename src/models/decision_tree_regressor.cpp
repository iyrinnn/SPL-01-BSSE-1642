#include <vector>
#include <string>
using namespace std;

class DecisionTreeRegressor
{
private:
    string criterion; // "mse", "mae", "poisson"
    int max_depth;
    int min_sample_split;
    int max_leaf_nodes;
    float min_impurity_decrease;

    float meanSquaredError(const vector<float> &y)
    {

        return 0.0;
    }

    float meanAbsoluteError(const vector<float> &y)
    {

        return 0.0;
    }

    float meanPoissonDeviance(const vector<float> &y)
    {

        return 0.0;
    }

public:
    DecisionTreeRegressor(string crit = "mse", int depth = 10)
        : criterion(crit), max_depth(depth) {}

    void fit(const vector<vector<float>> &X, const vector<float> &y);
    float predict(const vector<float> &x_single);
};