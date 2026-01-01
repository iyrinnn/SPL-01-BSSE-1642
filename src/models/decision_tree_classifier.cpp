#include <vector>
#include <string>
using namespace std;

class DecisionTreeClassifier
{
private:
    string criterion; // "gini", "entropy"
    int max_depth;
    int min_sample_split;

    float gini(const vector<int> &y)
    {

        return 0.0;
    }

    float entropy(const vector<int> &y)
    {

        return 0.0;
    }

public:
    DecisionTreeClassifier(string crit = "gini", int depth = 10)
        : criterion(crit), max_depth(depth) {}

    void fit(const vector<vector<float>> &X, const vector<int> &y);
    int predict(const vector<float> &x_single);
};