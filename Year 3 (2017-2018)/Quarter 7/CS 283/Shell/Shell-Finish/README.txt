Reed Ceniviva
Final Shell project
CS283
3/11/2018

This program is meant as a linux shell that can manage processes and execute system commands within linux with the given specifications:

Your tsh shell should have the following features:!The prompt should be the string ``tsh> ''.!The command line typed by the user should 
consist of a name and zero or more arguments, all separated by one or more spaces. If name is a built-in command,then tsh should handle it 
immediately and wait for the next command line.Otherwise, tsh should assume that name is the path of an executable file, which it loads 
and runs in the context of an initial child process (In this context, the term job refers to this initial child process).!tsh shall 
support pipes (|) and I/O redirection (< and >). Only a single pipe must be tested (a < foo | b > bar).!Typing ctrl-c (ctrl-z) should 
cause a SIGINT(SIGTSTP) signal to be sent to the current foreground job, as well as any descendents of that job (e.g., any child processes 
that it forked). If there is no foreground job, then the signal should have no effect.!If the command line ends with an ampersand &, 
then tsh should run the job in the back ground. Otherwise, it should run the job in the foreground.!Each job can be identified bye ither 
a process ID (PID) or a job ID (JID), which is a positive integer assigned by tsh. JIDs should be denoted on the command line by the 
prefix'%'. For example, ``%5'' denotes JID 5, and ``5'' denotes PID 5. (We have provided you with all of the routines you need for 
manipulating the job list.)!tsh should support the following built-in commands:"The quit command terminates the shell."The jobs 
command lists all background jobs."The bg<job> command restarts <job> by sending it a SIGCONTsignal, and then runs it in the background. 
The <job> argument can be either a PID ora JID."The fg<job> command restarts <job> by sending it a SIGCONTsignal, and then runs it in 
the foreground. The <job> argument can be either a PID or aJID.18:16:50 1/27/18 C:\USR\TC\CLASSES\CS283\CKNOTES\HOMEWORK\PROJECT2\P1-Writing 
Your Own Unix Shell.wpd 3/6
!tsh should reap all of its zombie children. If any job terminates because it receives a signal that it didn't catch, then tsh should recognize this 
event and print a message with the job's PID and a description of the offending signal.