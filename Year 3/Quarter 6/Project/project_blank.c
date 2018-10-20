jmp_buf buf;

int setjmp(int v), longjmp(int v), fun1(), fun2();

int main (){
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
	
	int setjmp(int v)
	{
		//put shit here
		return(0);
	}
	
	int longjmp(int v)
	{
		//put shit here
		return(0);
	}
	
	int fun1()
	{
		print_str("start fun1\n");
		fun2();
		return(0);
	}
	
	int fun2()
	{	
		int d;
		print_str("start fun2\n");
		
		longjmp(d);
		return(0);
	}