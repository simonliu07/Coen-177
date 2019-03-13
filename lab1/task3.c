/*	Simon Liu 
 *	COEN 177 Lab 1 Tues 5:15
 *
 *	Description: Task 3 is to create a total of 12 processes but no parent can have less
 *			than 2 child, but no more than 3. THe program prints out the pid of
 *			child and its parent. The program should create 3 child for each 
 *			parent and there should be two sets of parents. 
 *	Test:	gcc -o task3 task3.c
 *		./task3
 *	Result:	There should be a total of 12 child. Each parent process have 3 child
 *		processes. There should be a total of three parent processes, not 
 *		counting the initial process.
 */

#include <stdio.h>
#include <sys/types.h>

int main(void){
	int status;	
	int level = 0;	//initialize level value
	pid_t child1, child2, child3;	//initialize three value for fork()

	while(level < 2 && (child1 == 0 || child2 == 0 || child3 == 0)){		//continue the process if there is 2 levels of parents and there isn't 3 children
		child1 = fork();							//create the first child
		if(child1 == 0)								//if we are in the first child, print the statement
			printf("Child: %d , Parent: %d\n", getpid(), getppid());
		else if(child1 > 0){							//if we are in the parent process
			child2 = fork();						//create the second child
			if(child2 == 0)							//if we are in the second child, print the statement
				printf("Child: %d , Parent: %d\n", getpid(), getppid());
			else if(child2 > 0){						//if we are in the parent process 
				child3 = fork();					//create the third process
				if(child3 == 0){					//if we are in the third child, print the statement 
				printf("Child; %d , Parent: %d\n", getpid(), getppid());
				}	
				else
					waitpid(-1, &status, 0);			//even after the thrid child we are in parent, just wait
			}
		}
		++level;								//when everything is done on this level, increment
	}
}
