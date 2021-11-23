#pragma once

#include <eigen3/Eigen/Dense>
#include <fstream>
#include <vector>

#define SHOW_TRACK true

// feature tracker parameters
// as the feature are parameterized by inverse depth, which only need one parameter, will make a
// perfect diagonal matrix which is extremely fast for solve, so we could add more features without
// loss of the efficience.

const int FREQ = 10;

// estimator
const int WINDOW_SIZE = 10;
const double INIT_DEPTH = 2.0;
const double MIN_PARALLAX = 0.04;  // only threshold for new keyframe #0.02

// from output
const int ESTIMATE_EXTRINSIC = 0;

// backend
const double TD = 0.0;
const double SOLVER_TIME = 0.04;
const int NUM_ITERATIONS = 8;
const double TR = 0.0;
const double BIAS_ACC_THRESHOLD = 0.1;
const double BIAS_GYR_THRESHOLD = 0.1;
