#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
  VectorXd rmse(4);
  rmse << 0, 0, 0, 0;
  int estimations_size = estimations.size();
  int ground_truth_size = ground_truth.size();
  if (estimations_size != ground_truth_size || estimations_size == 0) {
    cout << "Invalid estimations and ground_truth" << endl;
    return rmse;
  }

  for (unsigned int i = 0; i < estimations_size; ++i) {
    VectorXd residual = estimations[i] - ground_truth[i];

    residual = residual.array() * residual.array();
    rmse += residual;    
  }
  // Calculate mean
  rmse = rmse / estimations_size;
  // SQRT 
  rmse = rmse.array().sqrt();

  // return error
  cout << "RMSE: " << rmse << endl;
  return rmse;
}