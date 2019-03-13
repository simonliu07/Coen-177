Simon Liu COEN 177 Lab 3 Tuesday 5:15

Graph called "Page Faults of FIFO, LRU, Second-Chance"

FIFO
Implementation:	The table that I created is a simple array with a flag called "insert" to indicate which
		memory page is suppose to be replace. Everytime we scan a new page number, we do a for
		loop to check whether the number is stored in the memory table or not. If it is already
		stored, then we set a flag called "found" as one. After the check is done, we see if the
		found flag is set to 1 or 0. If the flag is 0, then that means the page number wasn't in
		the table, then we replace the new page number with the page number at the insert slot.
		I print the new page number to indicate as a new page fault, then increament the insert
		flag to the next array slot.

Test:		To test the program, I compile the program and named it as "fifo". To execute the program,
		I need to include the input file name, size of page table, the name of the output file I 
		want. To execute the code, I ran " cat in.txt|./fifo 100 FIFOOutput.txt ". "in.txt" 
		represent input file, "100" is the size of table and "FIFOOutput.txt" is the output file
		name. After it's executed, I ran "diff FIFOOutput.txt out_fifo.txt" to check with answer
		key. Nothing was outputed, so the code is correct.


LRU
Implementation:	The page replacement program I created uses an array as the page table. I created a 
		function called "shift" to copy everything down a spot to the given location. In the main,
		we create an array of 0 that is the same of given table size. We do a loop until we no 
		longer have anything to scan in scanf. When a new page number comes in, we check if the page
		number is already in the table. If the page is already in the table, we shift everything 
		that is below the page location up a spot and place the number to the 0th spot of the list. 
		If the new page number isn't found in the table, we copy everything in the table up a spot,
		effectively deleting the oldest page number, then we insert the new page table to the 0th
		spot. 

Test:		To test the program, I compile the program and named it as "lru". To execute the program,
		I need to include the input file name, size of page table, the name of the output file I 
		want. To execute the code, I ran "cat in.txt|./lru 100 LRUOutput.txt". "in.txt" represent
		input file, "100" is the size of table and "LRUOutput.txt" is the output file name. After
		it's executed, I ran "diff LRUOutput.txt out_lru.txt" to check with answer key. Nothing was
		outputed, so the code works.


Second-Chance
Implementation:	The Second-Chance program I created uses two arrays, one is the table itself and another is 
		an array to keep track of which array is given a second-chance. When a new pae number is 
		given, we check whether the page number already exist in the table. If it does exist, then
		we set the token value of of same index as 1. If the page number isn't found, then we try 
		to insert the new page at the spot where the "insert" flag is pointing at, like in FIFO. 
		However, we also need to check the token array. If the insert location have a token value of
		1, then set it to 0 and check the next token slot. If the token slot value is 0, then replace
		the current table index location with the new page number and also output into the designated
		file. 

Test:		To test the program, I compile the program and named it as "sc". To execute the program, I 
		need to include the input file name, size of page table, the name of the output file I want.
		To execute the code, I ran "cat in.txt|./sr 100 SROutput.txt". "in.txt" represent input file,
		"100" is the size of the table and "SROutput.txt" is the name of the output file. After it's
		executed, I ran "diff SCOutput.txt out_sc_amartin.txt" to check with answer key. Noting was
		outputed, so the code works. 

Page Fault Comparison:
	All three page replacement programs have a decreasing rate as the size of page table increases. This
	makes sense since we can store more page numbers in the table, so there is a higher chance that we
	can find repeated new numbers. LRU and Second-Chance page fault number decrease at a faster rate,
	since they keep the page number that are used more frequently, so there is less chance of them 
	needing to replace old page numbers. LRU have a consistent decrease of page fault as the size of 
	table increase while Second-Chance fluctuated a few time. LRU also have more "least amount of page
	fault" per table size, so it could be a better implementation than FIFO or Second-Chance. The trend 
	of the three page replacement programs can be seen in the png file called "Page Gaults of FIFO, LRU,
	Second-Chance.png". 
