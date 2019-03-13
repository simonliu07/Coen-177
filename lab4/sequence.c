/*	Simon Liu COEN 177 Lab 4 5:15pm
 *
 *	Goal: 	Read the given file in sequential order and 
 *		see how long that took.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char* argv[]){
	clock_t t;
	char *buffer;
	FILE *fp = fopen(argv[1], "r");
	buffer = (char*)malloc(sizeof(char));
	
	t = clock();						//start timing the reading
	while(fread(buffer, 1, 1, fp) == 1);			//read data as long as there is stuff to read
	t = clock() - t;

	double time_taken = ((double) t)/CLOCKS_PER_SEC;	//cacluate time spent reading
	printf("Time :%f\n", time_taken);
	fclose(fp);
	return 0;
}
