/*	Simon Liu Coen 177 Lab Tuesday 5:15pm
 *	FIFO
 *
 *	Goal: Use FIFO method to determine page fault in the given page size,
 *	      print the page that faulted into a txt file and compare with 
 *	      answer key
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int size = atoi(argv[1]);			//set the page size from given argument. From string to int
	int table[size];				//create the table
	int number, i;
	int counter = 0;
	int insert = 0;
	int found = 0;
	FILE *file = fopen(argv[argc-1], "w");		//open the file to write the page faults on
	
	for(i = 0; i < size; ++i)
		table[i] = 0;
	while(scanf("%d", &number) == 1){		//key scanning until there is nothing to scan
		for(i = 0; i < size; ++i){		//check with the intergers in the table
			if(number == table[i]){		//if there is a same integer, its not a page fault
				found = 1;
				break;
			}
		}
		if(found == 0){				//if the number isn't found in the table, its a page fault
			table[insert] = number;		//replace current number with the oldest number in the table
			fprintf(file, "%d\n", number);	//print the page fault into the given output txt
			insert = (insert+1)% size;
			++counter;
		}
		found = 0;
	}
	printf("%d\n", counter);
	return 0;
}				
