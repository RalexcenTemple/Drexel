Reed Ceniviva
CS283
H6

CSAPP3 Problem 12.16 
	Write a version of hello.c (Figure 12.13)
	'that creates and'reaps n joinable peer threads, where n is a command-line argument.
	
	File found as "hello.c"
--------------------------------------------------------------------
•CSAPP3 Problem 12.17 
	A. The pro grain in Figure 12.46 has a bug. The 'thread'i~ supposed to sleep for 1 second and then print a string. 
	'However, when we run it on our system, nothing prints:'Why?
		As a result of the exit function, the program terminates before the child thread is able to print and so the parent
			completes and terminates without the child ever printing.

	B. You can fix this bug by replacing the exit functiop in ljpe 10 wi\h on,e of two different Pthreads function calls. Which ones? 
		By switching out the exit() function with pthread_exit() or pthread_join() the program will allow the child thread to continue
			and eventually print before the program exits.
--------------------------------------------------------------------
•Starting with file hello-hw.txt, 
	write a program that uses threads that print a string,their own task id and the value of a variable sum. The task id,
	value of sum and string address must be passed to the string through pthread_create(). Do not change the code in hello-hw.txt but only 
	add statements. Some of the places where new code must be added are shown by /* ... */. 

	code found in file: hello-hw.c
	
---------------------------------------------------------------------
•Startingwith file dotpr-hw.txt, 
	write a program that uses threads to calculate the dot product of two vectors. Do not change the code in dotpr-hw.txtbut
	only add statements. Some of the places where new code must be added are shown by/*... */.
	
	code found in file: dotpr-hw.c