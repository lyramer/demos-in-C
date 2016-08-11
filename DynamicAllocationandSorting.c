// Andy Wynden, V00746343

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point_struct {
	double xcoord;
	double ycoord;
} point;

// NOTE THAT CODE FOR LINKED LIST IS ADAPTED FROM CLASS EXAMPLE, BY MICHAEL MILLER
typedef struct circle_struct *nodePtr;

typedef struct circle_struct {
	point origin;
	double radius;
	double area;
	nodePtr next;
} circle;


double findDistance(point pointA) {
	double distance = 0.0;

	distance = sqrt(pow(0 - pointA.xcoord, 2) + pow(0 - pointA.ycoord, 2));

	return distance;
}

nodePtr readCircle() {
	const double pi = acos(-1);
	nodePtr listp, lastp, newp, p;
	double xinput,yinput, radinput;
	listp = NULL;
	setvbuf(stdout, NULL, _IONBF, 0);

	while(1){
		// check x,y pair read
		fflush(stdout);
		if(2 > scanf("%lf%lf%lf",&xinput,&yinput,&radinput)) break;

		// create new node with x,y read
		newp = (nodePtr)malloc(sizeof(circle));
		newp->origin.xcoord = xinput;
		newp->origin.ycoord = yinput;
		newp->radius = radinput;
		newp->area = pi * pow(newp->radius, 2);


		// insert into linked list
		p = listp;
		while(1){
			if(p == NULL || p->radius > newp->radius || (p->radius == newp->radius && findDistance(p->origin) > findDistance(newp->origin)))
			{
				// do insertion
				newp->next = p;
				if(p == listp) {listp = newp;} // first is special case
				else {lastp->next = newp;}
				break;
			}
			// go to next list node
			lastp = p;
			p = p->next;
		}
	}
	return listp;
}


void circlePrint(nodePtr p){
	while(p != NULL){
		printf("c = (%8.4lf, %8.4lf)  r = %8.4lf  a = %9.4lf",p->origin.xcoord,p->origin.ycoord, p->radius, p->area);
		p = p->next;
		printf("\n");
	}
	printf("\n");
}

int main(void) {

	nodePtr listp;
    listp = readCircle();
    circlePrint(listp);


	return EXIT_SUCCESS;
}
