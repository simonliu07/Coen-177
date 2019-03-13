/*	Simon Liu COEN 177 Lab 4 5:15pm
 *
 *	Goal: 	Read a given file in random order and see how 
 *		long that took.
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char* argv[]){
	clock_t t;
	char *buffer;
	unsigned long long counter = 0;
	buffer = malloc(sizeof(char));			
	FILE *fp = fopen(argv[1], "r");
	
	fseek(fp, 0, SEEK_END);
	unsigned long long  length = ftell(fp);			//find how long is the file
	srand(time(NULL));	

	t = clock();						//start the timing
	while(counter <= length){
		unsigned long long randomnumber = rand()%(length-1);	//randomize the memory location request
		fseek(fp,randomnumber,SEEK_SET);		//get to that location
		++counter;
		fread(buffer, 1, 1, fp);			//read the data requested
	}
	t = clock() - t;

	double time_taken = ((double)t)/CLOCKS_PER_SEC;		//caculate the time spent reading
	printf("%f\n", time_taken);
	fclose(fp);
	return 0;
}
