#pragma once
#include <vector>
#include <set>
#include <string>

using namespace std;

class DecisionTree
{
public:
    struct Node
    {
        double value; // mean for regressor...mode for classifier
        int featureIndex;
        double threshold;
        Node *left;
        Node *right;
        bool isLeaf;
    };

private:
    Node *root;
    string criterion; // "mse", "mae", "poisson" // string criterion; // "gini", "entropy"
    int max_depth;
    int min_sample_split;
    int max_leaf_nodes;
    float min_impurity_decrease;


    vector<int> feature_subset;
    bool use_feature_subset = false;

    Node *buildTree(vector<vector<double>> &X, const vector<double> &y, int depth);
    void findBestSplit(vector<vector<double>> &X, const vector<double> &y,
                       int &bestFeature, double &bestThreshold);
    void findBestSplit(vector<vector<double>> &X, const vector<double> &y,
                       const vector<int> &feature_indices,
                       int &bestFeature, double &bestThreshold);
    double leafValue(const vector<double> &y);
    bool stoppingCriteria(int depth, int numSamples);
    void deleteTree(Node *node);

public:
    DecisionTree(int depth = 5, int minSamplesSplit = 2);

    void fit(vector<vector<double>> &X, const vector<double> &y);
    void fit(vector<vector<double>> &X, const vector<double> &y, const vector<int> &feature_indices);
    double predict(const vector<double> &featureRow);
    vector<double> predict(const vector<vector<double>> &featureMatrix);
};
