#include "../../include/models/decision_tree.h"
#include "../../include/models/criterion.h"

DecisionTree::Node *DecisionTree::buildTree(vector<vector<double>> &X, const vector<double> &y, int depth)
{
    if (stoppingCriteria(depth, y.size()))
    {
        Node *leaf = new Node();
        leaf->isLeaf = true;
        leaf->value = leafValue(y);
        leaf->left = nullptr;
        leaf->right = nullptr;
        return leaf;
    }

    int bestFeature = -1;
    double bestThreshold = 0.0;

    findBestSplit(X, y, bestFeature, bestThreshold);

    // If no split improves impurity, make leaf
    if (bestFeature == -1)
    {
        Node *leaf = new Node();
        leaf->isLeaf = true;
        leaf->value = leafValue(y);
        leaf->left = nullptr;
        leaf->right = nullptr;
        return leaf;
    }

    // Split data into left/right based on threshold
    vector<vector<double>> X_left, X_right;
    vector<double> y_left, y_right;
    for (int i = 0; i < X.size(); i++)
    {
        if (X[i][bestFeature] <= bestThreshold)
        {
            X_left.push_back(X[i]);
            y_left.push_back(y[i]);
        }
        else
        {
            X_right.push_back(X[i]);
            y_right.push_back(y[i]);
        }
    }

    // Create node and recursively build children
    Node *node = new Node();
    node->featureIndex = bestFeature;
    node->threshold = bestThreshold;
    node->isLeaf = false;
    node->value = 0.0; // unused for non-leaf
    node->left = buildTree(X_left, y_left, depth + 1);
    node->right = buildTree(X_right, y_right, depth + 1);

    return node;
}

void DecisionTree::findBestSplit(vector<vector<double>> &X, const vector<double> &y,
                                 int &bestFeature, double &bestThreshold)
{

    double bestScore = 10e9;

    // Choose criterion object
    Criterion *crit = nullptr;
    if (criterion == "mse")
        crit = new MSE();
    else if (criterion == "mae")
        crit = new MAE();
    else if (criterion == "gini")
        crit = new Gini();
    else if (criterion == "entropy")
        crit = new Entropy();
    // if criterion not recognized, default to MSE ...or something we need a else statement here

    // Loop through all features
    for (int featureIndex = 0; featureIndex < X[0].size(); featureIndex++)
    {
        // Get all unique values for this feature without using set
        vector<double> uniqueValues;
        for (int i = 0; i < X.size(); i++)
        {
            bool found = false;
            for (auto val : uniqueValues)
            {
                if (val == X[i][featureIndex])
                {
                    found = true;
                    break;
                }
            }
            if (!found)
                uniqueValues.push_back(X[i][featureIndex]);
        }
        // Try splitting at each unique value
        for (const auto &threshold : uniqueValues)
        {
            vector<double> leftY, rightY;
            for (int i = 0; i < X.size(); i++)
            {
                if (X[i][featureIndex] <= threshold)
                {
                    leftY.push_back(y[i]);
                }
                else
                {
                    rightY.push_back(y[i]);
                }
            }

            // Calculate impurity based on the criterion

            double score = (leftY.size() * crit->impurity(leftY) +
                            rightY.size() * crit->impurity(rightY)) /
                           y.size();

            // Update best split if current score is better
            if (score < bestScore)
            {
                bestScore = score;
                bestFeature = featureIndex;
                bestThreshold = threshold;
            }
        }
    }

    delete crit;
}

double DecisionTree::leafValue(const vector<double> &y)
{
    Criterion *crit = nullptr;

    if (criterion == "mse")
        crit = new MSE();
    else if (criterion == "mae")
        crit = new MAE();
    else if (criterion == "gini")
        crit = new Gini();
    else if (criterion == "entropy")
        crit = new Entropy();
    // add Poisson etc.

    double value = crit->leaf_value(y);
    delete crit;
    return value;
}

bool DecisionTree::stoppingCriteria(int depth, int numSamples)
{

    return (depth >= max_depth || numSamples < min_sample_split);
}

void DecisionTree::fit(vector<vector<double>> &X, const vector<double> &y)
{
    root = buildTree(X, y, 0);
}

double DecisionTree::predict(const vector<double> &featureRow)
{
    Node *node = root;
    while (!node->isLeaf)
    {
        if (featureRow[node->featureIndex] <= node->threshold)
            node = node->left;
        else
            node = node->right;
    }
    return node->value;
}

vector<double> DecisionTree::predict(const vector<vector<double>> &featureMatrix)
{
    vector<double> predictions;
    for (auto &row : featureMatrix)
        predictions.push_back(predict(row));
    return predictions;
}

void DecisionTree::deleteTree(Node *node)
{
    if (node)
    {
        deleteTree(node->left);
        deleteTree(node->right);
        delete (node);
    }
}
