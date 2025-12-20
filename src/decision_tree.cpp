#include <vector>

class DecisionTreeRegressor
{

    string criterion;
    int max_depth;
    int min_sample_split;
    int max_leaf_nodes;
    int min_impurity_decrease;

private:
    struct Node
    {
        double value;
        int featureIndex;
        double threshold;
        Node *left;
        Node *right;
    };

    int SSE()
    {
    }
};

class Statistics
{
public:
    double mean(vector<int> &vec)
    {

        int sum = 0;
        for (auto it = vec)
        {
            sum += it;
        }

        int mean = (sum) / vec.size();
        return sum;
    }
    double median(vector<int> vec)
    {
        sort(vec.begin(), vec.end());
        int max = 0 int currentCount = 0;
        int maxIdx;
        for (int)
        {
            if (vec[i] = vector[i - 1])
            {
                currentCount++;
                if (currentCount > max)
                {
                    max = currentCount;
                    maxIdx = i;
                }
            }

            else
            {
                currentCount = 1;
            }
        }

        return vec[maxIdx];
    }

    double variance(vector<int> &vec)
    {
        int mean = mean(vec);
        int varSum = 0;
        for (auto it : vec)
        {
        }
    }

    double stddev(vector<int> &vec)
    {
    }
};
