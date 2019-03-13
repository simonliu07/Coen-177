Simon Liu Lab 4 Tuesday 5:15pm 

##File System Performance##

-Implementation-
I've created two programs: sequential.c & random.c. The sequential.c read in
randomly generated files 1 btye at a time from the start of the file to the end.
We only start calculating the time required when we start reading the file.
The random.c starts the read of each Kb of the file from random locations. 
This should theoredically slow down the performance of the system since we 
might run into locations that we've read already. There is 3 file sizes: 
1 MB, 3 MB & 5 MB size that we created through "base64 /dev/urandom | head -c N > name.txt"
, where N is 1M, 3M or 5M. We test the time spent by both program with these files.

-Tests-

Sequential:

1 MB:
Time	0m0.030s
real	0m0.042s
user	0m0.038s
sys		0m0.003s

3 MB:
Time	0m0.098s
real	0m0.098s
user	0m0.094s
sys		0m0.004s

5 MB:
Time	0m0.130s
real	0m0.138s
user	0m0.133s
sys		0m0.005s


Random:

1 MB:
Time	0m1.160s
real	0m1.169s
user	0m0.251s
sys 	0m0.917s

3 MB:
Time 	0m3.350s
real	0m3.364s
user	0m0.606s
sys		0m2.757s

5 MB:
Time	0m5.530s
real	0m5.540s
user	0m1.057s
sys		0m4.483s

-NOTE-
Time => only represent the time sent reading the data from given file
real => the time spent by the entire program
user => time spent not in the kernel, in user mode
sys  => time spent in the kernel

-Observation-
The sequential program runs faster than the random program as expected. In the 
randfom program, we constantly need to caculate what is the new location we want
to read the byte from, and check whether or not there is anything for us to read.
In sequential, we just keep reading one byte of information, no need to recalculate
new locations to read the data from. We can also see that there is exponential 
increase in time required in the kernel since we have to find what data to access.

-Question: "What is the performance of a specific user workload on file system performance?"-
In this case, we can see how constantly requesting different memory location from a disk may
affect the speed of the program. In the "random.c" program, we ask for a new memory location
for every byte, thus the disk have to constantly move the needle to our specify location. 
From the difference from the time spent on sequence and random, we can see that IO is slow.
If we want to increase the speed of the program, then we need to try and reduce the number 
of system calls we do in a program, thus reducing the amount of IO. 


