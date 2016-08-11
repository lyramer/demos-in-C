// Andy Wynden, V00746343

#include <stdio.h>
#include <stdlib.h>

int GCF(int x, int y) {
  if (x == 0) {return y;}
  return GCF(y%x, x);
}

int reduce(int * x, int * y) {
	int factor, xred, yred;

	factor = GCF(*x,*y);
	xred = *x / factor;
	yred = *y / factor;

	if (xred != *x && yred != *y) { // CHECKS TO SEE IF THERE WAS ANY USEFUL FACTOR
		*x = xred;
		*y = yred;
		return 1;
	} else {return -1;}
}


int main(void) {
	int x, y, factorable = 0;
	setvbuf(stdout, NULL, _IONBF, 0);


	while (1) {
		// READS FRACTIONS AS TWO INTEGERS
		printf("Fraction: ");
		fflush(stdout);
		if (0 == scanf("%d/%d", &x, &y)) {break;}

		factorable = reduce(&x, &y);

		if (factorable == 1) {
			printf("reduced = %d/%d\n", x, y);
		} else {printf("cannot be reduced\n");}
	}


	return EXIT_SUCCESS;
}
