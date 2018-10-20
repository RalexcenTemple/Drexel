int print_str (char *str);
int __main ();
int dummy(int v);
int setjmp(int v);
int longjmp(int v);
int fun1();
int fun2();
/* I grabbed a lot of code from other files weve been giving */
/* in this class just to cut down on how much I had to typed */

/* need these to be global so that we can still reach them outside the scope */
/* of the setjmp function and the longjmp function */
/* refference experiement 3 in files folder of the course */
static int *RA;
static int *FP;


main ()
	{
	int r;
	
	r= setjmp(r);
	if(r == 0){
		fun1();
		return(0);
		
	}else{
		print_str("error\n");
		return(2);
		}
	}
	
__main ()
	{
  return(0);
	}

dummy (v)
int v;
	{
  return(0);
	}
	
	 
setjmp(v)
int v;
	{
		/* gets the lovation of the variable passed and assignes */
		/* the return address and frame pointer based off that */
		/* uses the dumby to complete the frame */
		/* makes use of global perameters to store addresses */
		int *add; 
		add = &v;
		RA = (add - 1);
		FP = (add - 2);
		dummy (v);
		return(0);
	}
	
longjmp(v)
int v;
	{
		/* uses the same concept as setjmp to retrieve */
		/* and assign address locations */
		int *add;
		add = &v;
		*(add - 1) = *(RA - 8);
		*(add - 2) = *(FP);
		dummy (v);
		return(1);
	}
	
fun1()
	{
		print_str("start fun1\n");
		fun2();
		return(0);
	}
	
fun2()
	{	
		int d;
		print_str("start fun2\n");
		longjmp(d);
		return(0);
	}
	
print_str (str)
char *str;
	{
		int code;
		code = 4;
		asm (
			"add $a0,%1,$zero\n\t"
			"add $v0,%0,$zero\n\t"
			"syscall"
       :
       : "r" (code), "r" (str));
		return(0);
	}