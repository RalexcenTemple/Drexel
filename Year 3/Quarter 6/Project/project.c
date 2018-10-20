#include <stdio.h>
#include <stdlib.h>

int foo(void);
int bar(void);
int fun1();
int fun2();
int *add;
int setjmp(int arg);
int longjmp(int arg);

int main (void){
	int r;
	
	r= setjmp(r);
	if(r == 0){
		fun1();
		return(0);
		
	}else{
		printf("error\n");
		return(2);
		}
	}
	
int _main(void) {
    return(0);
}
	
	//giving properties to jmpbuf
struct jmpbuf {
    int lr;
    int fp;
    int *sp;
};
	//to access jmpbuf
static struct jmpbuf ctx;
	
	//saves lr when called
static void lrs(void){	}
	
int setjmp(int arg)
	{
		// save lr 
	lrs();

		// since the address should be above lr and fp 
		// we save sp first
	ctx.sp = &arg;

		// then using the position of sp we offset the location of lr from that so it is below
	ctx.lr = (&arg)[-1];

		// then using the position of sp we offset the location of fp so that
		// it is bellow lr
	ctx.fp = (&arg)[-2];
		
		return(0);
}
	
	//saves lr to new l;ocation
static void lrsfptosp(int arg){
		//needed to change the frame pointer and overwrite it
	(&arg)[-1] = (int)ctx.sp;
}
	
int longjmp(int arg)
	{
		// call the fptosp to change to frame pointer to the stack pointer
		// fptosp also does the job of saving lr 
		lrsfptosp(arg);

		// restores the new stack frame with the saved lr and fp
		// $arg is found via fp
		// since the position of arg has changed as a result of lrsfptosp
		(&arg)[-1] = ctx.lr;
		(&arg)[-2] = ctx.fp;

		// restores fp and lr
		// to appear that we've returned to the program
	return(1);
}
	
int fun1()
	{
		//debug perposes 
		printf("start fun1\n");
		
		fun2();
		return(0);
}
	
int fun2()
	{	
		int d;
		//debug perposes 
		printf("start fun2\n");
		longjmp(d);
		return(0);
}