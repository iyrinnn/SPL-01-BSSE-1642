#include <iostream>
#include <fstream>
#include <ctime>
#include "../include/dataset/dataset_loader.h"
    #include "../include/dataset/dataset_splitter.h"
#include "../include/models/criterion.h"
#include "../include/models/decision_tree.h"
#include "../include/models/hyper_parameter_tuning.h"
#include "../include/models/random_forest.h"
#include "../include/preprocessing/converter.h"
#include "../include/preprocessing/encoder.h"
#include "../include/preprocessing/imputer.h"
#include "../include/preprocessing/missing_values.h"
#include "../include/preprocessing/scaler.h"
#include "../include/preprocessing/shuffle.h"
#include "../include/preprocessing/splitter.h"
#include "../include/preprocessing/feature_engineering.h"
#include "../include/utils/utils.h"
#include "../include/metrics/metrics.h"

int main()
{
    srand(time(NULL));

    vector<vector<string>> data = fileRead("e:\\03_THIRD SEMESETER\\SPL-01 BSSE 1642\\SPL-01-BSSE-1642\\data\\crop_price_10000.csv");

    cout << "Data loaded. Rows: " << data.size() << endl;

    // Skip header row
    if (!data.empty())
    {
        data.erase(data.begin());
    }

    dropColumn(data, 0); // Remove Date column (redundant with Year/Month)

    MissingValuesUtils::fillMissing(data, "MISSING");

    // Clean categorical columns (fix typos, standardize format)
    vector<int> categoricalCols = {2, 3, 4}; // Season, Crop, Region
    cleanCategoricalColumns(data, categoricalCols);

    // One-hot encode categorical features: Season, Crop, Region
    Encoder encoder;
    for (int colIndex : categoricalCols)
    {
        encoder.oneHotEncode(data, colIndex);
    }

    vector<vector<double>> numericData = Converter::toDouble(data);

    SimpleImputer imputer;
    imputer.fitTransform(numericData);

    // Apply feature engineering
    applyFeatureEngineering(numericData);

    // Separate features (X) and target (y) - assuming last column is target
    vector<vector<double>> X;
    vector<double> y;

    for (const auto &row : numericData)
    {
        vector<double> features(row.begin(), row.end() - 1);
        X.push_back(features);
        y.push_back(row.back());
    }

    cout << "Features: " << X.size() << " rows, " << X[0].size() << " columns" << endl;
    cout << "Target: " << y.size() << " values" << endl;

    // Shuffle the data
    shuffleData(X, y, 42);
    cout << "Data shuffled" << endl;

    // Split into train and test sets (80-20 split)
    vector<vector<double>> X_train, X_test;
    vector<double> y_train, y_test;
    train_test_split(X, y, X_train, X_test, y_train, y_test, 0.2, 42);

    cout << "Train set: " << X_train.size() << " rows" << endl;
    cout << "Test set: " << X_test.size() << " rows" << endl;

    // Save train data
    ofstream trainFile("e:\\03_THIRD SEMESETER\\SPL-01 BSSE 1642\\SPL-01-BSSE-1642\\data\\train.csv");
    if (!trainFile.is_open())
    {
        cerr << "Error: Could not open train.csv!" << endl;
        return 1;
    }

    for (size_t i = 0; i < X_train.size(); i++)
    {
        for (size_t j = 0; j < X_train[i].size(); j++)
        {
            trainFile << X_train[i][j] << ",";
        }
        trainFile << y_train[i] << endl;
    }
    trainFile.close();
    cout << "Train data saved to train.csv" << endl;

    // Save test data
    ofstream testFile("e:\\03_THIRD SEMESETER\\SPL-01 BSSE 1642\\SPL-01-BSSE-1642\\data\\test.csv");
    if (!testFile.is_open())
    {
        cerr << "Error: Could not open test.csv!" << endl;
        return 1;
    }

    for (size_t i = 0; i < X_test.size(); i++)
    {
        for (size_t j = 0; j < X_test[i].size(); j++)
        {
            testFile << X_test[i][j] << ",";
        }
        testFile << y_test[i] << endl;
    }
    testFile.close();
    cout << "Test data saved to test.csv" << endl;

    // Train Decision Tree with MSE criterion
    cout << "\n=== Training Decision Tree ===" << endl;
    DecisionTree dt(4, 25); // max_depth=4, min_samples_split=25 (to reduce overfitting)
    dt.fit(X_train, y_train);
    cout << "Decision Tree trained!" << endl;

    // Make predictions
    vector<double> y_pred_train = dt.predict(X_train);
    vector<double> y_pred_test = dt.predict(X_test);

    // Calculate metrics
    cout << "\n=== Training Set Metrics ===" << endl;
    cout << "MAE: " << MAE(y_train, y_pred_train) << endl;
    cout << "MSE: " << MSE(y_train, y_pred_train) << endl;
    cout << "RMSE: " << RMSE(y_train, y_pred_train) << endl;
    cout << "R2 Score: " << R2Score(y_train, y_pred_train) << endl;

    cout << "\n=== Test Set Metrics ===" << endl;
    cout << "MAE: " << MAE(y_test, y_pred_test) << endl;
    cout << "MSE: " << MSE(y_test, y_pred_test) << endl;
    cout << "RMSE: " << RMSE(y_test, y_pred_test) << endl;
    cout << "R2 Score: " << R2Score(y_test, y_pred_test) << endl;

    return 0;
}
