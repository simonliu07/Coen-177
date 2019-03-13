/*	Simon Liu COEN 177 Lab Tuesday 5:15pm
 *	LRU
 *
 *	Goal: In a given size table, we replace the least recent process with the new process
 *	      that isn't found in the table. If we need to insert a new number into the table
 *	      that means that that number created a page fault, which will be recorded into a
 *	      file.
 */
#include <stdio.h>
#include <stdlib.h>

/*Description:	This function is incharge of shifting the entire table when a process is 
 * 		being access. It will save a copy of the number thats being access, then
 * 		it'll shift everything down and copy the number back into spot 0.
 */
void shift(int *t, int loc){
	int i;
	int temp = t[loc];
	for(i=loc ;i > 0;--i)
		t[i] = t[i-1];
	t[0] = temp;
}

int main(int argc, char *argv[]){
	int size = atoi(argv[1]);
	int table[size];
	int i;
	int found = 0;
	int counter = 0;
	int number = 0;
	FILE *file = fopen(argv[argc-1], "w");		//open the given file name to write

	for(i = 0;i < size; ++i)
		table[i] = 0; 

	while(scanf("%d", &number) ==1){		//keep traversing until there is nothing to scan
		for(i = 0; i < size; ++i){		//search through the table
			if(number == table[i]){		//if there is a similar one, bring it to spot 0
				found =1;		
				shift(table, i);
			}
		}
		if(found == 0){				//if the number wasn't found in the table, insert to spot 0
			shift(table, size);
			table[0] = number;
			fprintf(file, "%d\n", number);	//print this page fault
			++counter;
		}
		found = 0;
	}
	printf("%d\n", counter);
	return 0;
}							
