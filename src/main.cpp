#include <iostream>
#include "../include/dataset/dataset_loader.h"
#include "../include/dataset/dataset_splitter.h"
#include "../include/metrics/metrics.h"
#include "../include/models/criterion.h"
#include "../include/models/decision_tree.h"
#include "../include/models/hyper_parameter_tuning.h"
#include "../include/models/random_forest.h"
#include "../include/preprocessing/encoder.h"
#include "../include/preprocessing/imputer.h"
#include "../include/preprocessing/missing_values.h"
#include "../include/preprocessing/scaler.h"
#include "../include/preprocessing/shuffle.h"
#include "../include/preprocessing/splitter.h"
#include "../include/utils/utils.h"

int main()
{

    vector<double> y_reg = {2.0, 4.0, 6.0, 8.0, 10.0};

    MSE mse;
    MAE mae;
    Poisson poisson;

    cout << "=== Regression Criteria ===" << endl;

    cout << "MSE Impurity: " << mse.impurity(y_reg) << endl;
    cout << "MSE Leaf Value (mean): " << mse.leaf_value(y_reg) << endl;

    cout << "MAE Impurity: " << mae.impurity(y_reg) << endl;
    cout << "MAE Leaf Value (median): " << mae.leaf_value(y_reg) << endl;

    vector<double> y_clf = {0, 1, 1, 1, 0, 2, 2, 2, 2};

    Gini gini;
    Entropy entropy;

    cout << "\n=== Classification Criteria ===" << endl;

    cout << "Gini Impurity: " << gini.impurity(y_clf) << endl;
    cout << "Gini Leaf Value (majority class): " << gini.leaf_value(y_clf) << endl;

    cout << "Entropy Impurity: " << entropy.impurity(y_clf) << endl;
    cout << "Entropy Leaf Value (majority class): " << entropy.leaf_value(y_clf) << endl;

    return 0;
}
