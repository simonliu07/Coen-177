Coen 177 Lab 2 Tues 5:15pm
Simon Liu 

Minix Scheduling

First Task:
	Goal: 	The goal of this task to to print out a line of "custom message" when the OS
		started up.
	
	Method: Found "MINIX startup banner" in the "announce" section of main.c. Added the 
		line "printf("Simon was here\n") after the line "printf("MINIX is open
		source software, see http://www.minix3.org\n") so the custom message will 
		printed. 
	
	Result: After compiling the OS with "make world" and rebooting the system, the line 
		"Simon was here" appeared right after the line "MINIX is open source software
		, see http://www.minix3.org.

The Assignment:
	Goal: 	The original scheduling algorithm for Minix startup is a priority round 
		robin. It picks the processes according to their importance. The goal of
		this assignment is to change the order of picking the processe.Randomize 
		the startup of the OS, so that some lower priority processes can be start 
		before higher priority processes

	Method: To change the picking process, I've modify the code of "pick_proc" in proc.c.
		The original code pick the process in a priority queue that was made when 
		the processes enter. To make the startup more "random", I've alter the way
		of picking the processes after all the critial proccess are done. I did 
		"q>=7" because the first 7 processes are required for the OS to startup, if
		I didn't run the first 7 processes, the OS wouldn't even start, thus causing
		a freeze during startup. "q = (rand()%(NR_SCHED_QUEUES-7))+7" ensures that 
		after the 7th picking, we will start randomizing the process within the range
		of 7~NR_SCHED_QUEUES. 

	Result:	To test the code, we build the world with "make world" in /usr/src. After 
		compiling the new code, reboot. The result is a significantly slower startup
		of the OS since it takes time to through the list randomly to pick all the 
		processes we need to start the program. 

Questions:

	How many queues are there?
		The number of queues are define in NR_SCHED_QUEUES, which is 16
	Which queue is the highest priority? The lowest?
		The first one have the highest priority and the alst one in the queue have the 
		lowest
	What C expression gives the first ready process in a queue?
		rp = rdy_head[q]
	Describe the behavior of your changes:
		1. Which queues are affected?
			The queues after the 6th process are alter with random order
		2. What is the probability that randomization takes palce?
			Randomiztion will take place after the 6th process with a 5% chance the 
			randomization will acutally happen
		3. What parameter is being randomized?
			The indices of which process to pick from the queue will be randomize, q
		4. What difference did you observe?
			The OS took longer to start up and the second compile took around 8 min
		5. What happens if that queue doesn't have a ready process?
			It should print out "Queue %d empty" and restart the picking process
