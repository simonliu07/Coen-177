/*	Simon Liu 
 *	COEN 177 Lab 1 Tues 5:15
 *
 *	Description: The goal of Basic taks is to create a simple shell program that will
 *			run designated program that outputs "Hello World" as long as there
 *			is user input. When user input a "exit" key word, the program will stop.
 *
 *	Test: 	Execute program called task1.c that outputs "Hello World"
 *		gcc -o basic basic.c
 *		./basic
 *	Result:	The program outputs "Hello World" whenever there is a user input. The cycle
 *		continues until "Esc" is input. 
 */
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

int main(void){
	char input[20];				//create a string for user input
	char end[] = "Esc";			//exit program key word
	int status;				//variable for waitpid()
	while(1){
		scanf("%s", &input);		//wait for user input
		if(strcmp(input,end) == 0)	//if user input the key word, exit program
			return 0;
		pid_t pid = fork();		//create child process
		if(pid != 0)			//if we are in the parent process, wait for child
			waitpid( -1, &status,0);
		else				//if we are in child process, execute designated program
			execve("task1", NULL, NULL);
	}
}
