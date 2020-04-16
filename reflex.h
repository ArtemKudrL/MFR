#pragma once

#include "geometry.h"

double theta_calc_1(const double &theta_0, const double &mu, vec &s, vec &source, vec &spot, vec &detector, vec &ray, double &theta);
double theta_calc_2(const double &theta_0, const double &mu, vec &s, vec &source, vec &spot, vec &detector, vec &ray, double &theta);
double alpha_calc(double &theta_0, const double &mu, vec &s, vec &source, vec &spot, vec &detector, vec &ray, double &alpha, double d_alpha);
double spot_calc(double &theta_0, const double &mu, vec &s, vec &source, vec &spot, vec &detector, vec &ray, double d_theta);
bool condition(vec &source, vec &ray, vec &detector, double &d_theta, double &d_alpha, double &d_det_y);