/*	Simon Liu 
 *	COEN 177 Lab 1 Tues 5:15 Task 2	
 */
/*	Description: This program will create exactly 8 processes
 *		     but no parent processes can create more than two child processes
 *	Test: 	gcc -o task2 task2.c
 *		./task2
 *	Result:	There should be a total of 8 processes. The first child create will be
 *		the parent of the second child, etc. The result should be a linear line
 *		from the first child to the 8th child. 
 */
#include <stdio.h>		//standard library 
#include <sys/types.h>		//library for fork()
#include <unistd.h>		//library for getpid()

int main(void){
	pid_t child1;
	int status;	
	int pid = 0;	//flag to see if the processes became a parent
	int counter= 0;	//this counter keeps a record of how many processes were created

	while(counter <8 && pid == 0){	//stop when there is already 8 procceses or its a parent 
		child1 = fork();	//get the result of fork()
		++counter;		
		if(child1 == 0)	//if we are in the parent, do the following 
			printf("Child:%d , Parent: %d\n", getpid(),getppid());	//display the pid id of the processes
		else if(child1 >0){
			pid =1;
			waitpid(-1, &status, 0);
		}
	}

}
