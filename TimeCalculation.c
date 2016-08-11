// Andy Wynden, V00746343

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



void sanitizeInput(char inputString[], int type_flag) { // REPLACES SPACES OR SLASHES WITH HYPHENS
	int k, inputLength;
	inputLength = strlen(inputString);

	for(k = 0; k < inputLength; k++) {
		if ((inputString[k] == ' ' || inputString[k] == '/') && type_flag == 1) {inputString[k] = '-';}
		else if ((inputString[k] == ' ' || inputString[k] == '/') && type_flag == 2) {inputString[k] = ':';}
	}
}


struct tm readBirthday() { // PARSES LINE INTO INTS THEN CONVERTS TO UNIX TIME AND RETURNS A TM STRUCT.

	struct tm birthdayt;
	char inputString[100];
	int yr_birth, mon_birth, date_birth, hr_birth, min_birth, sec_birth;

	yr_birth = mon_birth = date_birth = hr_birth = min_birth = sec_birth = 0;

	printf("Enter your birthdate (yyyy-mm-dd): ");
	setvbuf(stdout, NULL, _IONBF, 0);
	fflush(stdout);
	fgets(inputString, 100, stdin);

	sanitizeInput(inputString, 1);

	sscanf(inputString, "%d-%d-%d", &yr_birth, &mon_birth, &date_birth);

	birthdayt.tm_year = yr_birth - 1900;  // CONVERTS GIVEN DATE INTO UNIX TIME
	birthdayt.tm_mon = mon_birth - 1;
	birthdayt.tm_mday = date_birth;


	printf("Enter the time of your birth (hh:mm:ss), -1 otherwise: ");
	fgets(inputString, 100, stdin);
	sanitizeInput(inputString, 2);
	sscanf(inputString, "%d:%d:%d", &hr_birth, &min_birth, &sec_birth);

	if (min_birth == -1) {min_birth = sec_birth = 0;}
	if (hr_birth == -1) {hr_birth = min_birth = sec_birth = 0;}

	birthdayt.tm_hour = hr_birth;
	birthdayt.tm_min = min_birth;
	birthdayt.tm_sec = sec_birth;

	return birthdayt;
}

void printTime (struct tm presentt, struct tm birthdayt) {
	struct tm * temptime;
	char timeStr[80];

	temptime = &presentt;
	strftime(timeStr,80,"%Y-%m-%d %H:%M:%S", temptime);
//	printf("The current time is: %s\n", timeStr);

	temptime = &birthdayt;
	strftime(timeStr,80,"%Y-%m-%d %H:%M:%S", temptime);
	printf("Your birthdate is: %s\n", timeStr);
}

void calcTimeAlive(struct tm birthdayt, time_t t) {
	int i, leap;
	double diff_t, count = 0.0;
	int secs_alive, mins_alive, hrs_alive, days_alive, yrs_alive;
	secs_alive = mins_alive = hrs_alive = days_alive = yrs_alive = 0.0;

	time_t mktime(struct tm *birthdayt);

	// fix below
	char timeStr[80];
	struct tm presentt;
	struct tm * temptime;
	presentt.tm_hour = 20;
	presentt.tm_min = 23;
	presentt.tm_sec = 50;
	presentt.tm_mday = 14;
	presentt.tm_mon = 2;
	presentt.tm_year = (2016-1900);

	temptime = &presentt;
	strftime(timeStr,80,"%Y-%m-%d %H:%M:%S", temptime);
	printf("The current time is: %s\n", timeStr);

	diff_t = difftime(t, mktime(&birthdayt));

	secs_alive = diff_t;
	mins_alive = secs_alive / 60;
	hrs_alive = mins_alive / 60;
	days_alive = (hrs_alive / 24);
	yrs_alive = (days_alive / 365);

	printf("Your age is: \n\t");
	printf("%d seconds \n\t", secs_alive);
	printf("%d minutes \n\t", mins_alive);
	printf("%d hours \n\t", hrs_alive);
	printf("%d days \n\t", days_alive);
	printf("%d years \n\t", yrs_alive);
}

int main(void) {
	time_t t;
    time(&t);
	struct tm presentt = *localtime(&t);
	struct tm birthdayt = *localtime(&t);

	birthdayt = readBirthday();
	printTime(presentt, birthdayt);
	calcTimeAlive(birthdayt, t);


	return EXIT_SUCCESS;
}
