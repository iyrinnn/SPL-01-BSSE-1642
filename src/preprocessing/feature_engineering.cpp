#include "../../include/preprocessing/feature_engineering.h"
#include <iostream>
#include <cmath>

using namespace std;

void applyFeatureEngineering(vector<vector<double>> &numericData)
{
    cout << "Applying feature engineering..." << endl;
    const double PI = 3.14159265358979323846;

    
    const int MONTH_IDX = 1;
    const int PREV_PRICE_OFFSET = 8; 
    const int RAINFALL_OFFSET = 7;
    const int SUPPLY_OFFSET = 6;
    const int DEMAND_OFFSET = 5;
    const int TEMP_OFFSET = 4;
    const int HUMIDITY_OFFSET = 3;
    const int DISTANCE_OFFSET = 2;
    const int TARGET_OFFSET = 1;

    for (auto &row : numericData)
    {
        int n = row.size();

        double month = row[MONTH_IDX];
        double previous_price = row[n - PREV_PRICE_OFFSET];
        double rainfall = row[n - RAINFALL_OFFSET];
        double supply = row[n - SUPPLY_OFFSET];
        double demand = row[n - DEMAND_OFFSET];
        double temperature = row[n - TEMP_OFFSET];
        double humidity = row[n - HUMIDITY_OFFSET];
        double distance = row[n - DISTANCE_OFFSET];

        // 1. Cyclic Month Encoding
        double month_sin = sin(2 * PI * month / 12.0);
        double month_cos = cos(2 * PI * month / 12.0);

        // 2. Demand–Supply pressure 
        double demand_supply_ratio = demand / (supply + 1.0);

        // 3. Net supply
        double supply_minus_demand = supply - demand;

        
        row.insert(row.end() - TARGET_OFFSET, {month_sin,
                                               month_cos,
                                               demand_supply_ratio,
                                               supply_minus_demand});
    }

    cout << "Feature engineering completed. Feature count (excluding target): "
         << numericData[0].size() - 1 << endl;
}
