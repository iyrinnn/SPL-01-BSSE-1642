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
        double value; // Mean for Regressor, Mode for Classifier
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

    // Core tree-building functions
    Node *buildTree(vector<vector<double>> &X, const vector<double> &y, int depth);
    void findBestSplit(vector<vector<double>> &X, const vector<double> &y,
                       int &bestFeature, double &bestThreshold);
    double leafValue(const vector<double> &y);
    bool stoppingCriteria(int depth, int numSamples);
    void deleteTree(Node *node);

public:
    // Constructor & Destructor
    DecisionTree(int depth = 5, int minSamplesSplit = 2);

    // Main interface
    void fit(vector<vector<double>> &X, const vector<double> &y);
    double predict(const vector<double> &featureRow);
    vector<double> predict(const vector<vector<double>> &featureMatrix);
};
