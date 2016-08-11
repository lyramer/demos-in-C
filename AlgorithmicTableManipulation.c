// Andy Wynden, V00746343

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct planetInfo {
	char planetName[12];
	char uselessData[21][60];
	double density;
} planetInfo;


void readPlanets(planetInfo planet[]) {
	int i, j, namelen;

	// reads cities from file
    FILE * planetdata = fopen("/Users/derekja/Documents/Andy/CSC111/V00746343a6p1/planets.txt","r");
    if(planetdata == NULL){printf("ERROR\n"); fclose(planetdata);}

    for (j = 0; j < 21; j++) {
    	for (i = 0; i < 10; i++) {
    		if (j == 0 && i == 0) {strcpy(planet[i].uselessData[j], " ");}
    		else if (j == 3 && i >= 1) {fscanf(planetdata, "%lf", &planet[i].density);}
    		else {fscanf(planetdata, "%s", planet[i].uselessData[j]);}
    	}
    }

    fclose(planetdata);

	// REPLACING UNDERSCORES WITH SPACES
	for(j = 0; j < 21; j++) {
		namelen = strlen(planet[0].uselessData[j]);
		for(i = 0; i < namelen; i++) {
			if (planet[0].uselessData[j][i] == '_') {planet[0].uselessData[j][i] = ' ';}
		}
	}

}

void printPlanets(planetInfo planet[]) {
    int i, j;

    FILE* outFile = NULL; // File pointer

    // Open file
    outFile = fopen("sortedPlanets.csv", "w");

    if (outFile == NULL) {
       printf("Could not open file myoutfile.txt.\n");
    }

    for (j = 0; j < 21; j++) {
    	for (i = 0; i < 10; i++) {
    		if (j == 3 && i >= 1) {fprintf(outFile, "%.lf", planet[i].density);}
    		else {fprintf(outFile, "%s", planet[i].uselessData[j]);}
    		if (i < 9) {fprintf(outFile, ",");}
    	}
    	fprintf(outFile, "\n");
    }
    fclose(outFile);

    for (j = 0; j < 21; j++) {
    	for (i = 0; i < 10; i++) {
    		if (j == 3 && i >= 1) {printf("%28.lf", planet[i].density);}
    		else {printf("%28s", planet[i].uselessData[j]);}
    		//if (i < 9) {printf("");}
    	}
    	printf("\n");
    }
}



void sortPlanets(planetInfo planet[]) {
	int i = 9, j, swap;
	planetInfo tempplanet;

	while (i > 1) {
		swap = 0;
		for (j = 2; j <= i; j++) {
			if (planet[j - 1].density < planet[j].density) {
				swap = j - 1;
				tempplanet = planet[j - 1];
				planet[j - 1] = planet[j];
				planet[j] = tempplanet;
			}
		}
		if (swap == 1)
			break;
		i = swap;
	}
	return;
}


int main(void) {
	int i;
	planetInfo planet[10];


	readPlanets(planet);
	sortPlanets(planet);
	printPlanets(planet);



	return EXIT_SUCCESS;
}
