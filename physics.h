#pragma once
#include <ctime>
#include <math.h>

class vec {
private:
	double x, y;
public:
	vec();
	vec(double x, double y);
	
	double GetX();
	double GetY();
	double GetLength();

	vec operator =(vec v);
	vec operator +(vec v);
	vec operator -(vec v);
	vec operator +=(vec v);
	vec operator -=(vec v);
	vec operator *(double c);
	vec operator /(double c);
	vec operator *=(double c);
	vec operator /=(double c);
	double operator *(vec &v);
};

class particle {
	friend vec;
private:
	vec r;
	vec v;
	double m;
	double q;
	clock_t time;
public:
	particle();
	particle(double m, double q);
	particle(vec &r, vec &v, double m, double q);
	particle(double x, double y, double vx, double vy, double m, double q);

	void SetPos(vec r);
	void SetPos(double x, double y);
	void SetVel(vec v);
	void SetVel(double vx, double vy);

	vec GetPos();
	vec GetVel();

	void dt_move(clock_t dt);
	void dt_force(vec force(particle&), clock_t dt);
};