// Andy Wynden, V00746343

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point_struct {
	double xcoord;
	double ycoord;
} point;

typedef struct circle_struct {
	point origin;
	double radius;
	double area;
} circle;


point readPoint(int * exit_flag_point) {
	point temppoint;
	setvbuf(stdout, NULL, _IONBF, 0);
	fflush(stdout);
	if (0 == scanf("%lf", &temppoint.xcoord)) {
		*exit_flag_point = 1;
	}
	if (0 == scanf("%lf", &temppoint.ycoord)) {
		*exit_flag_point = 1;
	}

	return temppoint;
}

circle readCircle(int * exit_flag) {
	const double pi = acos(-1);
	int exit_flag_point = 0;
	circle temp_circ;
	temp_circ.origin = readPoint(&exit_flag_point);
	fflush(stdout);
	scanf("%lf", &temp_circ.radius);
	*exit_flag = exit_flag_point;
	temp_circ.area = pi * pow(temp_circ.radius, 2);
	return temp_circ;
}

double findDistance(point pointA) {
	double distance = 0.0;

	distance = sqrt(pow(0 - pointA.xcoord, 2) + pow(0 - pointA.ycoord, 2));

	return distance;
}

void circleSort(circle circ[], int numCircles) {
	// Adapted from a class example.
	int i, j, swap;
	circle temp_circ;
	i = numCircles - 1;

	while (i > 0) {
		swap = 0;
		for (j = 1; j <= i; j++) {
			if (circ[j - 1].radius > circ[j].radius) {
				swap = j - 1;
				temp_circ = circ[j - 1];
				circ[j - 1] = circ[j];
				circ[j] = temp_circ;
			} else if (circ[j - 1].radius == circ[j].radius && findDistance(circ[j - 1].origin) > findDistance(circ[j].origin))  {
				swap = j - 1;
				temp_circ = circ[j - 1];
				circ[j - 1] = circ[j];
				circ[j] = temp_circ;
			}
		}
		if (swap == 0)
			break;
		i = swap;
	}
	return;
}


void circlePrint(circle temp_circ) {
	printf("c = (%.4lf, %.4lf)  r = %.4lf  a = %.4lf\n", temp_circ.origin.xcoord, temp_circ.origin.ycoord, temp_circ.radius, temp_circ.area);
}
int main(void) {
	circle circ[100];
	int exit_flag = 0, i = 0, numCircles;
	while(1) {

		circ[i] = readCircle(&exit_flag);

		if (exit_flag == 1) {
			numCircles = i;
			break;
		}
		i++;

	}

	circleSort(circ, numCircles);

	for (i = 0; i < numCircles; i++) {
		circlePrint(circ[i]);
	}


	return EXIT_SUCCESS;
}
