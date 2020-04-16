#include "geometry.h"

void vec::length_calc() {
	r = sqrt(x * x + y * y + z * z);
}
void vec::angle_calc() {
	length_calc();
	theta = acos(z / r);
	if (y >= 0) phi = acos(x / sqrt(x * x + y * y));
	else phi = - acos(x / sqrt(x * x + y * y));
}
void vec::norm_calc() {
	length_calc();
	norm_x = x / r;
	norm_y = y / r;
	norm_z = z / r;
}
vec::vec(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
	length_calc();
}
double vec::GetX() { return x; }
double vec::GetY() { return y; }
double vec::GetZ() { return z; }
double vec::GetR() {
	length_calc();
	return r;
}
double vec::GetPhi() {
	angle_calc();
	return phi;
}
double vec::GetTheta() {
	angle_calc();
	return theta;
}
double vec::GetNx() {
	norm_calc();
	return norm_x;
}
double vec::GetNy() {
	norm_calc();
	return norm_y;
}
double vec::GetNz() {
	norm_calc();
	return norm_z;
}
void vec::SetX(double x) { this->x = x; }
void vec::SetY(double y) { this->y = y; }
void vec::SetZ(double z) { this->z = z; }

void vec::SetDecart(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}
void vec::SetPhi(double phi) {
	angle_calc();
	x = r * sin(theta)*cos(phi); 
	y = r * sin(theta)*sin(phi);
	z = r * cos(theta);
}
void vec::SetTheta(double theta) {
	angle_calc();
	x = r * sin(theta)*cos(phi);
	y = r * sin(theta)*sin(phi);
	z = r * cos(theta);
}
void vec::SetSphere(double r, double phi, double theta) {
	x = r * sin(theta) * cos(phi);
	y = r * sin(theta) * sin(phi);
	z = r * cos(theta);
}

vec vec::operator = (const vec P) {
	this->x = P.x;
	this->y = P.y;
	this->z = P.z;
	return *this;
}
vec vec::operator + (const vec P) {
	vec sum(x + P.x, y + P.y, z + P.z);
	return sum;
}
vec vec::operator - (const vec P) {
	vec sum(x - P.x, y - P.y, z - P.z);
	return sum;
}
vec vec::operator * (const double &a) {
	vec mult(x*a, y*a, z*a);
	return mult;
}
vec vec::operator / (const double &a) {
	vec div(x*a, y*a, z*a);
	return div;
}
void vec::operator += (const vec &P) {
	x += P.x;
	y += P.y;
	z += P.z;
}
void vec::operator -= (const vec &P) {
	x -= P.x;
	y -= P.y;
	z -= P.z;
}
void vec::operator *= (const double &a) {
	x *= a;
	y *= a;
	z *= a;
}
void vec::operator /= (const double &a) {
	x /= a;
	y /= a;
	z /= a;
}
double vec::operator * (const vec &P) {
	return (x * P.x + y * P.y + z * P.z);
}
double vec::operator ^ (const vec &P) {
	return acos((x * P.x + y * P.y + z * P.z) / sqrt(x * x + y * y + z * z) / sqrt(P.x * P.x + P.y * P.y + P.z * P.z));
}
void vec::normalize() {
	norm_calc();
	x = norm_x;
	y = norm_y;
	z = norm_z;
}
double rad(double deg) { return deg * Pi / 180; }
double deg(double rad) { return rad * 180 / Pi; }
double length(double x, double y, double z) { return sqrt(x * x + y * y + z * z); }