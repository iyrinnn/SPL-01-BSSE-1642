class randomForest
{

    int num_estimator;
    int max_feature;
    bool bootstrap;
    int max_samples;

criterion{“gini”, “entropy”, “log_loss”}, default =”gini” max_depthint, default = None min_samples_splitint or #float, default = 2 min_samples_leaf int or #float, default = 1 min_weight_fraction_leaffloat, default = 0.0 max_features{“sqrt”, “log2”, None}, int or float, default =”sqrt” max_leaf_nodesint, default = None min_impurity_decreasefloat, default = 0.0

                                                                                                                                                                                                                                                                                                                                                                      N_t /
                                                                                                                                                                                                                                                                                                                                                                      N * (impurity - N_t_R / N_t * right_impurity - N_t_L / N_t * left_impurity)

                                                                                                                                                                                                                                                                                                                                                                              bootstrapbool,
                                          default = True
                                                        oob_scorebool or
                                                    callable,
                                          default = False
                                              n_jobsint,
                                          default = None
                                              random_stateint,
                                          RandomState instance or None, default = None verboseint, default = 0

                                                                                                   private : struct Node
    {
        double value;
        int featureIndex;
        double threshold;
        Node *left;
        Node *right;
    };

    int SSE()
    {
    }
};