class BaseDecisionTree
{
protected:
    struct Node
    {
        double value; // Mean for Regressor, Mode for Classifier
        int featureIndex;
        double threshold;
        Node *left, *right;
        bool isLeaf;

        Node() : left(nullptr), right(nullptr), isLeaf(false), featureIndex(-1), value(0), threshold(0) {}
    };

    Node *root;
    int max_depth;
    int min_sample_split;

    // Pure Virtual Function: Forces children to implement their own math
    virtual double calculate_impurity(const std::vector<double> &y) = 0;
    virtual double calculate_leaf_value(const std::vector<double> &y) = 0;

public:
    BaseDecisionTree(int depth, int split) : max_depth(depth), min_sample_split(split), root(nullptr) {}

    // Shared logic: Traversing the tree to predict is the same for both
    double predict_single(const std::vector<double> &x, Node *node)
    {
    }

    // Common Destructor to clean up memory
    void deleteTree(Node *node)
    {
        if (node)
        {
            deleteTree(node->left);
            deleteTree(node->right);
            delete (node);
        }
    }
    virtual ~BaseDecisionTree() { deleteTree(root); }
};