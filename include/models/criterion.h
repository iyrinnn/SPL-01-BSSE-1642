#pragma once
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;
class Criterion
{
public:
    virtual ~Criterion() = default;
    virtual double impurity(const vector<double> &targets) = 0;
    virtual double leaf_value(const vector<double> &targets) = 0;
};

class Gini : public Criterion
{
public:
    double impurity(const vector<double> &targets) override;
    double leaf_value(const vector<double> &targets) override;
};

class Entropy : public Criterion
{
public:
    double impurity(const vector<double> &targets) override;
    double leaf_value(const vector<double> &targets) override;
};

class MSE : public Criterion
{
public:
    double impurity(const vector<double> &targets) override;
    double leaf_value(const vector<double> &targets) override;
};

class MAE : public Criterion
{
public:
    double impurity(const vector<double> &targets) override;
    double leaf_value(const vector<double> &targets) override;
};

class Poisson : public Criterion
{
public:
    double impurity(const vector<double> &targets) override;
    double leaf_value(const vector<double> &targets) override;
};
