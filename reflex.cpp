#include "reflex.h"

double theta_calc_1(const double &theta_0, const double &mu, vec &s, vec &source, vec &spot, vec &detector, vec &ray, double &theta) {
	if (theta > theta_0 - s.GetTheta()) return -1;
	double alpha = s.GetPhi() + acos(tan(theta) / tan(s.GetTheta()) - sin(theta_0) / cos(theta) / sin(s.GetTheta()));
	ray.SetSphere(1, alpha, Pi / 2 + theta);
	if (ray.GetX() < 0) return -1;
	spot = source - ray * ((source.GetZ() - spot.GetZ()) / ray.GetZ());
	ray = ray - s * (2 * (s * ray) / (s * s));
	detector = spot + ray * ((-(spot * ray) + sqrt(source.GetR() * source.GetR() - spot * spot + (spot * ray)*(spot * ray))));
	ray = spot - source;
	return -mu * spot.GetZ() * 2 / cos(ray.GetTheta());
}
double theta_calc_2(const double &theta_0, const double &mu, vec &s, vec &source, vec &spot, vec &detector, vec &ray, double &theta) {
	if (theta > theta_0 + s.GetTheta()) return -1;
	double alpha = s.GetPhi() - acos(tan(theta) / tan(s.GetTheta()) - sin(theta_0) / cos(theta) / sin(s.GetTheta()));
	ray.SetSphere(1, alpha, Pi / 2 + theta);
	if (ray.GetX() < 0) return -1;
	spot = source - ray * ((source.GetZ() - spot.GetZ()) / ray.GetZ());
	ray = ray  - s * (2 * (s * ray) / (s * s));
	detector = spot + ray * ((-(spot * ray) + sqrt(source * source - spot * spot + (spot * ray)*(spot * ray))));
	ray = spot - source;
	return -mu * spot.GetZ() * 2 / cos(ray.GetTheta());
}
double reflex_cond_1(double &theta_0, vec &s, vec &ray, double &alpha, double &theta) {
	ray.SetSphere(1, alpha, Pi / 2 + theta);
	return  (s ^ ray) - theta_0 - Pi/2;
}
double alpha_calc(double &theta_0, const double &mu, vec &s, vec &source, vec &spot, vec &detector, vec &ray, double &alpha,  double h_alpha) {
	double theta_min = 0, theta_max = Pi / 2, theta;
	if (reflex_cond_1(theta_0, s, ray, alpha, theta_min) * reflex_cond_1(theta_0, s, ray, alpha, theta_max) > 0)
		return -1;
	else do {
			theta = (theta_min + theta_max) / 2;
			if (reflex_cond_1(theta_0, s, ray, alpha, theta) > 0) theta_max = theta;
			else theta_min = theta;
		} while (10 * fabs(theta_max - theta_min) > h_alpha);
	spot = source - ray * ((source.GetZ() - spot.GetZ()) / ray.GetZ());
	ray = ray - s * (2 * (s * ray) / (s * s));
	detector = spot + ray * ((-(spot * ray) + sqrt(source.GetR() * source.GetR() - spot * spot + (spot * ray)*(spot * ray))));
	ray = spot - source;
	return -mu * spot.GetZ() * 2 / cos(ray.GetTheta());
}
double reflex_cond_2(double &theta_0, vec &s, vec &spot, vec &source, double &theta) {
	source.SetSphere(source.GetR(), Pi, Pi / 2 - theta);
	return  (s ^ (spot - source)) - theta_0 - Pi / 2;
}
double spot_calc(double &theta_0, const double &mu, vec &s, vec &source, vec &spot, vec &detector, vec &ray, double d_theta) {
	double theta_min = 0, theta_max = Pi / 2, theta;
	do {
		theta = (theta_min + theta_max) / 2;
		if (reflex_cond_2(theta_0, s, spot, source, theta_min) > 0) theta_max = theta;
		else theta_min = theta;
	} while (100 * fabs(theta_max - theta_min) > d_theta);
	ray = spot - source;
	ray = ray - s * (2 * (s * ray) / (s * s));
	detector = spot + ray * ((fabs(spot * ray) + sqrt(source.GetR() * source.GetR() - spot * spot + (spot * ray)*(spot * ray))));
	ray = spot - source;
	return mu * spot.GetZ() * 2 / cos(ray.GetTheta());
}
bool condition(vec &source, vec &ray, vec &detector, double &d_theta, double &d_alpha, double &d_det_y) {
	return (fabs(source.GetTheta() + ray.GetTheta() - Pi) < d_theta) &&
		(fabs(ray.GetPhi()) < d_alpha) &&
		(fabs(detector.GetY()) < d_det_y);
}