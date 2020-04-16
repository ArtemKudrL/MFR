#include "graphics.h"

short X(double x) {
	return ORIGIN.X + (int)(SCALE * x);
}
short Y(double y) {
	return ORIGIN.Y - (int)(SCALE * y);
}