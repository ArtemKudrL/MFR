#pragma once
#include <math.h>

#define Pi 3.1415926535897931

class vec{
	double x, y, z,
		r, phi, theta,
		norm_x, norm_y, norm_z;

	void length_calc();
	void angle_calc();
	void norm_calc();
public:
	vec() {}
	vec(double x, double y, double z);

	double GetX();
	double GetY();
	double GetZ();
	double GetR();
	double GetPhi();
	double GetTheta();
	double GetNx();
	double GetNy();
	double GetNz();

	void SetX(double x);
	void SetY(double y);
	void SetZ(double z);
	void SetDecart(double x, double y, double z);
	void SetPhi(double phi);
	void SetTheta(double theta);
	void SetSphere(double r, double phi, double theta);

	void normalize();

	vec operator = (const vec P);
	vec operator + (const vec P);
	vec operator - (const vec P);
	vec operator * (const double &a);
	vec operator / (const double &a);
	void operator += (const vec &P);
	void operator -= (const vec &P);
	void operator *= (const double &a);
	void operator /= (const double &a);
	double operator * (const vec &P);
	double operator ^ (const vec &P);
};

double rad(double deg);
double deg(double rad);
double length(double x, double y, double z);