#include <vector>
using namespace std;
class BaseDecisionTree
{
protected:
    // Pure Virtual Function: Forces children to implement their own math
    virtual double calculate_impurity(const vector<double> &y) = 0;
    virtual double calculate_leaf_value(const std::vector<double> &y) = 0;

public:
    BaseDecisionTree(int depth, int split) : max_depth(depth), min_sample_split(split), root(nullptr) {}

    // Shared logic: Traversing the tree to predict is the same for both
    double predict_single(const std::vector<double> &x, Node *node)

        // Common Destructor to clean up memory
        void deleteTree(Node *node);
};