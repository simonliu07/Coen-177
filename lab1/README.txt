Simon Liu Lab 1 Documentation

Basic.c 
	Wait for the user input, if the user input is "Esc" exit the program. If
	its not the specific input, fork and run the execution called "task1".

task2.c
	In the while loop, keep track how many child we still need to create and
	whether the parent is created. If both statement is true, create a child.
	If we are in the child, print out the statement, and continue the while
	loop. If we are in the parent, flag the process as parent, and wait. The
	result should be a line of processes. 

task3.c
	The while loop checks if we are within 2 levels and if all child required
	are created. When both statement works create child, if we are in the child
	print the statement. If we are the in parent, create another child and 
	print the statement if we are in the second child. Create the third child
	when we are in the parent and print the statement. Increment the level 
	counter to indicate we are done with first level. Continue the steps for
	level two. The resulting structure should have 3 parent after the main,
	then for each parent they should have 3 children.

task4.c 
	The first while creates 3 levels of process with each parent having 2 
	child. The logic behind the first while is the same with task3.c, but
	in this case there is 3 elvels and only two child to check. In this 
	while loop, there is a flag and dicates 1 for the left most child. After
	the first loop is done, there is a while loop to check that if we are at
	the last level and the child have the flag 1, run the loop. In the loop,
	its the same as task3.c except we only run this code once to create the 
	remaining 3 children. 
