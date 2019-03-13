/*	Simon Liu
 *	COEN 177 Lab 1 Tues 5:15
 *
 *	Description: Task 4 goal is to create 17 processess. The parent process have to create more
 *			than 2 child processes, but no more than 3. This program will create 3 layers
 *			of parent processes, on the 4th layer, only the 3rd layer left most process 
 *			will create 3 child processes.
 *
 *	Test:	gcc -o task4 task4.c
 *		./task4
 *	Result:	There should be 17 children in total. There should be 7 sets of childrens that have the same parent pid.
 *		Another extra 3 children should have the same parent.
 */

#include <stdio.h>
#include <sys/types.h>

int main(void){
	int status;		//initialize variable for waitpid
	int level = 0;		//initial level
	int left = 0;		//initial flag for left most child
	pid_t child1, child2, child3;

	while(level < 3 && (child1 == 0 || child2 == 0)){		//this while loop will create 3 layers of parent process with each parent having 2 child
		child1 = fork();					//creating the first child
		if(child1 == 0){					//in the child
			left = 1;					//set the left most child flag
			printf("Child: %d , Parent: %d\n", getpid(), getppid());	
		}
		else if(child1 > 0){					//if we are in the parent, create the second child
			child2 = fork();
			if(child2 == 0)
				printf("Child: %d , Parent: %d\n", getpid(), getppid());
			else
				waitpid(-1, &status, 0);		//when we are in parent after create second child, wait for the respond form second child
		}
		++level;						//increment the level counter
	}
	if(level == 2 && left == 1){					//if we are done creating 14 childs and we are in the left most child of the last layer
		child1 = fork();					//create 15th child
		if(child1 == 0)
			printf("Child: %d , Parent: %d\n", getpid(), getppid());
		else if(child1 > 0){
			child2 = fork();				//create the 16th child
			if(child2 == 0)
				printf("Child: %d , Parent: %d\n", getpid(), getppid());
			else if(child2 > 0){
				child3 = fork();			//create the 17th child
				if(child3 == 0)
					printf("Child: %d , Parent: %d\n", getpid(), getppid());
				else
					waitpid(-1, &status, 0);
			}
		}
	}
}
