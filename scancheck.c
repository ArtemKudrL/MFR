#include "scancheck.h"

void scan_nat(unsigned int *x) {
	char in, buf[3 * sizeof(x) + 1];
	int i, res, size = abs(12 * sizeof(x) / 5);

	do {
		in = getchar();
		i = 0;
		res = 0;

		while (in != '\n') {

			if (res == 0) {
				if ((in >= '0' && in <= '9') && i < size)
				{
					buf[i] = in;
				}
				else if (i == size) res = 2;
				else res = 1;

			}

			in = getchar();
			i++;
		}
		if (i == 0) res = 3;

		switch (res) {
		case 1:
			printf_s("Input isn't a natural number. \n");
			break;
		case 2:
			printf_s("Too long number. \n");
			break;
		case 3:
			printf_s("You entered nohihng. \n");
			break;
		}

	} while (res != 0);

	buf[i] = 0;
	*x = atoi(buf);
}
void scan_int(int *x) {
	char in, buf[3 * sizeof(x) + 1];
	int i, res, size = abs(12 * sizeof(x) / 5);

	do {
		in = getchar();
		i = 0;
		res = 0;

		while (in != '\n') {

			if (res == 0) {
				if ((
					(in >= '0' && in <= '9') ||
					(in == '-' && i == 0)) && i < size)
				{
					buf[i] = in;
				}
				else if (i == size) res = 2;
				else res = 1;

			}

			in = getchar();
			i++;
		}
		if (i == 0) res = 3;

		switch (res) {
		case 1:
			printf_s("Input isn't a integer number. \n");
			break;
		case 2:
			printf_s("Too long number. \n");
			break;
		case 3:
			printf_s("You entered nohihng. \n");
			break;
		}

	} while (res != 0);

	buf[i] = 0;
	*x = atoi(buf);
}
void scan_real(double *x) {
	char in, buf[3 * sizeof(x) + 1];
	int i, res, size = abs(12 * sizeof(x) / 5), dot_counter;

	do {
		in = getchar();
		i = 0;
		res = 0;
		dot_counter = 0;

		while (in != '\n') {

			if (res == 0) {
				if ((
					(in >= '0' && in <= '9') ||
					(in == '-' && i == 0) ||
					(in == '.' && dot_counter == 0)) && i < size)
				{
					buf[i] = in;
					if (in == '.') dot_counter++;
				}
				else if (i == size) res = 2;
				else res = 1;

			}

			in = getchar();
			i++;
		}
		if (i == 0) res = 3;

		switch (res) {
		case 1:
			printf_s("Input isn't a real number. \n");
			break;
		case 2:
			printf_s("Too long number. \n");
			break;
		case 3:
			printf_s("You entered nohihng. \n");
			break;
		}

	} while (res != 0);

	buf[i] = 0;
	*x = atof(buf);
}
void scan_nat_cond(int *x, int(*cond)(char)) {
	char in, buf[3 * sizeof(x) + 1];
	int i, res, size = abs(12 * sizeof(x) / 5);

	do {
		in = getchar();
		i = 0;
		res = 0;

		while (in != '\n') {

			if (res == 0) {
				if ((in >= '0' && in <= '9') && cond(in) && i < size)
				{
					buf[i] = in;
				}
				else if (i == size) res = 2;
				else res = 1;

			}

			in = getchar();
			i++;
		}
		if (i == 0) res = 3;

		switch (res) {
		case 1:
			printf_s("Wrong input. \n");
			break;
		case 2:
			printf_s("Too long number. \n");
			break;
		case 3:
			printf_s("You entered nohihng. \n");
			break;
		}

	} while (res != 0);

	buf[i] = 0;
	*x = atoi(buf);
}
void scan_int_cond(int *x, int(*cond)(char)) {
	char in, buf[3 * sizeof(x) + 1];
	int i, res, size = abs(12 * sizeof(x) / 5);

	do {
		in = getchar();
		i = 0;
		res = 0;

		while (in != '\n') {

			if (res == 0) {
				if ((
					(in >= '0' && in <= '9') ||
					(in == '-' && i == 0)) && cond(in) && i < size)
				{
					buf[i] = in;
				}
				else if (i == size) res = 2;
				else res = 1;

			}

			in = getchar();
			i++;
		}
		if (i == 0) res = 3;

		switch (res) {
		case 1:
			printf_s("Wrong input. \n");
			break;
		case 2:
			printf_s("Too long number. \n");
			break;
		case 3:
			printf_s("You entered nohihng. \n");
			break;
		}

	} while (res != 0);

	buf[i] = 0;
	*x = atoi(buf);
}
void scan_real_cond(double *x, int(*cond)(char)) {
	char in, buf[3 * sizeof(x) + 1];
	int i, res, size = abs(12 * sizeof(x) / 5), dot_counter;

	do {
		in = getchar();
		i = 0;
		res = 0;
		dot_counter = 0;

		while (in != '\n') {

			if (res == 0) {
				if ((
					(in >= '0' && in <= '9') ||
					(in == '-' && i == 0) ||
					(in == '.' && dot_counter == 0)) && cond(in) && i < size)
				{
					buf[i] = in;
					if (in == '.') dot_counter++;
				}
				else if (i == size) res = 2;
				else res = 1;

			}

			in = getchar();
			i++;
		}
		if (i == 0) res = 3;

		switch (res) {
		case 1:
			printf_s("Wrong input. \n");
			break;
		case 2:
			printf_s("Too long number. \n");
			break;
		case 3:
			printf_s("You entered nohihng. \n");
			break;
		}

	} while (res != 0);

	buf[i] = 0;
	*x = atof(buf);
}