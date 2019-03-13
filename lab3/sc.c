/*	Simon Liu COEN 177 Lab 3 Tuesday 5:15pm
 *
 *	Goal:	Use Second-Chance method to determine page fault in the given page size,
 *		print the page hta faulted into a txt file and compare with answer key
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int size = atoi(argv[1]);
	int table[size];
	int token[size];
	int i, found = 0, number = 0, insert = 0, counter = 0;
	FILE *file = fopen(argv[argc-1], "w");

	for(i = 0; i < size; ++i){				//set everything in the array to 0
		table[i] = 0;
		token[i] = 0;
	}

	while(scanf("%d", &number) == 1){				//keep scanning until there is no input to scan
		for(i = 0; i < size; ++i){				//go and check if the number is already in the table
			if(number == table[i]){				//if we find it, set the token as 1, as accessed
				token[i] = 1;
				found = 1;
				break;
			}
		}
		if(found == 0){						//if the number was never found in the table
			for(i = 0; i < size; ++i){			//find the first table slot where it's token is 0
				if(token[insert] == 0)
					break;
				else{					//if the token is 1, set it to 0 and go next
					token[insert] = 0;		
					insert = (insert+1) % size;
				}
			}
			table[insert] = number;				//set in the number into table
			fprintf(file, "%d\n", number);			//the number into output file
			insert = (insert+1) % size;			//set insert into the next slot
			++counter;
		}
		found = 0 ;
	}
	printf("%d\n", counter);
	return 0;
}			
