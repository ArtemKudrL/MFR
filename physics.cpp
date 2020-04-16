#include "physics.h"

vec::vec() {}
vec::vec(double x, double y) {
	this->x = x;
	this->y = y;
}
double vec::GetX() {
	return x;
}
double vec::GetY() {
	return y;
}
double vec::GetLength() {
	return sqrt(x*x + y * y);
}
vec vec::operator =(vec v){
	x = v.x;
	y = v.y;
	return v;
}
vec vec::operator +(vec v) {
	v.x += x;
	v.y += y;
	return v;
}
vec vec::operator -(vec v) {
	v.x = x - v.x;
	v.y = y - v.x;
	return v;
}
vec vec::operator +=(vec v) {
	x += v.x;
	y += v.y;
	v.x = x;
	v.y = y;
	return v;
}
vec vec::operator -=(vec v) {
	x -= v.x;
	y -= v.y;
	v.x = x;
	v.y = y;
	return v;
}
vec vec::operator *(double c) {
	vec v(x*c, y*c);
	return v;
}
vec vec::operator /(double c) {
	vec v(x / c, y / c);
	return v;
}
vec vec::operator *=(double c) {
	x *= c;
	y *= c;
	return *this;
}
vec vec::operator /=(double c) {
	x /= c;
	y /= c;
	return *this;
}
double vec::operator *(vec &v) {
	return x * v.x + y * v.y;
}

particle::particle() {

}
particle::particle(double m, double q) {
	this->m = m;
	this->q = q;
}
particle::particle(vec &r, vec &v, double m, double q) {
	this->m = m;
	this->q = q;
	this->r = r;
	this->v = v;
	time = clock();
}
particle::particle(double x, double y, double vx, double vy, double m, double q) {
	this->m = m;
	this->q = q;
	r = { x,y };
	v = { vx,vy };
	time = clock();
}
void particle::SetPos(vec r) {
	this->r = r;
	time = clock();
}
void particle::SetPos(double x, double y) {
	r = { x,y };
	time = clock();
}
void particle::SetVel(vec v) {
	this->v = v;
}
void particle::SetVel(double vx, double vy) {
	v = { vx,vy };
}
vec particle::GetPos() {
	return r;
}
vec particle::GetVel() {
	return v;
}
void particle::dt_move(clock_t dt) {
	time += dt;
	if (time > clock()) {
		while (time > clock());
		r += v * dt / (double)CLOCKS_PER_SEC;
	}
	else {
		r += v * ((clock() - time + dt) / (double)CLOCKS_PER_SEC);
		time = clock();
	}
}
void particle::dt_force(vec force(particle&), clock_t dt) {
	v += force(*this) * (dt / m / (double)CLOCKS_PER_SEC);
}