#pragma once
#include <stdio.h>

void scan_nat(unsigned int *x);
void scan_int(int *x);
void scan_real(double *x);
void scan_nat_cond(int *x, int(*cond)(char));
void scan_int_cond(int *x, int(*cond)(char));
void scan_real_cond(double *x, int(*cond)(char));