# Model Development Progress Log

## Run History

### Run 1 - Initial Decision Tree (max_depth=10, min_samples_split=2)
**Date:** Jan 14, 2026
**Changes:** Initial baseline with basic preprocessing and no feature engineering
**Results:**
- Train MAE: 0.46, MSE: 1.63, RMSE: 1.28, R² Score: 0.996
- Test MAE: 9.84, MSE: 1582, RMSE: 39.77, R² Score: -5.41
- **Issue:** Severe overfitting

---

### Run 2 - Reduced Tree Depth (max_depth=5, min_samples_split=15)
**Date:** Jan 14, 2026
**Changes:** Reduced overfitting parameters
**Results:**
- Train MAE: 2.69, MSE: 94.40, RMSE: 9.72, R² Score: 0.764
- Test MAE: 7.90, MSE: 952.54, RMSE: 30.86, R² Score: -2.86
- **Improvement:** Better test R², still overfitting

---

### Run 3 - More Conservative Params (max_depth=4, min_samples_split=25)
**Date:** Jan 14, 2026
**Changes:** Further regularization
**Results:**
- Train MAE: 3.37, MSE: 116.12, RMSE: 10.78, R² Score: 0.709
- Test MAE: 7.13, MSE: 802.39, RMSE: 28.33, R² Score: -2.25
- **Note:** Stabilizing but still overfitting

---

### Run 4 - With Feature Engineering (10 engineered features)
**Date:** Jan 14, 2026
**Changes:** Added supply-demand ratios, weather interactions, heat index, cyclic month, price per km
**Results:**
- Train MAE: 3.13, MSE: 40.43, RMSE: 6.36, R² Score: 0.899
- Test MAE: 3.94, MSE: 112.39, RMSE: 10.60, R² Score: 0.545
- **Improvement:** 🎯 TEST R² improved to 0.545! Best so far!

---

### Run 5 - One-Hot Encoding Only (removed feature engineering)
**Date:** Jan 14, 2026
**Changes:** Reverted to one-hot encoding without feature engineering (19 features)
**Results:**
- Train MAE: 3.32, MSE: 117.57, RMSE: 10.84, R² Score: 0.706
- Test MAE: 7.22, MSE: 810.84, RMSE: 28.48, R² Score: -2.28
- **Result:** Performance dropped significantly

---

### Run 6 - Optimized Feature Engineering (4 key features)
**Date:** Jan 14, 2026
**Changes:** 
- One-hot encoding for Season, Crop, Region
- Cyclic month encoding (month_sin, month_cos)
- Supply-Demand Ratio
- Supply minus Demand
**Results:**
- Train MAE: 3.22, MSE: 110.14, RMSE: 10.49, R² Score: 0.724
- Test MAE: 6.87, MSE: 803.43, RMSE: 28.34, R² Score: -2.25
- **Status:** 23 total features, still overfitting

---

## Key Observations

✅ **Best Test Performance:** Run 4 (R² = 0.545)
- Feature engineering > one-hot encoding alone
- Supply-demand relationships critical
- Weather interactions matter

❌ **Current Issue:** Severe overfitting in all single-tree models
- Test R² keeps going negative
- Tree memorizing training data

## Next Steps to Try
1. Random Forest (ensemble method)
2. More aggressive max_depth (2-3)
3. Hyperparameter tuning with cross-validation
4. Check for data leakage with Previous_Price

---


Data loaded. Rows: 1001
Applying feature engineering...
Feature engineering completed. Feature count (excluding target): 20
Features: 1000 rows, 20 columns
Target: 1000 values
Data shuffled
Train set: 800 rows
Test set: 200 rows
Train data saved to train.csv
Test data saved to test.csv

=== Training Decision Tree ===
Decision Tree trained!

=== Training Set Metrics ===
MAE: 3.22289
MSE: 110.14
RMSE: 10.4948
R2 Score: 0.72417

=== Test Set Metrics ===
MAE: 6.86611
MSE: 803.432
RMSE: 28.3449
R2 Score: -2.25439
PS E:\03_THIRD SEMESETER\SPL-01 BSSE 1642\SPL-01-BSSE-1642> 

Data loaded. Rows: 5001                                                                                                                   
Applying feature engineering...                                                                                                           
Feature engineering completed. Feature count (excluding target): 20                                                                       
Features: 5000 rows, 20 columns                                                                                                           
Target: 5000 values
Data shuffled
Train set: 4000 rows
Test set: 1000 rows
Train data saved to train.csv
Test data saved to test.csv

=== Training Decision Tree ===
Decision Tree trained!

=== Training Set Metrics ===
MAE: 2.8294
MSE: 66.2212
RMSE: 8.13764
R2 Score: 0.948718

=== Test Set Metrics ===
MAE: 3.45098
MSE: 183.818
RMSE: 13.5579
R2 Score: 0.848486
PS E:\03_THIRD SEMESETER\SPL-01 BSSE 1642\SPL-01-BSSE-1642> 

Data loaded. Rows: 10001
Applying feature engineering...
Feature engineering completed. Feature count (excluding target): 20
Features: 10000 rows, 20 columns
Target: 10000 values
Data shuffled
Train set: 8000 rows
Test set: 2000 rows
Train data saved to train.csv
Test data saved to test.csv

=== Training Decision Tree ===
Decision Tree trained!

=== Training Set Metrics ===
MAE: 5.89279
MSE: 200.234
RMSE: 14.1504
R2 Score: 0.943069

=== Test Set Metrics ===
MAE: 6.58376
MSE: 469.679
RMSE: 21.6721
R2 Score: 0.889298
PS E:\03_THIRD SEMESETER\SPL-01 BSSE 1642\SPL-01-BSSE-1642> 

with KNN imputer
Data loaded. Rows: 10001                                                                                                                                                                       
Applying feature engineering...                                                                                                                                                                
Feature engineering completed. Feature count (excluding target): 20
Features: 10000 rows, 20 columns
Target: 10000 values
Data shuffled
Train set: 8000 rows
Test set: 2000 rows
Train data saved to train.csv
Test data saved to test.csv

=== Training Decision Tree ===
Decision Tree trained!

=== Training Set Metrics ===
MAE: 5.76102
MSE: 185.869
RMSE: 13.6334
R2 Score: 0.947153

=== Test Set Metrics ===
MAE: 6.37543
MSE: 459.664
RMSE: 21.4398
R2 Score: 0.891659
PS E:\03_THIRD SEMESETER\SPL-01 BSSE 1642\SPL-01-BSSE-1642>